#include "include/Subject.h"

void Subject::registerObserver(const std::string &key,
                               std::weak_ptr<IObserver> observer) {
  std::cout << "Subject registerObserver() key(" << key << ")" << std::endl;

  mObserverMap[key] = observer;
}

void Subject::unRegisterObserver(const std::string &key) {
  std::cout << "Subject unRegisterObserver() key(" << key << ")" << std::endl;

  auto iter = mObserverMap.find(key);
  if (iter != mObserverMap.end()) {
    mObserverMap.erase(iter);
  }
}

void Subject::notify(const std::string &str) {
  for (const auto &observer : mObserverMap) {
    auto spObserver = observer.second.lock();
    if (spObserver != nullptr) {
      spObserver->update(str);
    }
  }
}

void Subject::printObserverMap() {
  std::cout << "=================================================" << std::endl;

  for (const auto &observer : mObserverMap) {
    std::cout << " \"" << observer.first << "\"" << std::flush;
  }

  std::cout << std::endl;
  std::cout << "=================================================" << std::endl;
}