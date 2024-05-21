#include <iostream>
using namespace std;

//deklarasi
struct DataUser
{
    string nama, username, email, password;
    DataUser *prev;
    DataUser *next;
};

DataUser *kepala, *bt, *ini, *nodeBaru, *del;

void buatDobel(string data[4]) {

    kepala = new DataUser();
    kepala ->nama = data[0];
    kepala ->username = data[1];
    kepala ->email = data[2];
    kepala ->password = data[3];
    kepala ->prev = NULL;
    kepala ->next = NULL;
    bt = kepala;
}

void cetak() {
    if (kepala == NULL)
    {
        cout << "Double Linkedlist belum dibuat";
    }else
    {
        ini = kepala;
    while (ini != NULL)
    {
        cout << "nama user : " << ini->nama << endl;
        cout << "username user : " << ini->username << endl;
        cout << "email user : " << ini->email << endl;
        cout << "password user : " << ini->password << "\n" << endl;

        ini = ini->next;
    }
    }
}

int main () {

string newData[4] = {"Bagus eko", "bagusganteng", "bagus26@gmail.com", "password123"};
buatDobel(newData);
cetak();

return 0;

}
