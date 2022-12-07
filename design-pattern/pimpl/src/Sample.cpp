#include "include/Sample.h"
#include "include/SampleImpl.h"
#include <iostream>

Sample::Sample(const std::string &name)
    : pimpl(std::make_unique<SampleImpl>(name)) {
  std::cout << "Sample::" << __FUNCTION__ << "()" << std::endl;
}

Sample::~Sample() {}

void Sample::testFunction1() {
  std::cout << "Sample::" << __FUNCTION__ << "()" << std::endl;

  if (pimpl != nullptr) {
    pimpl->testFunction1();
  }
}

void Sample::testFunction2() {
  std::cout << "Sample::" << __FUNCTION__ << "()" << std::endl;

  if (pimpl != nullptr) {
    pimpl->testFunction2();
  }
}
