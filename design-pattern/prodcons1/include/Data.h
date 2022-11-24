#ifndef PRODCONS_DATA_H
#define PRODCONS_DATA_H

#include <string>

class Data {
public:
  Data(std::string str, int index) : mStr(str), mIndex(index) {}

  std::string getStr() const { return mStr; }
  int getIndex() const { return mIndex; }

private:
  std::string mStr;
  int mIndex;
};

#endif // PRODCONS_DATA_H