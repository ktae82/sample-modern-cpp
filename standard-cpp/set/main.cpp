#include <iostream>
#include <set>

template <typename T> void printSetValue(const std::set<T> &tempSet) {
  std::cout << __FUNCTION__ << "() entered." << std::endl;

  for (const auto &elem : tempSet) {
    std::cout << elem << ", " << std::flush;
  }
  std::cout << std::endl;

  // std::set<T>::iterator iter;
  // for (iter = tempSet.begin(); iter != tempSet.end(); iter++) {
  //  std::cout << *iter << " " << std::flush;
  //}
  // std::cout << std::endl;
}

void testSetInt() {
  std::cout << __FUNCTION__ << "() entered." << std::endl;
  std::set<int> tempSet;

  tempSet.insert(40);
  tempSet.insert(10);
  printSetValue(tempSet);

  tempSet.insert(20);
  tempSet.insert(30);
  printSetValue(tempSet);

  auto iter1 = tempSet.find(30);
  if (iter1 != tempSet.end()) {
    std::cout << "find value:" << *iter1 << std::endl;
  } else {
    std::cout << "there is no value:" << *iter1 << std::endl;
  }
}

void testSetString() {
  std::cout << __FUNCTION__ << "() entered." << std::endl;
  std::set<std::string> tempSet;

  tempSet.insert("AAA");
  tempSet.insert("DDD");
  printSetValue(tempSet);

  tempSet.insert("CCC");
  tempSet.insert("BBB");
  printSetValue(tempSet);

  auto iter1 = tempSet.find("CCC");
  if (iter1 != tempSet.end()) {
    std::cout << "find value:" << *iter1 << std::endl;
  } else {
    std::cout << "there is no value:" << *iter1 << std::endl;
  }
}

int main(void) {
  std::cout << __FUNCTION__ << "() entered." << std::endl;

  testSetInt();

  testSetString();

  return 0;
}
