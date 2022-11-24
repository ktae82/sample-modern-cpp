#include <iostream>

#include "include/Consumer.h"
#include "include/Data.h"

void Consumer::start() {
  std::cout << "Consumer::" << __FUNCTION__ << "()" << std::endl;
}

void Consumer::processData(const Data &data) {
  std::cout << "Consumer::" << __FUNCTION__ << "()" << std::endl;
  std::cout << "Consumer name(" << mName << ") "
            << "do something data:" << data.getStr()
            << ", index:" << data.getIndex() << std::endl;
}

void Consumer::finish() {
  std::cout << "Consumer::" << __FUNCTION__ << "()" << std::endl;
}
