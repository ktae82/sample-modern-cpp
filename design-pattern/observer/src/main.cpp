#include <memory>

#include "include/Observer.h"
#include "include/Subject.h"

const std::string key1 = "observer A";
const std::string key2 = "observer B";
const std::string key3 = "observer C";

int main() {
  std::cout << "main() start" << std::endl;

  std::shared_ptr<Subject> spSubject = std::make_shared<Subject>();
  std::shared_ptr<Observer> spObserver1 = std::make_shared<Observer>("A");
  std::shared_ptr<Observer> spObserver2 = std::make_shared<Observer>("B");
  std::shared_ptr<Observer> spObserver3 = std::make_shared<Observer>("C");

  if (spSubject != nullptr && spObserver1 != nullptr &&
      spObserver2 != nullptr && spObserver3 != nullptr) {
    spSubject->registerObserver(key1, spObserver1);
    spSubject->registerObserver(key2, spObserver2);
    spSubject->registerObserver(key3, spObserver3);

    spSubject->notify("test notify 1");
    spSubject->notify("test notify 2");
    spSubject->printObserverMap();

    spSubject->unRegisterObserver(key2);
    spSubject->unRegisterObserver(key3);

    spSubject->notify("test notify 3");
    spSubject->printObserverMap();
  }

  std::cout << "main() end" << std::endl;

  return 0;
}