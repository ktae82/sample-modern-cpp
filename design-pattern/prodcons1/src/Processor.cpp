#include <iostream>

#include "include/Data.h"
#include "include/Processor.h"

void Processor::process(const Data &data) {
  std::cout << "Processor name(" << mName << ") "
            << "do something data:" << data.getStr()
            << ", index:" << data.getIndex() << std::endl;
}