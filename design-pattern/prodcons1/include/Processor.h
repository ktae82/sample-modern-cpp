#ifndef PRODCONS_PROCESSOR_H
#define PRODCONS_PROCESSOR_H

#include "include/Data.h"
#include "include/IProcessor.h"

class Processor : public IProcessor {
public:
  Processor(std::string name) : mName(name){};
  void process(const Data &data) override;

private:
  std::string mName;
};

#endif // PRODCONS_PROCESSOR_H