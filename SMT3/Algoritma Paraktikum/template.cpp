#include<stdio.h>
#include<string.h>

typedef struct{
	int nim;
	char nama[255];
	float ipk;	
}Mahasiswa;

typedef struct Simpul{
	Mahasiswa data;
	struct Simpul *Next;	
}List;

List *Head, *Tail, *Baru;

List *B(Mahasiswa mhs){
	List *simpul = new List;
	simpul->data.nim = mhs. nim;
	strcpy(simpul->data.nama, mhs. nama);
	simpul->data.ipk = mhs. ipk;
	simpul->Next = NULL;
	return simpul;
}

void sisipDepan(Mahasiswa mhs);
void sisipBelakang(Mahasiswa mhs);
void sisipTerurut(Mahasiswa mhs);
void tampil();

void inisialisasi(){
	Head = new List;
	Head->Next = NULL;
	Tail = new List;
	Tail->Next = NULL;
}

int main (){
	int pilihan;
	Mahasiswa data;
	
	do{
		printf("MENU\n");
		printf("1. Sisip Depan \n");
		printf("2. Sisip Belakang \n");
		printf("3. Sisip Terurut \n");
		printf("4. Hapus Depan \n");
		printf("5. Hapus Belakang \n");
		printf("6. Hapus Terurut \n");
		printf("7. Rata - Rata / min max \n");
		printf("8. Cari Data \n");
		printf("9. Tampil \n");
		printf("0. Keluar \n");
		printf("Pilih Menu = "); scanf("%d",&pilihan);
		switch(pilihan){
			case 1:{
				printf("Masukkan NIM = "); scanf("%d", &data.nim);
				printf("Masukkan NAMA = "); scanf("%s", &data.nama);
				printf("Masukkan IPK = "); scanf("%f", &data.ipk);
				sisipDepan(data);
				break;
			}
			case 2:{
				printf("Masukkan NIM = "); scanf("%d", &data.nim);
				printf("Masukkan NAMA = "); scanf("%s", &data.nama);
				printf("Masukkan IPK = "); scanf("%f", &data.ipk);
				sisipBelakang(data);
				break;
			}
			case 3:{
				printf("Masukkan NIM = "); scanf("%d", &data.nim);
				printf("Masukkan NAMA = "); scanf("%s", &data.nama);
				printf("Masukkan IPK = "); scanf("%f", &data.ipk);
				sisipTerurut(data);
				break;
			}
			case 4:{
			
				break;
			}
			case 5:{
			
				break;
			}
			case 6:{
			
				break;
			}
			case 7:{
			
				break;
			}
			case 8:{
			
				break;
			}
			case 9:{
				tampil();
				break;
			}
			case 0:{
	
				break;
			}
			default : {
				printf("Pilihan salah\n");
				break;
			}
		}
	} while(pilihan != 0);
	
	return 0;
}


void sisipDepan(Mahasiswa mhs){
	Baru = B(mhs);
	
	if(Head->Next == NULL){
		Head->Next = Baru;
		Tail->Next = Baru;
	}else{
		Baru->Next = Head->Next;
		
		Head->Next = Baru;
	}
}
void sisipBelakang(Mahasiswa mhs){
	Baru = B(mhs);
	
	if(Head->Next == NULL){
		Head->Next = Baru;
		Tail->Next = Baru;
	}else{
		(Tail->Next)->Next = Baru;
		Tail->Next = Baru;
	}
}
void sisipTerurut(Mahasiswa mhs){
	Baru = B(mhs);
	
	if(Head->Next == NULL){
		Head->Next = Baru;
		Tail->Next = Baru;
	}else{
		List *pNow = Head->Next, *temp = Head->Next;
		
		while(pNow != NULL && pNow->data.nim < mhs.nim){
			temp = pNow;
			pNow = pNow->Next;
		}
		
		if(pNow == temp){
			Baru->Next = Head->Next;
			Head->Next = Baru;
		}else{
		Baru->Next = pNow;
			temp->Next = Baru;
			if(Tail->Next == temp){
			Tail->Next = Baru;
			}
		}
	}
}
void tampil(){
	List *pNow = Head->Next;
	
	printf("NIM\tNAMA\tIPK\n");
	while(pNow != NULL){
		printf("%d\t%s\t%.2f\n", pNow->data.nim, pNow->data.nama, pNow->data.ipk);
		pNow = pNow->Next;
	}
	printf("\n");
}
