#ifndef NLOHMAN_PRODUCTPARSER_H
#define NLOHMAN_PRODUCTPARSER_H

#include "include/ProductList.h"

class ProductFactory {
public:
  void createProductsFromFile(const std::string &file,
                              ProductList &productList);
};

#endif // NLOHMAN_PRODUCTPARSER_H