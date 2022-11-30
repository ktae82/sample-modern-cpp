#include <iostream>
#include <tuple>
#include <utility>

void printByStdGet(const std::tuple<int, double, bool> &tempTuple) {
  std::cout << __FUNCTION__ << "() entered." << std::endl;

  auto temp0 = std::get<0>(tempTuple);
  auto temp1 = std::get<1>(tempTuple);
  auto temp2 = std::get<2>(tempTuple);

  std::cout << "(" << temp0 << ", " << temp1 << ", " << std::boolalpha << temp2
            << ")" << std::endl;
}

int main() {
  auto tempTuple = std::make_tuple(1, 3.14, true);

  printByStdGet(tempTuple);
  printByStdGet(tempTuple);
}
