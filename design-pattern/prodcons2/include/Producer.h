#ifndef PRODCONS_PRODUCER_H
#define PRODCONS_PRODUCER_H

#include "include/Data.h"
#include "include/IProducer.h"

class Producer : public IProducer {
public:
  Producer(std::string name) : mName(name){};

public: // IProducer
  void start() override;
  void produceData(Data &data) override;
  void finish() override;

private:
  std::string mName;
};

#endif // PRODCONS_PRODUCER_H