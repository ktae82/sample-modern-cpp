#ifndef SAMPLE_IMPL_H
#define SAMPLE_IMPL_H

#include <memory>
#include <string>

class SampleImpl {
public:
  SampleImpl(const std::string &name);
  ~SampleImpl();

  void testFunction1();
  void testFunction2();

private:
  std::string mName;
};

#endif // SAMPLE_IMPL_H