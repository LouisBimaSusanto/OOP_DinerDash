# DinerDash-OOP-

Ini merupakan respitory untuk tugas Dinner Dash OOP bersama Zacky

Nama Anggota Kelompok

1. Louis Bima Susanto (5223600075)
2. Zacky Ade Putra Harjuna (5223600076)

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
-  Kelas ini merepresentasikan pesanan dari pelanggan. Kelas ini menyimpan deskripsi pesanan serta statusnya saat ini.
Metode:
* Order(const string &description): Konstruktor untuk menginisialisasi pesanan dengan deskripsi.
* setStatus(Status newStatus): Memperbarui status pesanan.
* getStatus() const: Mengembalikan status saat ini dari pesanan.
* statusToString() const: Mengubah status menjadi string yang mudah dibaca.
* toString() const: Memberikan representasi string dari pesanan.
  
2. Customer (Pelanggan)
Merepresentasikan pelanggan dan atribut terkait seperti kondisi emosional dan tingkat kesabarannya.
Metode:
* setOrder(shared_ptr<Order> order): Mengaitkan pesanan dengan pelanggan.
* updateEmotion(double timeSpent): Memperbarui emosi pelanggan berdasarkan waktu yang telah dihabiskan. Semakin lama waktu berlalu, tingkat kesabaran berkurang, dan pelanggan mungkin menjadi marah.
* setMaxSatisfaction(): Mengatur emosi pelanggan ke tingkat kepuasan maksimal dan mengembalikan kesabarannya ke nilai maksimum.
* emotionToString() const: Mengubah emosi menjadi string yang mudah dibaca.
* show() const: Menampilkan informasi pelanggan termasuk warna, nomor pesanan, emosi, dan pesanan yang dihubungkan.

3. Table (Meja)
Merepresentasikan meja di restoran tempat pelanggan duduk dan melakukan pemesanan.
Metode:
placeOrder(shared_ptr<Order> newOrder): Menempatkan pesanan di meja.
sendOrderToKitchen(): Mengirimkan pesanan dari meja ke dapur.
show() const: Menampilkan status meja beserta pesanan yang terkait.
getOrder() const: Mengembalikan pesanan yang ditempatkan di meja.
getTableNumber() const: Mengembalikan nomor meja.

5. Kitchen (Dapur)
Merepresentasikan dapur di mana pesanan disiapkan setelah diterima dari meja.
Metode:
receiveOrder(shared_ptr<Order> order): Menerima pesanan yang dikirim ke dapur.
prepareOrder(shared_ptr<Order> order): Memproses pesanan di dapur dan mengubah statusnya menjadi "Disajikan" setelah selesai.

5. Waiter (Pelayan)
Mengelola tugas pelayan dalam mengantarkan pesanan ke meja pelanggan dan mengambil pesanan dari dapur.
Metode:
deliverOrderToTable(shared_ptr<Table> table, shared_ptr<Customer> customer): Mengantarkan pesanan yang telah selesai dari dapur ke meja pelanggan.
pickUpOrderFromKitchen(shared_ptr<Order> order, Kitchen &kitchen): Mengambil pesanan yang telah disiapkan dari dapur.
