#include <iostream>

using namespace std;

struct Buku
{
    string judul, pengarang;
    int thn;

    Buku *next;
};

Buku *kepala, *bt, *ini, *nodeBaru, *busek, *before;

void ngisiLinkedlist (string judul, string pengarang, int thn) {
    kepala = new Buku();
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->thn = thn;
    kepala->next = NULL;
    bt = kepala;    
}

int hitungSingle(){
    ini = kepala;
    int jumlah = 0;
    while (ini != NULL)
    {
    jumlah++;
    ini = ini->next;
    }
    return jumlah;
}

void tambahAwal (string judul, string pengarang, int thn) {
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;
    nodeBaru->next = kepala;
    kepala = nodeBaru;
}

void tambahTengah (string judul, string pengarang, int thn, int posisi) {
    if (posisi < 1 || posisi > hitungSingle() ) {
        cout << "posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == hitungSingle() ) {
        cout << "bukan posisi tengah" << endl;
    }
    else {
        nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;

    ini = kepala;
    int nomor = 1;
    while (nomor < posisi - 1) {
        ini = ini -> next;
        nomor++;
    }
    nodeBaru ->next = ini -> next;
    ini -> next = nodeBaru;
    }
}

void tambahGuri (string judul, string pengarang, int thn) {
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;
    nodeBaru->next = NULL;
    bt->next = nodeBaru;
    bt = nodeBaru;
}

void ubahAwal (string judul, string pengarang, int thn) {
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->thn = thn;
}
void ubahLast (string judul, string pengarang, int thn) {
    bt->judul = judul;
    bt->pengarang = pengarang;
    bt->thn = thn;
}
void ubahTengah (string judul, string pengarang, int thn, int posisi) {
    if (posisi < 1 || posisi > hitungSingle() ) {
        cout << "posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == hitungSingle() ) {
        cout << "bukan posisi tengah" << endl;
    }
    else {
    ini = kepala;
    int nomor = 1;
    while (nomor < posisi)
    {
        ini = ini->next;
        nomor++;
    }
    ini->judul = judul;
    ini->pengarang = pengarang;
    ini->thn = thn;
    }
}

void hapusAwal () {
    busek = kepala;
    kepala = kepala->next;
    delete busek;
}

void hapusTengah (int posisi) {
    if (posisi < 1 || posisi > hitungSingle() ) {
        cout << "posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == hitungSingle() ) {
        cout << "bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
    ini = kepala;
    while (nomor <= posisi)
    {
        if (nomor == posisi - 1)
        {
            before = ini;
        }
        if (nomor == posisi)
        {
            busek = ini;
        }
        ini = ini -> next;
        nomor++;
    }
    before ->next = ini;
    delete busek;
    }
}

void hapusLast () {
    busek = bt;
    ini = kepala;
    while (ini->next != bt)
    {
        ini = ini->next;
    }
    bt = ini;
    bt->next = NULL;
    delete busek;  
}

void cetakLinkedlist(){
    cout << "jumlah data : " << hitungSingle() << endl;
    ini = kepala;
    while (ini != NULL)
    {
        cout << "Judul Buku : " << ini->judul << endl;
        cout << "Pengarang Buku : " << ini->pengarang << endl;
        cout << "Tahun terbit Buku : " << ini->thn << endl;
        cout << endl;
    ini = ini->next;
    }

}
    
int main () {
 ngisiLinkedlist("Ngoding", "bagus", 2025);
 tambahAwal("Mancing", "eko", 2033);
 tambahGuri("Sekolah", "wijayanto", 2021);
//  hapusAwal();
//  hapusLast();
 ubahAwal("Senja pagi buta", "uden", 1923);
 ubahLast("Fajar sore itu", "hilmi", 2000);
 tambahTengah("hp baru", "nopal", 2000, 2);
 tambahTengah("laptop baru", "giska", 2005, 3);
 ubahTengah("Hari itu", "jarwo", 2021, 3);
 hapusTengah(1);
 cetakLinkedlist();

 return 0;
}
