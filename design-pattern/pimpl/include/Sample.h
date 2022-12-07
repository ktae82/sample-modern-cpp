#ifndef SAMPLE_H
#define SAMPLE_H

#include <memory>
#include <string>

class SampleImpl;

class Sample {
public:
  Sample(const std::string &name);
  ~Sample();

  void testFunction1();
  void testFunction2();

private:
  std::unique_ptr<SampleImpl> pimpl;
};
#endif // SAMPLE_H