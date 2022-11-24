#ifndef OBSERVER_SUBJECT_H
#define OBSERVER_SUBJECT_H

#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "include/IObserver.h"

class Subject {
public:
  void registerObserver(const std::string &key,
                        std::weak_ptr<IObserver> observer);
  void unRegisterObserver(const std::string &key);
  void notify(const std::string &str);

public:
  void printObserverMap();

private:
  std::map<std::string, std::weak_ptr<IObserver>> mObserverMap;
};

#endif //#ifdef OBSERVER_SUBJECT_H