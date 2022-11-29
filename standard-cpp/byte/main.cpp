#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

void stringToBytes(const std::string &srcStr,
                   std::vector<std::byte> &dstBytes) {
  std::cout << __FUNCTION__ << "() entered" << std::endl;

  dstBytes.reserve(srcStr.size());

  std::transform(srcStr.begin(), srcStr.end(), std::back_inserter(dstBytes),
                 [](char c) { return std::byte(c); });

  return;
}

void bytesToString(const std::vector<std::byte> &srcBytes,
                   std::string &dstStr) {
  std::cout << __FUNCTION__ << "() entered" << std::endl;

  std::transform(srcBytes.begin(), srcBytes.end(), std::back_inserter(dstStr),
                 [](std::byte b) { return static_cast<char>(b); });

  return;
}

int main() {
  std::cout << __FUNCTION__ << "() start" << std::endl;

  std::string inStr("TEST String");
  std::string outStr;
  std::vector<std::byte> bytes;

  stringToBytes(inStr, bytes);

  bytesToString(bytes, outStr);

  if (inStr.compare(outStr) == 0) {
    std::cout << "inStr == outStr" << std::endl;
  } else {
    std::cout << "inStr != outStr" << std::endl;
  }

  // std::cout << "inStr:" << inStr << ", outStr:" << outStr << std::endl;

  return 0;
}
