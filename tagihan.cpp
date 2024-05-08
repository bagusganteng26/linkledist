#include <iostream>
using namespace std;
struct Tagihan
{
    string pelanggan, transaksi;
    double jumlah;

    Tagihan *next;
};

Tagihan *kepala, *ekor, *ini, *nodeBaru, *busek;

void ngisi(string pelanggan, string transaksi, double jumlah) {
    kepala = new Tagihan();
    kepala->pelanggan = pelanggan;
    kepala->transaksi = transaksi;
    kepala->jumlah = jumlah;
    kepala->next = NULL;
    ekor = kepala;   
}

void tambahAwal (string pelanggan, string transaksi, double jumlah) {
    nodeBaru = new Tagihan();
    nodeBaru->pelanggan = pelanggan;
    nodeBaru->transaksi = transaksi;
    nodeBaru->jumlah = jumlah;
    nodeBaru->next = kepala;
    kepala = nodeBaru;
}

void tambahGuri (string pelanggan, string transaksi, double jumlah) {
    nodeBaru = new Tagihan();
    nodeBaru->pelanggan = pelanggan;
    nodeBaru->transaksi = transaksi;
    nodeBaru->jumlah = jumlah;
    nodeBaru->next = NULL;
    ekor->next = nodeBaru;
    ekor = nodeBaru;
}

void cetak() {
    ini = kepala;
    while (ini != NULL)
    {
        cout << "nama pelanggan : " << ini -> pelanggan << endl;
        cout << "tanggal transaksi : " << ini -> transaksi << endl;
        cout << "jumlah transaksi : " << ini -> jumlah << endl;
        cout << endl;
    ini = ini -> next;
    }
}

void ubahAwal (string pelanggan, string transaksi, double jumlah) {
    kepala->pelanggan = pelanggan;
    kepala->transaksi = transaksi;
    kepala->jumlah = jumlah;
}
void ubahLast (string pelanggan, string transaksi, double jumlah) {
    ekor->pelanggan = pelanggan;
    ekor->transaksi = transaksi;
    ekor->jumlah = jumlah;
}

void hapusAwal () {
    busek = kepala;
    kepala = kepala->next;
    delete busek;
}

void hapusLast () {
    busek = ekor;
    ini = kepala;
    while (ini->next != ekor)
    {
        ini = ini->next;
    }
    ekor = ini;
    ekor->next = NULL;
    delete busek;  
}

int main () {
    ngisi("Hilmi", "20 mei", 2000);
    // cetak();
    tambahAwal("nopal", "30 mei 2000", 200000);
    tambahGuri("iman", "11 april", 40000);
    ubahAwal("giska", "26 februari", 5000);
    ubahLast("hudul", "50 agustus", 10000);
    hapusAwal();
    // hapusLast();
    cetak();

    return 0;
}