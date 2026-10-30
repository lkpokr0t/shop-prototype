#pragma once
#include <vector>
#include <iostream>
#include <string>

// Структура элемента корзины
struct CartItem {
    int id;
    std::string name;
    double price;
};

class Cart {
public:
    std::vector<CartItem> items;
    double totalPrice = 0.0;

    void addItem(int id, const std::string& name, double price, int stock) {
        if (stock > 0) {
            items.push_back({ id, name, price });
            totalPrice += price;
            std::cout << "Товар '" << name << "' успешно добавлен в корзину.\n";
        }
        else {
            std::cout << "Ошибка: Товара '" << name << "' нет на складе!\n";
        }
    }

    void printCart() const {
        std::cout << "В корзине товаров: " << items.size() << ", на общую сумму: " << (int)totalPrice << " руб.\n";
    }
};