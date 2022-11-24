#include <memory>

#include "include/Data.h"
#include "include/Processor.h"
#include "include/Worker.h"

int main() {
  std::shared_ptr<Processor> spProcessor1 = std::make_shared<Processor>("AAA");
  std::shared_ptr<Processor> spProcessor2 = std::make_shared<Processor>("BBB");
  std::shared_ptr<Worker> spWorker = std::make_shared<Worker>();

  if (spWorker != nullptr && spProcessor1 != nullptr &&
      spProcessor2 != nullptr) {
    // consumer (new thread)
    spWorker->registerProcessor(spProcessor1);
    spWorker->registerProcessor(spProcessor2);
    spWorker->run();

    // producer (main thread)
    int index = 0;
    for (index = 0; index < 10; index++) {
      spWorker->putData(Data{std::to_string(index), index});
    }

    while (1) {
      std::string temp;
      std::getline(std::cin, temp);

      spWorker->putData(Data{temp, index++});

      if (!temp.compare("quit")) {
        std::cout << "prodcons worker stop" << std::endl;
        spWorker->stop();
        break;
      }
    }
  }

  std::cout << "prodcons end" << std::endl;

  return 0;
}