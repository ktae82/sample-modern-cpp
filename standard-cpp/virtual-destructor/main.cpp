#include <iostream>
#include <memory>

class VirtualParent {
public:
  // virtual ~VirtualParent() = default;
  virtual void function() = 0;
};

class Child : public VirtualParent {
public:
  Child() { std::cout << "\tChild::Child()" << std::endl; }
  ~Child() { std::cout << "\tChild::~Child()" << std::endl; }
  void function() override { std::cout << "\tChild::function()" << std::endl; }
};

void createByUniquePtr() {
  std::cout << __FUNCTION__ << "() entered" << std::endl;
  {
    auto spChild = std::make_unique<Child>();
    spChild->function();
  }
  std::cout << __FUNCTION__ << "() exited" << std::endl;
}

void createBySharedPtr() {
  std::cout << __FUNCTION__ << "() entered" << std::endl;
  {
    auto spChild = std::make_shared<Child>();
    spChild->function();
  }
  std::cout << __FUNCTION__ << "() exited" << std::endl;
}

void createByRawPtr() {
  std::cout << __FUNCTION__ << "() entered" << std::endl;
  {
    VirtualParent *pChild = new Child();
    pChild->function();
    delete pChild;
  }
  std::cout << __FUNCTION__ << "() exited" << std::endl;
}

void createByRawPtrToSharedPtr() {
  std::cout << __FUNCTION__ << "() entered" << std::endl;
  {
    std::shared_ptr<VirtualParent> spChild{new Child};
    spChild->function();
  }
  std::cout << __FUNCTION__ << "() exited" << std::endl;
}

int main() {
  createByUniquePtr();

  createBySharedPtr();

  createByRawPtr();

  createByRawPtrToSharedPtr();
}
