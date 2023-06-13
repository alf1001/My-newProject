#include <iostream>
using namespace std;

struct BankUsers{
    string nama,keperluan;
    BankUsers *prev;
    BankUsers *next;
};
BankUsers *head,*tail,*cur,*newNode,*del;

void createNewNode(string nama,string keperluan){
    head = new BankUsers();
    head->nama = nama;
    head->keperluan = keperluan;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}
void addLast(string nama,string keperluan){
    if(head == NULL){
        createNewNode(nama,keperluan);
    }else{
        newNode = new BankUsers();
        newNode->nama = nama;
        newNode->keperluan = keperluan;
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

void delFirst(){
    if (head == nullptr) {
        cout << "Antrian kosong" << endl;
     } else {
        del = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = NULL;
        }
        delete del;
     }
}

void print(){
    if(head == NULL){
        cout << "List kosong" << endl;
    }else{
        cur = head;
        while(cur != NULL){
        cout << "Nama nasabah : " << cur->nama<<endl;
        cout << "Keperluan(Nabung/Konsultasi) : " << cur->keperluan<<endl;
        //step
        cur = cur->next;
     }
    }
}

int main(){
    int opsi;
    string milih,nama,keperluan,pilih;
    do{
        cout<<"\n ================================================"<<endl;
        cout<<" ||         Selamat Datang di Bank Wati          ||"<<endl;
        cout<<"\n ================================================"<<endl;
        cout<<" ||"<<"  1.Ambil Antrian                         "<<"||"<<endl;
        cout<<" ||"<<"  2.Memanggil Antrian                     "<<"||"<<endl;
        cout<<" ||"<<"  3.Lihat Antrian                         "<<"||"<<endl;
        cout<<" ||"<<"  4.Keluar                                "<<"||"<<endl;
        cout<<"\n ================================================"<<endl;
        cout<<" Masukkan Pilihan Anda : ";
        cin>>opsi;
        switch(opsi){
            case 1:
                cout<<" Nama nasabah : ";
                cin>>nama;
                cout<<" Keperluan(nabung/konsultasi) : ";
                cin>>keperluan;
                addLast(nama,keperluan);
                cout<<"\nApakah ingin mengulangi (y/n)?";
                cin>>pilih;
                break;
            case 2:
                delFirst();
                cout<<"Antrian pertama sudah di panggil";
                cout<<"\nApakah ingin mengulangi (y/n)?";
                cin>>pilih;
                break;
            case 3:
                print();
                cout<<"\nApakah ingin mengulangi (y/n)?";
                cin>>pilih;
                break;
            case 4:
                break;
        }
    }while(pilih == "y" || pilih == "Y" && opsi!=4);
}
