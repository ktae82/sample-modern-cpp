#include <chrono>
#include <memory>

#include "include/Consumer.h"
#include "include/Data.h"
#include "include/Producer.h"
#include "include/Worker.h"

int main() {
  using namespace std::chrono_literals;

  std::shared_ptr<Consumer> spConsumer = std::make_shared<Consumer>("AAA");
  std::shared_ptr<Producer> spProducer = std::make_shared<Producer>("AAA");
  std::shared_ptr<Worker> spWorker = std::make_shared<Worker>();

  if (spWorker != nullptr && spConsumer != nullptr && spProducer != nullptr) {
    // register
    spWorker->registerConsumer(spConsumer);
    spWorker->registerProducer(spProducer);

    // run producer / consumer
    spWorker->run();

    std::this_thread::sleep_for(2s);
    spWorker->stop();

    std::this_thread::sleep_for(500ms);
    spWorker->run();

    std::this_thread::sleep_for(2s);
    spWorker->stop();
  }

  std::cout << __FUNCTION__ << "() prodcons end" << std::endl;

  return 0;
}