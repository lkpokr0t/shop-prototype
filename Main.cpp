#include <iostream>
#include <windows.h>
#include "ShopDatabase.h"
#include "Manager.h"
#include "Customer.h"
#include "Product.h"
#include "Cart.h"
#include "Order.h"

// Инициализация статического поля базы данных (Singleton)
ShopDatabase* ShopDatabase::instance = nullptr;

int main() {
    // Включение поддержки русского языка в консоли
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "=====================================================\n";
    std::cout << "   ДЕМОНСТРАЦИЯ РАБОТЫ ИНТЕРНЕТ-МАГАЗИНА (ЛАБ 5)     \n";
    std::cout << "=====================================================\n\n";

    ShopDatabase* db = ShopDatabase::getInstance();

    // 1. ДЕЙСТВИЯ МЕНЕДЖЕРА (US-4: Наполнение магазина товарами)
    std::cout << "[1. Добавление товаров менеджером]:\n";
    Manager manager(1, "Алексей Смирнов", 101);
    Product p1(101, "Ноутбук Asus ZenBook", 75000.0, 2);
    Product p2(102, "Игровая мышь Razer", 2500.0, 0); // Товар закончился на складе

    manager.addProduct(p1);
    manager.addProduct(p2);

    // 2. ДЕЙСТВИЯ ПОКУПАТЕЛЯ (US-1, US-2: Регистрация и витрина)
    std::cout << "\n[2. Регистрация покупателя и каталог]:\n";
    Customer customer(2, "Иван Петров", "ул. Ленина, д. 45, кв. 12");
    customer.registerCustomer();
    customer.login();

    std::cout << "\nДоступный каталог магазина:\n";
    for (const auto& prod : db->products) {
        std::cout << " - " << prod.getDetails() << "\n";
    }

    // 3. РАБОТА С КОРЗИНОЙ И ПОКУПКА (US-3: Ветвление активности)
    std::cout << "\n[3. Добавление товаров в корзину]:\n";
    Cart cart;
    customer.buyProduct();
    cart.addItem(p1.productId, p1.name, p1.price, p1.stock);
    cart.addItem(p2.productId, p2.name, p2.price, p2.stock); // Сработает проверка остатка!
    cart.printCart();
    // 5. ОБРАБОТКА ЗАКАЗА МЕНЕДЖЕРОМ (US-5)
    std::cout << "\n[5. Обработка заказа менеджером]:\n";
    manager.processOrder(order, true);
    std::cout << "Итоговый статус заказа в системе: [" << order.status << "]\n";

    std::cout << "\n=====================================================\n";
    std::cout << "              ТЕСТ УСПЕШНО ЗАВЕРШЕН                  \n";
    std::cout << "=====================================================\n";

    return 0;
}