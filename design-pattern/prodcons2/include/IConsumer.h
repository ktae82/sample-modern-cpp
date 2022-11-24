#ifndef PRODCONS_ICONSUMER_H
#define PRODCONS_ICONSUMER_H

#include "include/Data.h"

class IConsumer {
public:
  virtual void start() = 0;
  virtual void processData(const Data &data) = 0;
  virtual void finish() = 0;
};

#endif // PRODCONS_ICONSUMER_H