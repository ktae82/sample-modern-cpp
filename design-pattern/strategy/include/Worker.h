#ifndef STRATEGY_WORKER_H
#define STRATEGY_WORKER_H

#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "include/IStrategy.h"

class Worker {
public:
  void registerStrategy(std::weak_ptr<IStrategy> strategy);
  void doSomethingAll();

private:
  std::vector<std::weak_ptr<IStrategy>> mStrategys;
};

#endif //#ifdef STRATEGY_WORKER_H