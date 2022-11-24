#ifndef NLOHMAN_PRODUCTLIST_H
#define NLOHMAN_PRODUCTLIST_H

#include <map>
#include <memory>

#include "include/Product.h"

class ProductList {
public:
  ProductList() = default;
  ~ProductList() = default;

public:
  void pushProduct(const std::string &key,
                   const std::shared_ptr<Product> &product);
  void getProduct(const std::string &key, std::shared_ptr<Product> &product);
  void removeProduct(const std::string &key);
  void printProducts();

private:
  std::map<std::string, std::shared_ptr<Product>> mProducts;
};

#endif // NLOHMAN_PRODUCTLIST_H
