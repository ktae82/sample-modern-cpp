#include <algorithm>
#include <iostream>
#include <vector>

void toStringVector(int argc, char *argv[], std::vector<std::string> &out) {
  std::cout << __FUNCTION__ << "(), argc:" << argc << std::endl;

  // change argc,argv to std::vector<std::string>
  out = std::move(std::vector<std::string>(argv, argv + argc));

  // print
  for (const auto &elem : out) {
    std::cout << elem << " " << std::flush;
  }
  std::cout << std::endl;
}

void toCharPtrVector(std::vector<std::string> &in,
                     std::vector<const char *> &out) {
  std::cout << __FUNCTION__ << "(), in.size():" << in.size() << std::endl;

  // change std::vector<std::string> to std::vector<char>
  out.resize(in.size());
  std::transform(in.begin(), in.end(), out.begin(),
                 [](std::string &str) { return str.c_str(); });

  // std::transform(in.begin(), in.end(), out.begin(),
  //                std::mem_fun_ref(&std::string::c_str));

  // print
  for (const auto &elem : in) {
    std::cout << elem << " " << std::flush;
  }
  std::cout << std::endl;
}

void printArgcArgv(int argc, char *argv[]) {
  std::cout << __FUNCTION__ << "(), argc:" << argc << std::endl;

  // print
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << " " << std::flush;
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  std::cout << __FUNCTION__ << "(), argc:" << argc << std::endl;

  std::vector<std::string> argVecStr;
  std::vector<const char *> argVecCharPtr;

  toStringVector(argc, argv, argVecStr);
  toCharPtrVector(argVecStr, argVecCharPtr);
  printArgcArgv(argVecCharPtr.size(),
                const_cast<char **>(argVecCharPtr.data()));

  return 0;
}