#include <iostream>

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

void tampil()
{
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

    string Nama;
    int NRP;
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

    cout << "=======================================" << endl;
    cout << "\tMENGHAPUS SIMPUL TERTENTU" << endl;
    cout << "=======================================" << endl
         << endl;

    cout << "Data yang ada di list saat ini : " << endl;
    tampil();

    cout << "Masukkan nama yang ingin di hapus dari daftar" << endl;
    cout << "=> ";
    cin >> Nama;
    Hapus(Nama);

    cout << "\nData yang ada di list saat ini : " << endl;
    tampil();
}