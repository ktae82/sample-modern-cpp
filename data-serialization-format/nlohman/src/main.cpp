#include <iostream>

#include "include/ProductFactory.h"
#include "include/ProductList.h"

int main(int argc, char *argv[]) {
  if (argc == 1 || argc > 2) {
    std::cout << "usage:" << std::endl;
    std::cout << "    ex) ./nlohmann-sample ./products.json" << std::endl;
    return 0;
  }

  std::cout << "main start" << std::endl;

  ProductFactory productFactory;
  ProductList productList;
  std::string filePath(argv[1]);

  /* create Products */
  std::cout << "#################################################" << std::endl;
  productFactory.createProductsFromFile(filePath, productList);
  productList.printProducts();

  /* getProduct */
  std::cout << "#################################################" << std::endl;
  std::shared_ptr<Product> spProduct;
  productList.getProduct("123457", spProduct);
  if (spProduct != nullptr) {
    std::cout << "main name:" << spProduct->getName()
              << ", barcode:" << spProduct->getBarcode() << std::endl;
  }

  /* removeProduct */
  std::cout << "#################################################" << std::endl;
  productList.removeProduct("123457");
  productList.printProducts();

  std::cout << "main end" << std::endl;
  return 0;
}
