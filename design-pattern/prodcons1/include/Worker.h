#ifndef PRODCONS_WORKER_H
#define PRODCONS_WORKER_H

#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#include "include/Data.h"
#include "include/IProcessor.h"

class Worker : public std::enable_shared_from_this<Worker> {
public:
  void registerProcessor(std::weak_ptr<IProcessor> processor);
  void putData(Data &&data);
  void run();
  void stop();

private:
  void processData();

private:
  std::thread mSelf;
  std::mutex mMtx;
  std::condition_variable mCv;
  bool mStopFlag = false;

  std::vector<std::weak_ptr<IProcessor>> mIProcessors;
  std::queue<Data> mQueue;
};

#endif //#ifdef PRODCONS_WORKER_H