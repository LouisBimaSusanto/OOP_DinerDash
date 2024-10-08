#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string &color, int orderNumber)
    : color(color), orderNumber(orderNumber), emotion(Emotion::HAPPY), patience(100.0) {}

void Customer::setOrder(std::shared_ptr<Order> order)
{
    this->order = order;
}

void Customer::updateEmotion(double timeSpent)
{
    patience -= timeSpent;
    if (patience > 60)
    {
        emotion = Emotion::HAPPY;
    }
    else
    {
        emotion = Emotion::ANGRY;
    }
}

void Customer::setMaxSatisfaction()
{
    emotion = Emotion::HAPPY;
    patience = 100.0;
}

std::string Customer::emotionToString() const
{
    switch (emotion)
    {
    case Emotion::HAPPY:
        return "Senang";
    case Emotion::ANGRY:
        return "Marah";
    default:
        return "Tidak Diketahui";
    }
}

void Customer::show() const
{
    std::cout << "Warna pelanggan: " << color << std::endl;
    std::cout << "Nomor pesanan pelanggan: " << orderNumber << std::endl;
    std::cout << "Ekspresi pelanggan: " << emotionToString() << std::endl;
    if (order)
    {
        std::cout << order->toString() << std::endl;
    }
    else
    {
        std::cout << "Tidak ada pesanan." << std::endl;
    }
}
