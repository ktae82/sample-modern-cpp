#include <chrono>
#include <future>
#include <iostream>
#include <thread>

bool print(std::string_view c) {
  using namespace std::chrono_literals;

  for (int i = 0; i < 200; i++) {
    std::cout << c << std::flush;
    std::this_thread::sleep_for(10ms);
  }

  return true;
}

int main() {
  auto future1 = std::async(std::launch::async, print, "1");
  auto future2 = std::async(std::launch::async, print, "2");
  auto future3 = std::async(std::launch::async, print, "3");
  auto future4 = std::async(std::launch::async, print, "4");

  future1.wait();
  future2.wait();
  future3.wait();
  future4.wait();

  std::cout << std::endl;

  std::cout << "future1: " << std::boolalpha << future1.get() << std::endl;
  std::cout << "future2: " << std::boolalpha << future2.get() << std::endl;
  std::cout << "future3: " << std::boolalpha << future3.get() << std::endl;
  std::cout << "future4: " << std::boolalpha << future4.get() << std::endl;
  return 0;
}