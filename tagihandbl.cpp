#include <iostream>
using namespace std;

struct Tagihan
{
    string pelanggan, tanggal;
    double jumlah;

    Tagihan *next;
    Tagihan *prev;
};

Tagihan *kepala, *bt, *ini, *nodeBaru, *del, *after;

void buatDobel(string pelanggan, string tanggal, double jumlah) {

    kepala = new Tagihan();
    kepala ->pelanggan = pelanggan;
    kepala ->tanggal = tanggal;
    kepala ->jumlah = jumlah;
    kepala ->prev = NULL;
    kepala ->next = NULL;
    bt = kepala;
}

int hitung() {
        ini = kepala;
        int banyak=0;
    while (ini != NULL)
    {
        banyak++;
        ini = ini->next;
    }
    return banyak;
}

void tambahAwal (string pelanggan, string tanggal, double jumlah){
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        nodeBaru = new Tagihan();
        nodeBaru ->pelanggan = pelanggan;
        nodeBaru ->tanggal= tanggal;
        nodeBaru ->jumlah= jumlah;
        nodeBaru ->prev = NULL;
        nodeBaru ->next = kepala;
        kepala->prev = nodeBaru;
        kepala = nodeBaru;
    }
}

void tambahLast (string pelanggan, string tanggal, double jumlah){
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        nodeBaru = new Tagihan();
        nodeBaru ->pelanggan = pelanggan;
        nodeBaru ->tanggal= tanggal;
        nodeBaru ->jumlah= jumlah;
        nodeBaru ->prev = bt;
        nodeBaru ->next = NULL;
        bt->next = nodeBaru;
        bt = nodeBaru;
    }
}

void tambahTengah(string pelanggan, string tanggal, double jumlah, int posisi){
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else{
        if (posisi == 1)
        {
            cout << "posisi awal bukan posisi tengah" << endl;
        }else if (posisi < 1 || posisi > hitung())
        {
            cout << "posisi ngawur" << endl;
        }else
        {
        nodeBaru = new Tagihan();
        nodeBaru ->pelanggan = pelanggan;
        nodeBaru ->tanggal= tanggal;
        nodeBaru ->jumlah= jumlah;

        //transfersing
        ini = kepala;
        int nomor = 1;
        while (nomor < posisi-1)
        {
            ini = ini ->next;
            nomor++;
        }
            after = ini->next;
            nodeBaru->prev = ini;
            nodeBaru->next = after;
            ini->next = nodeBaru;
            after->prev = nodeBaru;
        }
    }
}

void editAwal (string pelanggan, string tanggal, double jumlah) {
            if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        kepala ->pelanggan = pelanggan;
        kepala ->tanggal= tanggal;
        kepala ->jumlah= jumlah;
}
}

void editLast (string pelanggan, string tanggal, double jumlah) {
                if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        bt ->pelanggan = pelanggan;
        bt ->tanggal= tanggal;
        bt ->jumlah= jumlah;
}
}

void editTengah(string pelanggan, string tanggal, double jumlah, int posisi) {
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else{
        if (posisi == 1)
        {
            cout << "posisi awal bukan posisi tengah" << endl;
        }else if (posisi < 1 || posisi > hitung())
        {
            cout << "posisi ngawur" << endl;
        }else
        {
        nodeBaru = new Tagihan();
        nodeBaru ->pelanggan = pelanggan;
        nodeBaru ->tanggal= tanggal;
        nodeBaru ->jumlah= jumlah;

        //transfersing
        ini = kepala;
        int nomor = 1;
        while (nomor < posisi-1)
        {
            ini = ini ->next;
            nomor++;
        }
        ini ->pelanggan = pelanggan;
        ini ->tanggal= tanggal;
        ini ->jumlah= jumlah;
}
}
}

void hapusAwal(){
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    { del = kepala;
    kepala = kepala->next;
    kepala->prev = NULL;
    delete del;
    }
}

void hapusLast () {
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        del = bt;
        bt = bt->prev;
        bt->next = NULL;
        delete del;
    }
}

void hapusTengah (int posisi) {
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        if ( posisi == 1 || posisi == hitung()) {
            cout << "posisi bukan posisi tengah" << endl;
        } else if (posisi < 1 || posisi > hitung())
        {
            cout << "posisi diluar jangkauan" << endl;
        }else
        {
            int nomor = 1;
            ini = kepala;
            while (nomor < posisi - 1)
            {
                ini = ini -> next;
                nomor++;
            }
            del = ini -> next;
            after = del->next;
            ini ->next = after;
            after ->prev = ini;
            delete del;
        }
    }
}

void cetak() {
    cout << "jumlah datanya pelanggan : " << hitung() << endl;
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        ini = kepala;
    while (ini != NULL)
    {
        cout << "nama pelanggan : " << ini->pelanggan << endl;
        cout << "tanggal transaksi : " << ini->tanggal << endl;
        cout << "jumlah transaksi : " << ini->jumlah << "\n" << endl;
        ini = ini->next;
    }
    }
}
int main () {
buatDobel("Noval", "2 mei 2023", 20.500);
tambahAwal("Bagus", "4 maret 2020", 30000);
editAwal("Gamblok", "15 juni 2000", 35000);
editLast("Denayot", "12 Desember 2010", 15000);
cetak();
// tambahLast("Hilmi", "13 januari", 50000);
// cetak();
// tambahTengah("eko", "11 maret 2010", 100000, 3);
// cetak();
return 0;
}
