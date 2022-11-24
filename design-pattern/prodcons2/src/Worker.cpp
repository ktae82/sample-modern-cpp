#include "include/Worker.h"
#include <chrono>

void Worker::registerConsumer(std::weak_ptr<IConsumer> consumer) {
  mwpIConsumer = consumer;
}

void Worker::registerProducer(std::weak_ptr<IProducer> producer) {
  mwpIProducer = producer;
}

void Worker::putData(Data &&data) {
  {
    std::unique_lock lock(mMtxConsumer);
    mQueue.push(std::move(data));
  }
  mCv.notify_one();
}

void Worker::run() {
  std::cout << "Worker::" << __FUNCTION__ << "()" << std::endl;
  {
    std::scoped_lock lck{mMtxConsumer, mMtxProducer};
    mStopConsumer = false;
    mStopProducer = false;
  }

  mProducerThread = std::thread(&Worker::producerThread, shared_from_this());
  mConsumerThread = std::thread(&Worker::consumerThread, shared_from_this());
}

void Worker::stop() {
  std::cout << "Worker::" << __FUNCTION__ << "()" << std::endl;
  {
    std::scoped_lock lck{mMtxConsumer, mMtxProducer};
    mStopConsumer = true;
    mStopProducer = true;
  }

  mCv.notify_one();
  mConsumerThread.join();
  mProducerThread.join();
}

void Worker::producerThread() {
  std::cout << "Worker::" << __FUNCTION__ << "() start" << std::endl;

  auto spProducer = mwpIProducer.lock();
  if (spProducer != nullptr) {
    spProducer->start();

    while (1) {
      std::unique_lock lck(mMtxProducer);

      Data data;
      spProducer->produceData(data);
      this->putData(std::move(data));

      if (mStopProducer) {
        std::cout << "Worker mStopProducer:" << std::boolalpha << mStopProducer
                  << std::endl;
        break;
      }

      using namespace std::chrono_literals;
      std::this_thread::sleep_for(10ms);
    }

    spProducer->finish();
  }

  std::cout << "Worker::" << __FUNCTION__ << "() finished" << std::endl;
}

void Worker::consumerThread() {
  std::cout << "Worker::" << __FUNCTION__ << "() start" << std::endl;

  auto spConsumer = mwpIConsumer.lock();
  if (spConsumer != nullptr) {
    spConsumer->start();

    while (1) {
      std::unique_lock lck(mMtxConsumer);
      mCv.wait(lck, [&] { return (!mQueue.empty() || mStopConsumer); });

      if (!mQueue.empty()) {
        Data data = std::move(mQueue.front());
        mQueue.pop();

        spConsumer->processData(data);
      }

      if (mStopConsumer) {
        std::cout << "Worker mStopConsumer:" << std::boolalpha << mStopConsumer
                  << std::endl;
        break;
      }
    }

    spConsumer->finish();
  }

  std::cout << "Worker::" << __FUNCTION__ << "() finished" << std::endl;
}
