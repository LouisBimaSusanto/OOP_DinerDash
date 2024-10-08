#ifndef KITCHEN_H
#define KITCHEN_H

#include <memory>
#include "Order.h"

class Kitchen
{
public:
    void receiveOrder(std::shared_ptr<Order> order);
    void prepareOrder(std::shared_ptr<Order> order);
};

#endif