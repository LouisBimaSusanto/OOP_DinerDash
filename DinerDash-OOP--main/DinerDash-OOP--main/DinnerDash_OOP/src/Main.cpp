#include <iostream>
#include <string>

using namespace std;

class DisplayOrder
{
};

class Pelanggan
{
public:
    string warnaPelanggan;
    int pesanan;
    double waktu;
    double patience;

    int jmlhPelanggan;

    bool isServe;

    Pelanggan(const char *warnaPelanggan, int pesanan)
    {
        Pelanggan::warnaPelanggan = warnaPelanggan;
        Pelanggan::pesanan = pesanan;
    }

    void show()
    {
        cout << "Warna dari pelanggan adalah" << Pelanggan::warnaPelanggan << endl;
        cout << "Nomor pesanan pelanggan adalah" << Pelanggan::pesanan << endl;
    }
};

class Meja
{
public:
    int jmlhMeja;
};

int main(int argc, char const *argv[])
{
    Pelanggan customer1 = Pelanggan(" Merah", 2);
    customer1.show();
    return 0;
}
