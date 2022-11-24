#ifndef PRODCONS_DATA_H
#define PRODCONS_DATA_H

#include <string>

class Data {
public:
  Data() {}
  Data(std::string str, int index) : mStr(str), mIndex(index) {}

  std::string getStr() const { return mStr; }
  int getIndex() const { return mIndex; }

  void setStr(std::string str) { mStr = str; }
  void setIndex(int index) { mIndex = index; }

private:
  std::string mStr;
  int mIndex;
};

#endif // PRODCONS_DATA_H