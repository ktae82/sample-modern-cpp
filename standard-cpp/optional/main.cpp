#include <iostream>
#include <optional>

std::optional<std::string> testOptional(bool testValue) {
  if (testValue)
    return "Hello";
  return std::nullopt;
}

int main() {
  auto test1 = testOptional(true);
  std::cout << "test1: " << *test1 << std::endl;

  auto test2 = testOptional(false);
  std::cout << "test2: " << *test2 << std::endl;

  std::cout << "testOptional(false) -> "
            << testOptional(false).value_or("empty") << std::endl;

  std::cout << "testOptional(false) -> " << testOptional(true).value_or("empty")
            << std::endl;

  return 0;
}