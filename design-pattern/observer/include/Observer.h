#ifndef OBSERVER_OBSERVER_H
#define OBSERVER_OBSERVER_H

#include "include/IObserver.h"
#include <string>

class Observer : public IObserver {
public:
  Observer(const std::string &name) : mName(name) {}

public:
  void update(const std::string &str) override;

private:
  std::string mName;
};

#endif // OBSERVER_OBSERVER_H
