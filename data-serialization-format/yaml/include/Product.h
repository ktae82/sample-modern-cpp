#ifndef YAML_PRODUCT_H
#define YAML_PRODUCT_H

#include <string>

class Product {
public:
  Product(const std::string &name, const std::string &barcode)
      : mName(name), mBarcode(barcode){};
  // Product(const Product &product)
  //     : mName(product.mName), mBarcode(product.mBarcode){};
  // Product(Product &&product)
  //     : mName(std::move(product.mName)),
  //       mBarcode(std::move(product.mBarcode)){};

public:
  const std::string_view getName() const { return mName; }
  const std::string_view getBarcode() const { return mBarcode; }

private:
  std::string mName;
  std::string mBarcode;
};

#endif // YAML_PRODUCT_H
