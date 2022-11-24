#include "include/Worker.h"

void Worker::registerProcessor(std::weak_ptr<IProcessor> processor) {
  mIProcessors.push_back(processor);
}

void Worker::putData(Data &&data) {
  {
    std::unique_lock lock(mMtx);
    mQueue.push(std::move(data));
  }
  mCv.notify_one();
}

void Worker::run() {
  std::cout << "Worker run()" << std::endl;

  mSelf = std::thread(&Worker::processData, shared_from_this());
}

void Worker::stop() {
  {
    std::unique_lock lck(mMtx);
    mStopFlag = true;
  }
  mCv.notify_one();
  mSelf.join();
}

void Worker::processData() {
  while (1) {
    std::unique_lock lck(mMtx);
    mCv.wait(lck, [&] { return (!mQueue.empty() || mStopFlag == true); });

    if (!mQueue.empty()) {
      Data data = std::move(mQueue.front());
      mQueue.pop();

      for (const auto &processor : mIProcessors) {
        auto spProcessor = processor.lock();
        if (spProcessor != nullptr) {
          spProcessor->process(data);
        }
      }
    }

    if (mStopFlag) {
      std::cout << "Worker processData() mStopFlag:" << std::boolalpha
                << mStopFlag << std::endl;
      break;
    }
  }
  std::cout << "Worker processData() finished" << std::endl;
}
