#include <iostream>

#include "include/Observer.h"

void Observer::update(const std::string &str) {
  std::cout << "Observer(" << mName << ") update() do something data: " << str
            << std::endl;
}
