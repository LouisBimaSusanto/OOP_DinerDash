# DinerDash-OOP-

Ini merupakan respitory untuk tugas Dinner Dash OOP bersama Zacky

Nama Anggota Kelompok

1. Louis Bima Susanto (5223600075)
2. Zacky Ade Putra Harjuna (5223600076)

Berikut yang perlu dilakukan saat membuat  Single Responsibility Principle (SRP) dalam dinner dash :

# Yang di perlukan : #
  - Pastikan mempunyai C++ 11 atau lebih
  - Library standar C++
# Class and Responbility :#
## 1. Order (Pesanan) ##
Kelas ini untuk memppresentasikan pesanan untuk pelanggannya
Metode:
* Order(const string &description): Konstruktor yang menginisialisasi pesanan dengan deskripsi
* setStatus(Status newStatus): Memperbarui status pesanan pelanggan
* getStatus() const: Mengembalikan status pesanan
* statusToString() const: Mengubah status menjadi string yang mudah dibaca
* toString() const: Memperlihatkan representasi string dari pesanan
  
## 2. Customer (Pelanggan )##
Kelas ini untuk merepresentasikan pelanggan dan kesabarannya
Metode:
* setOrder(shared_ptr<Order> order): Mengaitkan pesanan pelanggan.
* updateEmotion(double timeSpent): Memperbarui emosi pelanggan berdasarkan waktu dihabiskan. Semakin lama waktu berlalu, tingkat kesabaran pelanggan berkurang, dan pelanggan menjadi marah
* setMaxSatisfaction(): Mengatur emosi pelanggan ke tingkat kepuasan maksimal ketika pesanan sudah terpenuhi atau dilayani
* emotionToString() const: Mengubah emosi menjadi string yang mudah dibaca
* show() const: Menampilkan deskripsi/detail dari pelanggan termasuk warna, nomor pesanan, emosi, dan pesanan yang dihubungkan

## 3. Table (Meja) 
kelas ini untuk merepresentasikan meja atau tempat pelanggan untuk dilayani 
Metode:
* placeOrder(shared_ptr<Order> newOrder): Menempatkan pesanan di meja
* sendOrderToKitchen(): Mengirimkan pesanan dari meja ke dapur
* show() const: Menampilkan status meja beserta pesanan yang terkait
* getOrder() const: Mengembalikan pesanan yang ditempatkan di meja
* getTableNumber() const: Mengembalikan nomor meja

## 4. Kitchen (Dapur)
Kelas ini untuk merepresentasikan dapur atau tempat memasak dari orderan pelanggan
Metode:
* receiveOrder(shared_ptr<Order> order): Menerima pesanan yang dikirim ke dapur
* prepareOrder(shared_ptr<Order> order): Mengecek kondisi pesanan sudah siap disajikan atau belum

## 5. Waiter (Pelayan)
Kelas ini untuk mempresentasikan tugas pelayan dalam mengantarkan pesanan ke meja pelanggan dan mengambil pesanan dari dapur.
Metode:
* deliverOrderToTable(shared_ptr<Table> table, shared_ptr<Customer> customer): Mengantarkan pesanan yang telah selesai dari dapur ke meja pelanggan.
* pickUpOrderFromKitchen(shared_ptr<Order> order, Kitchen &kitchen): Mengambil pesanan yang telah disiapkan dari dapur.

# Cara Menjalankan Program
* Membuka visual studio code
* Pilih menu -> File -> Open File -> (cari folder ini) -> Select Folder
* Cari file main.cpp di bagian src
* lalu pencet tombol mulai yang berada di bagian pojok kanan atas




Inggris

#DinerDash-OOP

This is the respitory for the Dinner Dash OOP assignment with Zacky

Group Member Name

1. Louis Bima Susanto (5223600075)
2. Zacky Ade Putra Harjuna (5223600076)

The following needs to be done when creating a Single Responsibility Principle (SRP) in a dinner dash:

# What is needed: #
  - Make sure you have C++ 11 or above
  - C++ standard library
# Class and Responsibility :#
## Order.
This class is for presenting orders to customers.
Methods:
* Order(const string &description): Constructor that initializes the order with a description
* setStatus(Status newStatus): Updates the status of the customer's order
* getStatus() const: Returns the status of the order
* statusToString() const: Converts the status to a readable string
* toString() const: Returns the string representation of the order
  
## 2. Customer
This class is for representing customers and their patience.
Method:
* setOrder(shared_ptr<Order> order): Associates the customer's order.
* updateEmotion(double timeSpent): Updates the customer's emotion based on the time spent. The longer the time passes, the customer's patience level decreases, and the customer becomes angry.
* setMaxSatisfaction(): Sets the customer's emotion to the maximum satisfaction level when the order is fulfilled or serviced.
* emotionToString() const: Converts the emotion to a readable string
* show() const: Displays the description/details of the customer including color, order number, emotion, and linked orders.

## Table 
This class is to represent a table or a place for customers to be served. 
Methods:
* placeOrder(shared_ptr<Order> newOrder): Places an order on the table
* sendOrderToKitchen(): Sends the order from the table to the kitchen
* show() const: Displays the status of the table and its associated orders
* getOrder() const: Returns the order placed on the table
* getTableNumber() const: Returns the table number

## Kitchen
This class represents the kitchen or cooking area of a customer order.
Methods:
* receiveOrder(shared_ptr<Order> order): Receive orders sent to the kitchen
* prepareOrder(shared_ptr<Order> order): Checking whether the order is ready to be served or not.

## 5. Waiter
This class is to present the waiter's task in delivering orders to the customer's table and taking orders from the kitchen.
Methods:
* deliverOrderToTable(shared_ptr<Table> table, shared_ptr<Customer> customer): Deliver the finished order from the kitchen to the customer's table.
* pickUpOrderFromKitchen(shared_ptr<Order> order, Kitchen&kitchen): Picks up the prepared order from the kitchen.

# How to Run the Program
* Open visual studio code
* Select menu -> File -> Open File -> (find this folder) -> Select Folder
* Find the main.cpp file in the src section
* then press the start button in the upper right corner
