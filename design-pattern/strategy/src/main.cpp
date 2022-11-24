#include <iostream>
#include <memory>

#include "include/StrategyAAA.h"
#include "include/StrategyBBB.h"
#include "include/StrategyCCC.h"
#include "include/Worker.h"

int main() {
  std::cout << "main() start" << std::endl;

  auto spWorker = std::make_shared<Worker>();
  auto spStrategyAAA = std::make_shared<StrategyAAA>();
  auto spStrategyBBB = std::make_shared<StrategyBBB>();
  auto spStrategyCCC = std::make_shared<StrategyCCC>();

  if (spWorker != nullptr && spStrategyAAA != nullptr &&
      spStrategyBBB != nullptr && spStrategyCCC != nullptr) {
    spWorker->registerStrategy(spStrategyAAA);
    spWorker->registerStrategy(spStrategyBBB);
    spWorker->registerStrategy(spStrategyCCC);

    spWorker->doSomethingAll();
  }

  std::cout << "main() end" << std::endl;

  return 0;
}