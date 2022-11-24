#include "include/ProductFactory.h"
#include <fstream>
#include <iostream>
#include <yaml-cpp/yaml.h>

void ProductFactory::createProductsFromFile(const std::string &file,
                                            ProductList &productList) {
  std::cout << "ProductFactory createProductsFromFile()" << std::endl;

  try {
    YAML::Node node = YAML::LoadFile(file);

    auto yamlArray = node["products"];
    for (const auto &product : yamlArray) {
      const std::string name = product["name"].as<std::string>();
      const std::string barcode = product["barcode"].as<std::string>();
      std::string key = barcode;

      productList.pushProduct(key, std::make_shared<Product>(name, barcode));
    }
  } catch (std::exception &e) {
    std::cerr << "ProductFactory exception e:" << e.what() << std::endl;
  }
}
