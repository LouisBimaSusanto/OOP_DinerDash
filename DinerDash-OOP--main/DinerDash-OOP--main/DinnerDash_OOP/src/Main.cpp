#include <iostream> // Pastikan ini ada di awal file
#include "Order.h"
#include "Customer.h"
#include "Table.h"
#include "Kitchen.h"
#include "Waiter.h"
#include <cstdlib>
#include <ctime>

using namespace std; // Opsional: ini menghindarkan Anda dari menulis 'std::' berulang-ulang

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    // Membuat meja
    Table table1(1);
    Table table2(2);

    // Membuat pelanggan
    auto customer1 = std::make_shared<Customer>("Merah", 101);
    auto customer2 = std::make_shared<Customer>("Biru", 102);

    // Membuat pesanan
    auto order1 = std::make_shared<Order>("Burger");
    auto order2 = std::make_shared<Order>("Burger");

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
    waiter.deliverOrderToTable(std::make_shared<Table>(table1), customer1);
    waiter.deliverOrderToTable(std::make_shared<Table>(table2), customer2);

    // Menampilkan status dari berbagai objek
    std::cout << "\nStatus meja 1:" << std::endl;
    table1.show();
    std::cout << "\nStatus meja 2:" << std::endl;
    table2.show();
    std::cout << "\nStatus pelanggan 1:" << std::endl;
    customer1->show();
    std::cout << "\nStatus pelanggan 2:" << std::endl;
    customer2->show();

    return 0;
}
