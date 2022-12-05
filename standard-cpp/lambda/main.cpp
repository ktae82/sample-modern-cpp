#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cout << __FUNCTION__ << "()" << std::endl;

  std::vector<int> tv{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int maxValue = 7;
  int minValue = 3;

  /********************************************************/
  /* print tv values */
  for (const auto &e : tv) {
    std::cout << e << " " << std::flush;
  }
  std::cout << std::endl;

  /********************************************************/
  /* erase / remove_if */
  tv.erase(
      std::remove_if(tv.begin(), tv.end(),
                     [&](int e) { return (e < minValue) || (e > maxValue); }),
      tv.end());

  /********************************************************/
  /* print tv values */
  for (const auto &e : tv) {
    std::cout << e << " " << std::flush;
  }
  std::cout << std::endl;

  /********************************************************/
  /* lambda test */
  int ret = [](int a, int b) -> int { return a + b; }(10, 20);
  std::cout << __FUNCTION__ << "() ret:" << ret << std::endl;

  return 0;
}
