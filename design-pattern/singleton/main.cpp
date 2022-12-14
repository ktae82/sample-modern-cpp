#include <iostream>

class MeyersSingleton {
private:
  MeyersSingleton() { std::cout << "MeyersSingleton constructor" << std::endl; }
  virtual ~MeyersSingleton() {
    std::cout << "MeyersSingleton destructor" << std::endl;
  }

public:
  static MeyersSingleton &getInstance() {
    static MeyersSingleton instance;
    return instance;
  }

  void DoSomething(const std::string_view msg) {
    std::cout << "MeyersSingleton DoSomething() msg:" << msg << std::endl;
  }

public:
  MeyersSingleton(const MeyersSingleton &) = delete;
  MeyersSingleton(MeyersSingleton &&) = delete;
  MeyersSingleton &operator=(const MeyersSingleton &) = delete;
  MeyersSingleton &operator=(MeyersSingleton &&) = delete;
};

int main() {
  MeyersSingleton::getInstance().DoSomething("test1");

  MeyersSingleton &singleton = MeyersSingleton::getInstance();
  singleton.DoSomething("test2");

  return 0;
}
