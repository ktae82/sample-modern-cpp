#ifndef PRODCONS_CONSUMER_H
#define PRODCONS_CONSUMER_H

#include "include/Data.h"
#include "include/IConsumer.h"

class Consumer : public IConsumer {
public:
  Consumer(std::string name) : mName(name){};

public: // IConsumer
  void start() override;
  void processData(const Data &data) override;
  void finish() override;

private:
  std::string mName;
};

#endif // PRODCONS_CONSUMER_H