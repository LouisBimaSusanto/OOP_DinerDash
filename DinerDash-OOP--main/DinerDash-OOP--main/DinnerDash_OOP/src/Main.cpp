#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

// Kelas untuk memberikan informasi seputar status order pelanggan
class Order
{
public:
    enum class Status
    {
        NOT_YET_TAKEN,
        IN_KITCHEN,
        SERVED
    };

    Order(const string &description) : description(description), status(Status::NOT_YET_TAKEN) {}

    void setStatus(Status newStatus)
    {
        status = newStatus;
    }

    Status getStatus() const
    {
        return status;
    }

    string statusToString() const
    {
        switch (status)
        {
        case Status::NOT_YET_TAKEN:
            return "Belum Diambil \n";
        case Status::IN_KITCHEN:
            return "Sedang dimasak \n";
        case Status::SERVED:
            return "Disajikan \n";
        default:
            return "Tidak Diketahui \n";
        }
    }

    string toString() const
    {
        std::cout << std::endl;
        return "Pesanan: " + description + "\n"
                                           "Status: " +
               statusToString();
    }

private:
    string description;
    Status status;
};

// Kelas yang mengatur kondisi emosi dari pelanggan
class Customer
{
public:
    enum class Emotion
    {
        HAPPY,
        ANGRY
    };

    Customer(const string &color, int orderNumber)
        : color(color), orderNumber(orderNumber), emotion(Emotion::HAPPY), patience(100.0) {}

    void setOrder(shared_ptr<Order> order)
    {
        this->order = order;
    }

    void updateEmotion(double timeSpent)
    {
        patience -= timeSpent; // Mengurangi kesabaran berdasarkan waktu yang dihabiskan
        if (patience > 60)
        {
            emotion = Emotion::HAPPY;
        }
        else
        {
            emotion = Emotion::ANGRY;
        }
    }

    void setMaxSatisfaction()
    {
        emotion = Emotion::HAPPY; // Set to maximum satisfaction
        patience = 100.0;         // Reset patience to maximum value
    }

    string emotionToString() const
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

    void show() const
    {
        cout << "Warna pelanggan: " << color << endl;
        cout << "Nomor pesanan pelanggan: " << orderNumber << endl;
        cout << "Ekspresi pelanggan: " << emotionToString() << endl;
        if (order)
        {
            cout << order->toString() << endl;
        }
        else
        {
            cout << "Tidak ada pesanan." << endl;
        }
    }

private:
    string color;
    int orderNumber;
    shared_ptr<Order> order;
    Emotion emotion;
    double patience; // Mewakili tingkat kesabaran pelanggan
};

// Kelas untuk memberikan informasi tentang meja yang digunakan
class Table
{
public:
    Table(int number) : tableNumber(number), order(nullptr) {}

    void placeOrder(shared_ptr<Order> newOrder)
    {
        order = newOrder;
        cout << "Pesanan ditempatkan di meja " << tableNumber << ": " << order->toString() << endl;
        std::cout << std::endl;
    }

    void sendOrderToKitchen()
    {
        if (order)
        {
            order->setStatus(Order::Status::IN_KITCHEN);
            cout << "Pesanan dari meja " << tableNumber << " telah dikirim ke dapur: " << order->toString() << endl;
        }
        else
        {
            cout << "Tidak ada pesanan untuk dikirim ke dapur di meja " << tableNumber << endl;
        }
    }

    void show() const
    {
        cout << "Meja " << tableNumber << " dengan ";
        if (order)
        {
            cout << order->toString() << endl;
        }
        else
        {
            cout << "Tidak Ada Pesanan" << endl;
        }
    }

    shared_ptr<Order> getOrder() const
    {
        return order;
    }

    int getTableNumber() const
    {
        return tableNumber;
    }

private:
    int tableNumber;
    shared_ptr<Order> order;
};

// Kelas untuk mengatasi status pesanan yang sedang dimasak
class Kitchen
{
public:
    void receiveOrder(shared_ptr<Order> order)
    {
        if (order && order->getStatus() == Order::Status::IN_KITCHEN)
        {
            cout << "Dapur menerima pesanan: " << order->toString() << endl;
        }
        else
        {
            cout << "Pesanan tidak ada atau belum dikirim ke dapur." << endl;
        }
    }

    void prepareOrder(shared_ptr<Order> order)
    {
        if (order && order->getStatus() == Order::Status::IN_KITCHEN)
        {
            cout << "Dapur memproses pesanan: " << order->toString() << endl;
            // Simulasi waktu persiapan
            order->setStatus(Order::Status::SERVED);
            cout << "Pesanan telah siap di dapur: " << order->toString() << endl;
        }
        else
        {
            cout << "Pesanan belum siap untuk diproses." << endl;
        }
    }
};

// Kelas untuk mengelola aksi pelayan
class Waiter
{
public:
    // Fungsi untuk mengantarkan pesanan ke meja
    void deliverOrderToTable(shared_ptr<Table> table, shared_ptr<Customer> customer)
    {
        auto order = table->getOrder();
        if (order && order->getStatus() == Order::Status::SERVED)
        {
            cout << "Pelayan mengantarkan pesanan ke meja " << table->getTableNumber() << ": " << order->toString() << endl;
            customer->setMaxSatisfaction(); // Set customer satisfaction to maximum
        }
        else
        {
            cout << "Pesanan belum siap untuk diantarkan ke meja " << table->getTableNumber() << endl;
        }
    }

    // Fungsi untuk mengambil pesanan yang sudah selesai dari dapur
    void pickUpOrderFromKitchen(shared_ptr<Order> order, Kitchen &kitchen)
    {
        (void)kitchen; // Untuk membiarkan peringatan parameter kitchen karena untuk saat ini masih tidak digunakan

        if (order->getStatus() == Order::Status::SERVED)
        {
            cout << "Pelayan mengambil pesanan dari dapur: " << order->toString() << endl;
        }
        else
        {
            cout << "Pesanan belum siap untuk diambil dari dapur." << endl;
        }
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0)));

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
    if (rand() % 2 == 0)
    {
        table1.placeOrder(order1);
    }
    else
    {
        table1.placeOrder(order2);
    }

    if (rand() % 2 == 0)
    {
        table2.placeOrder(order1);
    }
    else
    {
        table2.placeOrder(order2);
    }

    // Menghubungkan pesanan dengan pelanggan
    customer1->setOrder(order1);
    customer2->setOrder(order2);

    // Mengirim pesanan ke dapur
    table1.sendOrderToKitchen();
    table2.sendOrderToKitchen();

    // Membuat dapur
    Kitchen kitchen;

    // Dapur menerima dan memproses pesanan
    kitchen.receiveOrder(order1);
    kitchen.prepareOrder(order1);

    // Membuat pelayan
    Waiter waiter;

    // Pelayan mengambil pesanan dari dapur
    waiter.pickUpOrderFromKitchen(order1, kitchen);

    // Pelayan mengantarkan pesanan ke meja
    waiter.deliverOrderToTable(make_shared<Table>(table1), customer1);
    waiter.deliverOrderToTable(make_shared<Table>(table2), customer2);

    // Menampilkan status dari berbagai objek
    std::cout << std::endl;
    cout << "Status meja 1:" << endl;
    table1.show();
    cout << "\n"
         << endl;

    cout << "Status meja 2:" << endl;
    table2.show();
    cout << "\n"
         << endl;

    cout << "Status pelanggan 1:" << endl;
    customer1->show();
    cout << "\n"
         << endl;

    cout << "Status pelanggan 2:" << endl;
    customer2->show();
    cout << "\n"
         << endl;

    return 0;
}
