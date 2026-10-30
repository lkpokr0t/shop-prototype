#pragma once
#include <iostream>
#include <string>

class Customer {
public:
    int id;
    std::string name;
    std::string address;
    bool isLoggedIn;

    Customer(int userId, const std::string& userName, const std::string& userAddress)
        : id(userId), name(userName), address(userAddress), isLoggedIn(false) {
    }

    bool login() {
        isLoggedIn = true;
        std::cout << "Покупатель " << name << " успешно вошел в систему.\n";
        return true;
    }

    void registerCustomer() {
        std::cout << "Покупатель " << name << " зарегистрирован по адресу: " << address << "\n";
    }

    void buyProduct() {
        std::cout << "Покупатель " << name << " перешел к оформлению покупки.\n";
    }
};