#include <iostream>
#include <map>

struct Data {
  int index;
  std::string str;
};

class TestMap {
public:
  void insertArray(int key, Data data) {
    std::cout << __FUNCTION__ << "()" << std::endl;
    mMap[key] = data;
  }

  void insertAPI(int key, Data data) {
    std::cout << __FUNCTION__ << "()" << std::endl;

    auto ret = mMap.insert(std::pair(key, data));
    if (!ret.second) {
      std::cout << __FUNCTION__ << "() change data" << std::endl;
      ret.first->second = data;
    }
  }

  void removeAPI(int key) {
    std::cout << __FUNCTION__ << "()" << std::endl;

    auto it = mMap.find(key);
    if (it != mMap.end()) {
      mMap.erase(it);
    }
  }

  void findArray(int key, Data &data) {
    std::cout << __FUNCTION__ << "()" << std::endl;

    data = mMap[key];
  }

  void findAPI(int key, Data &data) {
    std::cout << __FUNCTION__ << "()" << std::endl;

    auto it = mMap.find(key);
    if (it != mMap.end()) {
      data = mMap.at(key);
    }
  }

  void printMap() {
    std::cout << __FUNCTION__ << "()" << std::endl;

    for (const auto &elem : mMap) {
      std::cout << __FUNCTION__ << "() index:" << elem.second.index
                << ", str:" << elem.second.str << std::endl;
    }
  }

private:
  std::map<int, Data> mMap;
};

int main() {
  TestMap tMap;
  tMap.insertArray(0, Data{0, "test0"});
  tMap.insertArray(1, Data{1, "test1"});
  tMap.insertArray(2, Data{2, "test2"});
  tMap.printMap();

  tMap.insertAPI(0, Data{10, "test10"});
  tMap.insertAPI(1, Data{11, "test11"});
  tMap.insertAPI(3, Data{13, "test13"});
  tMap.printMap();

  tMap.removeAPI(0);
  tMap.removeAPI(1);
  tMap.printMap();

  Data data;
  tMap.findArray(2, data);
  std::cout << "findArray() index:" << data.index << ", str:" << data.str
            << std::endl;

  tMap.findAPI(3, data);
  std::cout << "findArray() index:" << data.index << ", str:" << data.str
            << std::endl;
  return 0;
}