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
#include "include/IConsumer.h"
#include "include/IProducer.h"

class Worker : public std::enable_shared_from_this<Worker> {
public:
  void registerConsumer(std::weak_ptr<IConsumer> consumer);
  void registerProducer(std::weak_ptr<IProducer> producer);
  void putData(Data &&data);
  void run();
  void stop();

private:
  void producerThread(); // producer
  void consumerThread(); // consumer

private:
  std::thread mProducerThread;
  std::thread mConsumerThread;
  std::mutex mMtxProducer;
  std::mutex mMtxConsumer;
  std::condition_variable mCv;
  bool mStopProducer = false;
  bool mStopConsumer = false;

  std::weak_ptr<IConsumer> mwpIConsumer;
  std::weak_ptr<IProducer> mwpIProducer;
  std::queue<Data> mQueue;
};

#endif //#ifdef PRODCONS_WORKER_H