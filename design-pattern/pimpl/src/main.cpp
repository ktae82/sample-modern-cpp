#include <iostream>
#include <memory>

#include "include/Sample.h"

int main() {
  std::cout << "main() start" << std::endl;

  Sample sample("Test Sample");
  sample.testFunction1();
  sample.testFunction2();

  std::cout << "main() end" << std::endl;

  return 0;
}