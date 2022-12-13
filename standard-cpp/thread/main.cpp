#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

using Data = std::string;

class Worker : public std::enable_shared_from_this<Worker> {
public:
  void putData(Data &&data) {
    {
      std::unique_lock lock(mMtx);
      mQueue.push(std::move(data));
    }
    mCv.notify_one();
  }

  void run() {
    std::cout << "Worker run()" << std::endl;

    mSelf = std::thread(&Worker::workThread, shared_from_this());
  }

  void stop() {
    {
      std::unique_lock lck(mMtx);
      mStopFlag = true;
    }
    mCv.notify_one();
    mSelf.join();
  }

private:
  void workThread() {
    while (1) {
      std::unique_lock lck(mMtx);
      mCv.wait(lck, [&] { return (!mQueue.empty() || mStopFlag == true); });

      if (!mQueue.empty()) {
        Data data = std::move(mQueue.front());
        mQueue.pop();

        /** do something Data **/
        std::cout << "###### Worker do data:" << data << "######" << std::endl;
      }

      if (mStopFlag) {
        std::cout << "Worker processData() mStopFlag:" << std::boolalpha
                  << mStopFlag << std::endl;
        break;
      }
    }
    std::cout << "Worker processData() finished" << std::endl;
  }

private:
  std::thread mSelf;
  std::mutex mMtx;
  std::condition_variable mCv;
  bool mStopFlag = false;

  std::queue<Data> mQueue;
};

int main() {
  std::cout << __FUNCTION__ << "() start" << std::endl;
  using namespace std::chrono_literals;

  auto worker = std::make_shared<Worker>();
  if (worker != nullptr) {
    worker->run();

    worker->putData("test1");
    std::this_thread::sleep_for(1s);

    worker->putData("test2");
    std::this_thread::sleep_for(1s);

    worker->putData("test3");
    std::this_thread::sleep_for(1s);

    worker->putData("test4");
    std::this_thread::sleep_for(1s);

    worker->stop();
  }

  std::cout << __FUNCTION__ << "() finish" << std::endl;
}