#include <iostream>
#include <utility>

void printByFirstSecond(const std::pair<int, double> &tempPair) {
  std::cout << __FUNCTION__ << "() entered." << std::endl;

  auto first = tempPair.first;
  auto second = tempPair.second;

  std::cout << "(" << first << ", " << second << ")" << std::endl;
}

void printByStdGet(const std::pair<int, double> &tempPair) {
  std::cout << __FUNCTION__ << "() entered." << std::endl;

  auto first = std::get<0>(tempPair);
  auto second = std::get<1>(tempPair);

  std::cout << "(" << first << ", " << second << ")" << std::endl;
}

int main() {
  auto tempPair = std::make_pair(1, 3.14);

  printByStdGet(tempPair);
  printByFirstSecond(tempPair);

  tempPair.first = 2;
  tempPair.second = 6.11;

  printByStdGet(tempPair);
  printByFirstSecond(tempPair);
}
