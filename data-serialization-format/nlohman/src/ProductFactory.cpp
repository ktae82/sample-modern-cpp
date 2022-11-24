#include "include/ProductFactory.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

void ProductFactory::createProductsFromFile(const std::string &file,
                                            ProductList &productList) {
  std::cout << "ProductFactory createProductsFromFile()" << std::endl;
  nlohmann::json productsJson;

  try {
    std::fstream ifs(file);

    if (ifs.is_open()) {
      ifs >> productsJson;

      nlohmann::json jsonArray = productsJson["products"];
      for (const auto &product : jsonArray) {
        std::string name = product["name"];
        std::string barcode = product["barcode"];
        std::string key = barcode;

        productList.pushProduct(key, std::make_shared<Product>(name, barcode));
      }
    } else {
      std::cerr << "ProductFactory no file:" << file << std::endl;
    }
  } catch (std::exception &e) {
    std::cerr << "ProductFactory exception e:" << e.what() << std::endl;
  }
}
