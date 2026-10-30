#pragma once
#include <iostream>
#include <string>
#include "ShopDatabase.h"
#include "Product.h"
#include "Order.h"

class Manager {
public:
    int id;
    std::string name;
    int employeeId;

    Manager(int userId, const std::string& userName, int empId)
        : id(userId), name(userName), employeeId(empId) {
    }

    void addProduct(const Product& p) {
        ShopDatabase::getInstance()->saveProduct(p);
        std::cout << "Менеджер " << name << " (ID: " << employeeId << ") добавил в магазин: " << p.name << "\n";
    }

    void processOrder(Order& order, bool approve) {
        if (approve) {
            order.changeStatus("Подтвержден менеджером");
            std::cout << "Менеджер " << name << " подтвердил заказ #" << order.orderId << ".\n";
        }
        else {
            order.cancel();
            std::cout << "Менеджер " << name << " отклонил заказ #" << order.orderId << ".\n";
        }
    }
};