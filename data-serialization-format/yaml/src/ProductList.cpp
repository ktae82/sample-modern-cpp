#include <iostream>

#include "include/ProductList.h"

void ProductList::pushProduct(const std::string &key,
                              const std::shared_ptr<Product> &product) {
  std::cout << "name:" << product->getName()
            << ", barcode:" << product->getBarcode() << std::endl;

  auto ret = mProducts.insert(std::pair(key, product));
  if (!ret.second) {
    ret.first->second = product;
  }
  // mProducts[key] = product;
}

void ProductList::getProduct(const std::string &key,
                             std::shared_ptr<Product> &product) {
  auto it = mProducts.find(key);
  if (it != mProducts.end()) {
    product = mProducts.at(key);
  }
  // product = mProducts[key];
}

void ProductList::removeProduct(const std::string &key) {
  auto it = mProducts.find(key);
  if (it != mProducts.end()) {
    mProducts.erase(it);
  }
}

void ProductList::printProducts() {
  for (const auto &product : mProducts) {
    std::cout << "key:" << product.first
              << ", name:" << product.second->getName()
              << ", barcode:" << product.second->getBarcode() << std::endl;
  }
}
