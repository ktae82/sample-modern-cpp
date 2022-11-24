#ifndef YAML_PRODUCTPARSER_H
#define YAML_PRODUCTPARSER_H

#include "include/ProductList.h"

class ProductFactory {
public:
  void createProductsFromFile(const std::string &file,
                              ProductList &productList);
};

#endif // YAML_PRODUCTPARSER_H