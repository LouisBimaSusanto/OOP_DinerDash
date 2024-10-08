#include "Kitchen.h"
#include <iostream>

void Kitchen::receiveOrder(std::shared_ptr<Order> order)
{
    if (order && order->getStatus() == Order::Status::IN_KITCHEN)
    {
        std::cout << "Dapur menerima pesanan: " << order->toString() << std::endl;
    }
    else
    {
        std::cout << "Pesanan tidak ada atau belum dikirim ke dapur." << std::endl;
    }
}

void Kitchen::prepareOrder(std::shared_ptr<Order> order)
{
    if (order && order->getStatus() == Order::Status::IN_KITCHEN)
    {
        std::cout << "Dapur memproses pesanan: " << order->toString() << std::endl;
        order->setStatus(Order::Status::SERVED);
        std::cout << "Pesanan telah siap di dapur: " << order->toString() << std::endl;
    }
    else
    {
        std::cout << "Pesanan belum siap untuk diproses." << std::endl;
    }
}
