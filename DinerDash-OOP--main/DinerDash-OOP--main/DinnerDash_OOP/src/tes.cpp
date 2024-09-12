#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Order {
public:
    enum class Status {
        NOT_YET_TAKEN,
        IN_KITCHEN,
        SERVED
    };

    Order(const string& description) : description(description), status(Status::NOT_YET_TAKEN) {}

    void setStatus(Status newStatus) {
        status = newStatus;
    }

    Status getStatus() const {
        return status;
    }

    string statusToString() const {
        switch (status) {
            case Status::NOT_YET_TAKEN: return "Belum Diambil";
            case Status::IN_KITCHEN: return "Di Dapur";
            case Status::SERVED: return "Disajikan";
            default: return "Tidak Diketahui";
        }
    }

    string toString() const {
        return "Pesanan: " + description + ", Status: " + statusToString();
    }

private:
    string description;
    Status status;
};

class Customer {
public:
    enum class Emotion {
        HAPPY,
        ANGRY,
        NEUTRAL
    };

    Customer(const string& color, int orderNumber) 
        : color(color), orderNumber(orderNumber), emotion(Emotion::NEUTRAL), patience(100.0) {}

    void setOrder(shared_ptr<Order> order) {
        this->order = order;
    }

    void updateEmotion(double timeSpent) {
        patience -= timeSpent; // Reduce patience based on time spent
        if (patience > 60) {
            emotion = Emotion::HAPPY;
        } else if (patience > 30) {
            emotion = Emotion::NEUTRAL;
        } else {
            emotion = Emotion::ANGRY;
        }
    }

    string emotionToString() const {
        switch (emotion) {
            case Emotion::HAPPY: return "Senang";
            case Emotion::ANGRY: return "Marah";
            case Emotion::NEUTRAL: return "Netral";
            default: return "Tidak Diketahui";
        }
    }

    void show() const {
        cout << "Warna pelanggan: " << color << endl;
        cout << "Nomor pesanan pelanggan: " << orderNumber << endl;
        cout << "Emosi pelanggan: " << emotionToString() << endl;
        if (order) {
            cout << order->toString() << endl;
        } else {
            cout << "Tidak ada pesanan." << endl;
        }
    }

private:
    string color;
    int orderNumber;
    shared_ptr<Order> order;
    Emotion emotion;
    double patience; // Represents how patient the customer is
};

class Table {
public:
    Table(int number) : tableNumber(number), order(nullptr) {}

    void placeOrder(shared_ptr<Order> newOrder) {
        order = newOrder;
        cout << "Pesanan ditempatkan di meja " << tableNumber << ": " << order->toString() << endl;
    }

    void sendOrderToKitchen() {
        if (order) {
            order->setStatus(Order::Status::IN_KITCHEN);
            cout << "Pesanan dari meja " << tableNumber << " telah dikirim ke dapur: " << order->toString() << endl;
        } else {
            cout << "Tidak ada pesanan untuk dikirim ke dapur di meja " << tableNumber << endl;
        }
    }

    void show() const {
        cout << "Meja " << tableNumber << " dengan ";
        if (order) {
            cout << order->toString() << endl;
        } else {
            cout << "Tidak Ada Pesanan" << endl;
        }
    }

    shared_ptr<Order> getOrder() const {
        return order;
    }

    int getTableNumber() const {
        return tableNumber;
    }

private:
    int tableNumber;
    shared_ptr<Order> order;
};

class Kitchen {
public:
    void receiveOrder(shared_ptr<Order> order) {
        if (order && order->getStatus() == Order::Status::IN_KITCHEN) {
            cout << "Dapur menerima pesanan: " << order->toString() << endl;
        } else {
            cout << "Pesanan tidak ada atau belum dikirim ke dapur." << endl;
        }
    }

    void prepareOrder(shared_ptr<Order> order) {
        if (order && order->getStatus() == Order::Status::IN_KITCHEN) {
            cout << "Dapur memproses pesanan: " << order->toString() << endl;
            // Simulate preparation time
            order->setStatus(Order::Status::SERVED);
            cout << "Pesanan telah siap di dapur: " << order->toString() << endl;
        } else {
            cout << "Pesanan tidak siap untuk diproses." << endl;
        }
    }
};

int main() {
    // Membuat meja
    Table table1(1);
    Table table2(2);

    // Membuat pelanggan
    auto customer1 = make_shared<Customer>("Merah", 101);
    auto customer2 = make_shared<Customer>("Biru", 102);

    // Membuat pesanan
    auto order1 = make_shared<Order>("Burger");
    auto order2 = make_shared<Order>("Burger");

    // Menempatkan pesanan di meja
    table1.placeOrder(order1);
    table2.placeOrder(order2);

    // Menghubungkan pesanan dengan pelanggan
    customer1->setOrder(order1);
    customer2->setOrder(order2);

    // Mengirim pesanan ke dapur
    table1.sendOrderToKitchen();

    // Membuat dapur
    Kitchen kitchen;

    // Dapur menerima dan memproses pesanan
    kitchen.receiveOrder(order1);
    kitchen.prepareOrder(order1);

    // Menampilkan status dari berbagai objek
    cout << "Status meja 1:" << endl;
    table1.show();
    cout << "Status meja 2:" << endl;
    table2.show();
    cout << "Status pelanggan 1:" << endl;
    customer1->show();
    cout << "Status pelanggan 2:" << endl;
    customer2->show();

    return 0;
}
