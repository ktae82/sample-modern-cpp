#ifndef PRODCONS_IPRODUCER_H
#define PRODCONS_IPRODUCER_H

#include "include/Data.h"

class IProducer {
public:
  virtual ~IProducer() = default;
  virtual void start() = 0;
  virtual void produceData(Data &data) = 0;
  virtual void finish() = 0;
};

#endif // PRODCONS_IPRODUCER_H