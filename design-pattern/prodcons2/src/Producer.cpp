#include <iostream>

#include "include/Data.h"
#include "include/Producer.h"

void Producer::start() {
  std::cout << "Producer::" << __FUNCTION__ << "()" << std::endl;
}

void Producer::produceData(Data &data) {
  std::cout << "Producer::" << __FUNCTION__ << "()" << std::endl;

  static int index = 0;
  data.setStr("TEST" + std::to_string(index));
  data.setIndex(index++);

  std::cout << "Producer::" << __FUNCTION__ << "() index:" << index
            << std::endl;
}

void Producer::finish() {
  std::cout << "Producer::" << __FUNCTION__ << "()" << std::endl;
}