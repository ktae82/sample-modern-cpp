#include "include/SampleImpl.h"
#include <iostream>

SampleImpl::SampleImpl(const std::string &name) : mName(name) {
  std::cout << "Sample::" << __FUNCTION__ << "()" << std::endl;
};

SampleImpl::~SampleImpl() {}

void SampleImpl::testFunction1() {
  std::cout << "SampleImpl::" << __FUNCTION__ << "(), mName:" << mName
            << std::endl;
}

void SampleImpl::testFunction2() {
  std::cout << "SampleImpl::" << __FUNCTION__ << "(), mName:" << mName
            << std::endl;
}
