#include <iostream>
#include <string.h>
using namespace std;

class node
{
    public:
        int
        noMhs;
        node *next;
};

class singleLinkedlist{
    node *START;

    public:
    singleLinkedlist(){
        START = NULL;
    }

void addnode(){
    int nim;
    cout << "\nMasukan Nomer Mahasiswa : ";
    cin >> nim;

    node *nodebaru = new node;
    nodebaru ->noMhs = nim;

    if (START == NULL || nim <= START ->noMhs)
    {
        if ((START != NULL) && (nim == START ->noMhs)){
            cout << "\nDuplikasi noMhs tidak diijinkan\n";
            return;
        }
        nodebaru -> next= START;
        START= nodebaru;
        return;
    }  
    
    node *previous = START;
    node *current = START;

    while ((current != NULL) && (nim >= current ->noMhs))
    {
        if (nim == current ->noMhs)
        {
            cout << "\nDuplikasi noMhs todak diijinkan\n";
            return;
        }
        previous = current;
        current = current ->next;

        nodebaru ->next = current;
        previous->next =nodebaru;
    }
}

bool listEmpty(){
    return (START == NULL); 
}

bool Search(int nim, node **previous, node **current)
{
    *previous = START;
    *current = (*current)->next;

    while ((*current != NULL) && (nim !=(*current)->noMhs))
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

bool delnode(int nim){
    node *current, *previous;
    if (!Search(nim, &previous, &current))
    return false;

    if (current == START)
    START = START->next;
    else

        previous->next = current->next;
    
    delete current;
    return true;
}

void traverse(){
    if (listEmpty())
    {
        cout << "\nData didalam list adalah : \n";
        node *currentnode = START;
        while (currentnode != NULL)
        {
            cout << currentnode->noMhs << endl;
            currentnode = currentnode->next;
        }
        cout << endl;
    }
}
};

int main(){
    singleLinkedlist mhs;
    int nim;
    char ch;

    while(1)
    {
        cout << endl
             << "MENU";
        cout << endl
             << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data dalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << endl
             << "Masukan piliham (1-5): ";
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            mhs.addnode();
        }
        break;

        case '2':
        { 
            if (mhs.listEmpty())
            {
                cout << endl
                     << "List kosong" << endl;
                break;
            }
            cout << endl
                 << "\nMasukkan no mahasiswa yang akan dihapus : ";
            cin >> nim;
            if (mhs.delnode(nim) == false)
                cout << endl
                     << "Data tidak ditemukan" << endl;
            else
                cout << endl
                     << "Data dengan nomer mahasiswa " << nim << "berhasil dihapus " << endl;

        }
        break;

        case '3':
        {
            mhs.traverse();
        }
        break;

        case '4':
        {
            if (mhs.listEmpty() == true)
            {
                cout << "\nList kosong\n";
                break;
        }
        node *previous, *current;
        cout << endl
             << "Masukkan no mahasiswa yang dicari : ";
        cin >> nim;
        if (mhs.Search(nim, &previous, &current) == false)
            cout << endl
                 << " Data tidak ditemukan" << endl;
                
                 else
                 {
                     cout << endl
                          << "Data ditemukan" << endl;
                     cout << "\nNo Mahasiswa: " << current->noMhs << endl;
                     cout << "\n";
         
                 }
         
                 }
         
             break;
    }
}
}