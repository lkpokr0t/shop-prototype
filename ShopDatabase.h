#pragma once
#include <vector>
#include <iostream>
#include "Product.h"

class ShopDatabase {
private:
    static ShopDatabase* instance;
    ShopDatabase() = default;

public:
    std::vector<Product> products;

    static ShopDatabase* getInstance() {
        if (instance == nullptr) {
            instance = new ShopDatabase();
        }
        return instance;
    }

    void saveProduct(const Product& p) {
        products.push_back(p);
        std::cout << "Товар '" << p.name << "' сохранен в базу данных магазина.\n";
    }
};