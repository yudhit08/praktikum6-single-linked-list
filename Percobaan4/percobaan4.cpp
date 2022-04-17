#include <iostream>
#include <conio.h>

using namespace std;

struct Node
{
    string nama;
    int nrp;
    Node *next;
};

Node *head, *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    if (tail == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void insertData(string Nama, int NRP)
{
    Node *baru;
    baru = new Node;
    baru->nama = Nama;
    baru->nrp = NRP;
    baru->next = NULL;
    if (isEmpty() == 1)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = baru;
    }
    cout << "Data masuk...\n";
}

void Hapus(string Nama)
{
    Node *hapus = head;
    Node *cur;
    if(hapus->nama == Nama)
        head = hapus->next;
    else{
        while (hapus->nama != Nama)
        {
            cur = hapus;
            hapus = hapus->next;
        }
        cur->next = hapus->next;
    }
}

void sisipSetelah(string curName, string Nama, int NRP)
{
    Node *sisip;
    sisip = new Node;
    Node *cari = head;
    while (cari->nama != curName)
    {
        cari = cari->next;
    }
    sisip->nama = Nama;
    sisip->nrp = NRP;
    sisip->next = cari->next;
    cari->next = sisip;
}

void sisipSebelum(string curName, string Nama, int NRP)
{
    Node *baru, *stl;
    Node *cari = head;
    baru = new Node;
    stl = new Node;
    if (cari->nama == curName)
    {
        baru->next = head;
        head = baru;
    }
    else{
        while (cari->nama != curName)
        {
            stl = cari;
            cari = cari->next;
        }
        baru->next = cari;
    }
    baru->nama = Nama;
    baru->nrp = NRP;
    stl->next = baru;    
}

void tampil()
{
    cout << "\nData yang ada di list saat ini : " << endl;
    Node *bantu;
    bantu = head;
    if (isEmpty() == 0)
    {
        while (bantu != NULL)
        {
            cout << "--> Nama Mahasiswa : " << bantu->nama << endl;
            cout << "--> NRP            : " << bantu->nrp << endl
                 << endl;
            bantu = bantu->next;
        }
    }
    else
        cout << "Masih kosong\n";
}

int main()
{
    system("clear");

    string Nama, curNama;
    int NRP, pil;
    char lagi;

    cout << "Input data" << endl
         << endl;
    while (true)
    {
        cout << "Nama   : ";
        cin >> Nama;
        cout << "NRP    : ";
        cin >> NRP;
        insertData(Nama, NRP);
        cout << "\nIngin masukkan data lagi(y/n) : ";
        cin >> lagi;
        if (lagi != 'y' && lagi != 'Y')
        {
            break;
        }
    }

    system("clear");

    tampil();
    while (true)
    {
        cout << endl;
        cout << " ============================" << endl;
        cout << " =   PROGRAM LINKED LIST    =" << endl;
        cout << " ============================" << endl;
        cout << " = 1. Hapus Data Tertentu   =" << endl;
        cout << " = 2. Menyisipkan Setelah   =" << endl;
        cout << " = 3. Menyisipkan Sebelum   =" << endl;
        cout << " = 4. Tampil Data           =" << endl;
        cout << " = 5. Exit                  =" << endl;
        cout << " ============================" << endl;
        cout << " Masukan Pilihan : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            system("clear");
            {
                tampil();
                cout << "Masukkan nama yang akan dihapus : " << endl;
                cout << "=> ";
                cin >> Nama;
                Hapus(Nama);
                tampil();
                break;
            }
        case 2:
            system("clear");
            {
                tampil();
                cout << "Masukkan nama yang akan disisipkan data setelahnya " << endl;
                cout << "=> ";
                cin >> curNama;

                cout << "\nInsert data..." << endl;

                cout << "Masukkan Nama : ";
                cin >> Nama;
                cout << "Masukkan NRP  : ";
                cin >> NRP;
                sisipSetelah(curNama, Nama, NRP);
                tampil();
                break;
            }
        case 3:
            system("clear");
            {
                tampil();
                cout << "Masukkan nama yang akan disisipkan data sebelumnya " << endl;
                cout << "=> ";
                cin >> curNama;

                cout << "\nInsert data..." << endl;

                cout << "Masukkan Nama : ";
                cin >> Nama;
                cout << "Masukkan NRP  : ";
                cin >> NRP;
                sisipSebelum(curNama, Nama, NRP);
                tampil();
                break;
            }
        case 4:
            system("clear");
            {
                cout << "Tampilkan semua data : \n";
                tampil();
                break;
            }
        case 5:
            {
                cout << "\n Terima Kasih!\n";
                exit(0);
                break;
            }
        default:
            system("clear");
            {
                cout << "Pilihan anda tidak tersedia..." << endl;
                break;
            }
        }
        getch();
    }
}