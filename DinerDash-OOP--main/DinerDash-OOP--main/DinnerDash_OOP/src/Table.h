#ifndef TABLE_H
#define TABLE_H

#include <memory>
#include "Order.h"

class Table
{
private:
    int tableNumber;
    std::shared_ptr<Order> order;

public:
    Table(int number);
    void placeOrder(std::shared_ptr<Order> newOrder);
    void sendOrderToKitchen();
    void show() const;
    std::shared_ptr<Order> getOrder() const;
    int getTableNumber() const;
};

#endif