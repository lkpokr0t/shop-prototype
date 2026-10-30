#pragma once
#include <string>

class Product {
public:
    int productId;
    std::string name;
    double price;
    int stock;

    Product(int id, const std::string& prodName, double prodPrice, int prodStock)
        : productId(id), name(prodName), price(prodPrice), stock(prodStock) {
    }

    std::string getDetails() const {
        return "[" + std::to_string(productId) + "] " + name +
            " - " + std::to_string((int)price) + " / " + std::to_string(stock);
    }

    void updatePrice(double newPrice) {
        price = newPrice;
    }
};