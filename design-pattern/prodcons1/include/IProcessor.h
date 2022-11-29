#ifndef PRODCONS_IPROCESSOR_H
#define PRODCONS_IPROCESSOR_H

#include "include/Data.h"

class IProcessor {
public:
  virtual ~IProcessor() = default;
  virtual void process(const Data &data) = 0;
};

#endif // PRODCONS_IPROCESSOR_H