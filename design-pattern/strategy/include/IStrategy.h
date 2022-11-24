#ifndef STRATEGY_ISTRATEGY_H
#define STRATEGY_ISTRATEGY_H

class IStrategy {
public:
  virtual ~IStrategy() = default;
  virtual void doSomething() = 0;
};

#endif // STRATEGY_ISTRATEGY_H
