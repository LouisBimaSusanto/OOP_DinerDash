#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <memory>
#include "Order.h"

class Customer
{
public:
    enum class Emotion
    {
        HAPPY,
        ANGRY
    };

    Customer(const std::string &color, int orderNumber);
    void setOrder(std::shared_ptr<Order> order);
    void updateEmotion(double timeSpent);
    void setMaxSatisfaction();
    std::string emotionToString() const;
    void show() const;

private:
    std::string color;
    int orderNumber;
    std::shared_ptr<Order> order;
    Emotion emotion;
    double patience;
};

#endif