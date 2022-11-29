#ifndef OBSERVER_IOBSERVER_H
#define OBSERVER_IOBSERVER_H

class IObserver {
public:
  virtual ~IObserver() = default;
  virtual void update(const std::string &str) = 0;
};

#endif // OBSERVER_IOBSERVER_H
