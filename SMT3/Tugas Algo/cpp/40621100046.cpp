#include<stdio.h>
#include<string.h>
#include <stdlib.h>

using namespace std;

void sisipDepan(int ID, char NAMA[30], int STOK, float HARGA);
void sisipBelakang(int ID, char NAMA[30],int STOK, float HARGA);
void sisipTerurut(int ID, char NAMA[30], int STOK, float harga);
void tampil();
void hapusPosisi(int posisi);
void hapusDepan();
void hapusBelakang();


typedef struct list{
    int id, stok;
	char nama[30];
	float harga;
	struct list *next;
}barang;
barang *Awal = NULL, *Akhir = NULL;
barang *Baru;

int main(){
	int id, stok, pilihan, posisi; 
    char nama[30];
    float harga;
	do{
		printf("Menu\n");
		printf("1. input data depan\n");
		printf("2. input data belakang\n");
		printf("3. input data terurut\n");
		printf("4. hapus posisi\n");
		printf("5. hapus depan\n");
		printf("6. hapus belakang\n");
		printf("99. Tampil\n");
		printf("0. Keluar\n");
		printf("Pilih Menu : "); scanf("%d", &pilihan);
		switch(pilihan){
			case 1 :{
				printf("Masukkan ID : "); scanf("%d", &id);
				printf("Masukkan NAMA : "); scanf("%s", nama);
				printf("Masukkan STOK : "); scanf("%d", &stok);
				printf("Masukkan HARGA : "); scanf("%f", &harga);
				sisipDepan(id, nama, stok,harga);
				break;
			}
			case 2 :{
				printf("Masukkan ID : "); scanf("%d", &id);
				printf("Masukkan NAMA : "); scanf("%s", nama);
				printf("Masukkan STOK : "); scanf("%d", &stok);
				printf("Masukkan HARGA : "); scanf("%f", &harga);
				sisipBelakang(id, nama, stok,harga);
				break;
			}
			case 3 :{
			   	printf("Masukkan ID : "); scanf("%d", &id);
				printf("Masukkan NAMA : "); scanf("%s", nama);
				printf("Masukkan STOK : "); scanf("%d", &stok);
				printf("Masukkan HARGA : "); scanf("%f", &harga);
				sisipTerurut(id, nama, stok,harga);
				break;
			}
            case 4:{
			    printf("Masukkan Posisi : "); scanf("%d", &posisi);
				hapusPosisi(posisi);
			}
            case 5:{
				hapusDepan();
			}
            case 6:{
				hapusBelakang();
			}
			case 99 :{
				tampil();
				break;
			}
			case 0 :{
				break;
			}
		}
//	Baru->next = NULL;
		
}while(pilihan !=0);
	return 0;
}



void sisipDepan(int ID, char NAMA[30], int STOK, float HARGA)
{
	Baru = new barang;
	Baru->id = ID;
	strcpy(Baru->nama, NAMA);
	Baru->stok = STOK;
	Baru->harga = HARGA;
	
	if(Awal == NULL){
		Awal = Baru;
		Akhir = Baru;
		Baru->next = NULL;
		
	}else {
		Baru->next = Awal;
		Awal = Baru;
	}
}
void sisipBelakang(int ID, char NAMA[30], int STOK, float HARGA){
	Baru = new barang;

	Baru->id = ID;
	strcpy(Baru->nama, NAMA);
	Baru->stok = STOK;
	Baru->harga = HARGA;
	
	if(Awal == NULL){
		Awal = Baru;
	}else{
		Akhir->next = Baru;
	}
	Akhir = Baru;
	Baru->next = NULL;
}
void sisipTerurut(int ID, char NAMA[30], int STOK, float HARGA){
	Baru = new barang;

	Baru->id = ID;
	strcpy(Baru->nama, NAMA);
	Baru->stok = STOK;
	Baru->harga = HARGA;
	Baru->next = NULL;
	
	if(Awal == NULL){
		Awal = Baru;
		Akhir = Baru;
	}else{
        barang *pNow = Awal, *temp = Awal;
        while(pNow->id < Baru->id && pNow->next != NULL){
            temp = pNow;
            pNow = pNow->next;
        }

        if(pNow->id > Baru->id && pNow == temp){
            Baru->next = Awal;
		    Akhir = Baru;
        }else{
            Baru->next = temp->next;
            temp->next = Baru;
        }
	}
}

void tampil(){
	barang *pNow = Awal;
	printf("ID NAMA STOK HARGA\n");
	while(pNow != NULL){
		printf("%d %s %d %.2f\n", pNow->id, pNow->nama, pNow->stok, pNow->harga);
		pNow = pNow->next;
	}
}

void hapusPosisi(int posisi)
{
    barang *pNow = Awal, *temp = Awal;
	if(pNow != NULL){
		for (int i = 0; i < posisi; i++) {
			if (i == 0 && posisi == 1) {
				Awal = (Awal)->next;
				free(pNow);
			}
			else {
				if (i == posisi - 1 && pNow) {
					temp->next = pNow->next;
					free(pNow);
				}
				else {
					temp = pNow;
					if (temp == NULL)
						break;
					pNow = pNow->next;
				}
			}
		}
	}else{
		printf("List Kosong !!\n");
	}
}

void hapusDepan(){
	barang *pNow = Awal;
	Awal = (Awal)->next;
    free(pNow);

}
void hapusBelakang(){
    barang *pNow = Awal, *temp = Awal;

    //first check if firstNode is NULL or last node.
    if(pNow == NULL)
        printf("List Kosong !!\n");

    if(pNow->next == NULL){
        free(pNow);
        pNow = NULL;
        return;
    }
    while (temp->next && temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
