#include "include/Worker.h"

void Worker::registerStrategy(std::weak_ptr<IStrategy> strategy) {
  std::cout << "Worker " << __FUNCTION__ << "()" << std::endl;

  mStrategys.push_back(strategy);
}

void Worker::doSomethingAll() {
  std::cout << "Worker " << __FUNCTION__ << "()" << std::endl;

  for (const auto &strategy : mStrategys) {
    auto spStrategy = strategy.lock();
    if (spStrategy != nullptr) {
      spStrategy->doSomething();
    }
  }
}
