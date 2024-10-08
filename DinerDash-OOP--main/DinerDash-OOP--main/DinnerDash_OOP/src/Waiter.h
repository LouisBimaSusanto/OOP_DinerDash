#ifndef WAITER_H
#define WAITER_H

#include <memory>
#include "Order.h"
#include "Table.h"
#include "Customer.h"
#include "Kitchen.h"

class Waiter
{
public:
    void pickUpOrderFromKitchen(std::shared_ptr<Order> order, Kitchen &kitchen);
    void deliverOrderToTable(std::shared_ptr<Table> table, std::shared_ptr<Customer> customer);
};

#endif
