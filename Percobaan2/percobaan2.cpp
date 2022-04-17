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

    string Nama, curName;
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
    cout << "\tMENYISIPKAN DATA SETELAH SIMPUL TERTENTU" << endl;
    cout << "=======================================" << endl
         << endl;

    cout << "Data yang ada di list saat ini : " << endl;
    tampil();

    cout << "Masukkan nama yang ingin disisipkan data setelahnya" << endl;
    cout << "=> ";
    cin >> curName;

    cout << "\nInsert data..." << endl;

    cout << "Nama   : ";
    cin >> Nama;
    cout << "NRP    : ";
    cin >> NRP;
    sisipSetelah(curName, Nama, NRP);

    cout << "\nData yang ada di list saat ini : " << endl;
    tampil();
}