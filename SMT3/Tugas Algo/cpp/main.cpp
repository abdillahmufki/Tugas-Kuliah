#include <iostream>
#include <stdlib.h>
#include <string.h>
 
using namespace std;
 
typedef int typeinfo;
typedef struct typenode *typeptr;
struct typenode {
    typeinfo info;
    typeptr next;
};
 
typeptr awal, akhir;
void buatlistbaru();
void sisipdepan(typeinfo IB);
void sisipbelakang(typeinfo IB);
void sisiptengah(typeinfo IB);
void hapusnode(typeinfo IH);
void cetaklist();
 
int main (){
    typeinfo angka,pilih;
    char ulangi = 'y';
   
    cout << "\n------------ Program Single Linked List ------------\n\n";
   
    buatlistbaru();
 
    while(ulangi == 'y'){
       
        cout << "1. Menyisipkan Depan\n";
        cout << "2. Menyisipkan Belakang\n";
        cout << "3. Menyisipkan Tengah\n";
        cout << "4. Hapus Node\n";
        cout << "Pilih Penyisipan : ";
        cin >> pilih;
        cout << endl;
        switch (pilih){
            case 1 :
            cout << "Masukkan NIM : ";
            cin >> angka;
            cout << "Masukkan NAMA : ";
            cin >> angka;
            cout << "Masukkan IPK : ";
            cin >> angka;
            sisipdepan(angka);
            break;
 
            case 2 :
            cout << "Menyisipkan Belakang : ";
            cin >> angka;
            sisipbelakang(angka);
            break;
 
            case 3 :
            cout << "Menyisipkan Tengah : ";
            cin >> angka;
            sisiptengah(angka);
            break;
 
            case 4 :
            cout << "Hapus Node : ";
            cin >> angka;
            hapusnode(angka);
            break;
 
        }
       
        cout << endl;
        cetaklist();
        cout << endl;
        cout << endl;
        cout << "Apakah kamu mau mengulang?" << endl;
        cout << "Jawab (y/n) : ";
        cin >> ulangi;
        cout << endl;
 
    }
   
    cin.get();
    return 0;
}
 
void buatlistbaru(){
    typeptr list;
    list = (typenode *) malloc(sizeof(typenode));
    list = NULL;
    awal = list;
    akhir = list;
}
 
void sisipdepan (typeinfo IB){
    typeptr NB;
    NB = (typenode *) malloc(sizeof(typenode));
    NB ->info = IB;
    if(awal == NULL){
        awal = NB;
        akhir = NB;
        awal->next = NULL;
    }else {
        NB->next = awal;
    }
    awal = NB;
}
 
void sisipbelakang (typeinfo IB){
    typeptr NB;
    NB = (typenode *) malloc(sizeof(typenode));
    NB->info = IB;
    if(awal == NULL){
        awal = NB;
        akhir = NB;
    }else {
        akhir->next = NB;
        akhir = NB;
    }
    akhir->next = NULL;
}
 
void sisiptengah(typeinfo IB){
    typeptr NB, bantu;
    NB = (typenode *) malloc(sizeof(typenode));
    NB->info = IB;
    NB->next = NULL;
 
    if (awal == NULL) {
         awal = NB;
        akhir = NB;
        }
    else {
        bantu = awal;
        while ((IB > bantu->next->info) && (bantu->next!=NULL)){
        bantu = bantu->next;
        NB->next = bantu->next;
        bantu->next = NB;
        }
    }
}
 
void hapusnode(typeinfo IH){
    typeptr hapus, bantu;
    if (awal == NULL){
    cout << "List masih kosong!\n";
    }
    else {
        if (awal->info == IH){  /* hapus awal list */
            hapus = awal;
            awal = hapus->next;
            free(hapus); /*hapus node nya */
        }
        else {
            bantu = awal; /* cari list yang akan dihapus */
            while ((bantu->next->info!=IH) && (bantu->next!=NULL)){
                bantu = bantu->next;}
                hapus = bantu->next;
            if (hapus == NULL){
                cout << "List tidak ditemukan\n";
            }
            else{
                if (hapus == akhir){ /* hapus akhir list */
                akhir = bantu;
                akhir->next=NULL;
                }
                else{ /* hapus list ditengah */
                bantu->next = hapus->next;
                }
                free(hapus); /*hapus node nya */
                }
            }
        }
}
 
void cetaklist(){
    typeptr bantu;
    bantu = awal;
    cout << "|";
    while (bantu!=NULL){
        cout << " ";
        cout << bantu->info;
        cout << " ";
        cout << "|";
        bantu = bantu->next;
    }
}
