#include "Table.h"
#include <iostream>

Table::Table(int number) : tableNumber(number), order(nullptr) {}

void Table::placeOrder(std::shared_ptr<Order> newOrder)
{
    order = newOrder;
    std::cout << "Pesanan ditempatkan di meja " << tableNumber << ": " << order->toString() << std::endl;
}

void Table::sendOrderToKitchen()
{
    if (order)
    {
        order->setStatus(Order::Status::IN_KITCHEN);
        std::cout << "Pesanan dari meja " << tableNumber << " telah dikirim ke dapur: " << order->toString() << std::endl;
    }
    else
    {
        std::cout << "Tidak ada pesanan untuk dikirim ke dapur di meja " << tableNumber << std::endl;
    }
}

void Table::show() const
{
    std::cout << "Meja " << tableNumber << " dengan ";
    if (order)
    {
        std::cout << order->toString() << std::endl;
    }
    else
    {
        std::cout << "Tidak Ada Pesanan" << std::endl;
    }
}

std::shared_ptr<Order> Table::getOrder() const
{
    return order;
}

int Table::getTableNumber() const
{
    return tableNumber;
}
