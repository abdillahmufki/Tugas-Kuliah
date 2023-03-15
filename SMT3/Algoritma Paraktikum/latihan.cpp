#include<stdio.h>
#include<string.h>

typedef struct{
	int nim;
	char nama[255];
	float ipk;	
}mahasiswa;

typedef struct simpul{
	mahasiswa data;
	struct simpul *Back;
	struct simpul *Next;	
}List;

List *Head;

List *NewList(mahasiswa data){
	List *BARU = new List;
	BARU->data = data;
	BARU->Back = NULL;
	BARU->Next = NULL;
	return BARU;
}

mahasiswa InputData(){
	mahasiswa data;
	printf("Masukkan NIM = "); scanf("%d", &data.nim);
	printf("Masukkan NAMA = "); fflush(stdin); gets(data.nama);
	printf("Masukkan IPK = "); scanf("%f", &data.ipk);
	return data;
}

void SisipDepan(mahasiswa data);
void SisipBelakang(mahasiswa data);
void SisipTerurut(mahasiswa data);
void HapusDepan();
void HapusBelakang();
void HapusCari(int data);
void Avarage();
void SearchData(int NIM);
void Tampil();

void inisialisasi(){
	Head = new List;
	Head->Back = NULL;
	Head->Next = NULL;
}

int main (){
	int pilihan, nim;
	mahasiswa mhs;
	inisialisasi();
	
	
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
				mhs = InputData();
				SisipDepan(mhs);
				break;
			}
			case 2:{
				mhs = InputData();
				SisipBelakang(mhs);
				break;
			}
			case 3:{
				mhs = InputData();
				SisipTerurut(mhs);
				break;
			}
			case 4:{
				HapusDepan();
				break;
			}
			case 5:{
				HapusBelakang();
				break;
			}
			case 6:{
				int nim;
				printf("Masukkan Nim Yang Ingin Dihapus =  "); scanf("%d", &nim);
				HapusCari(nim);
				break;
			}
			case 7:{
				Avarage();
				break;
			}
			case 8:{
				int nim;
				printf("Masukkan Nim Yang Ingin Dicari =  "); scanf("%d,&nim");
				SearchData(nim);
				break;
			}
			case 9:{
				Tampil();
				break;
			}
			case 0:{
				printf("Keluar dari program\n");
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

void SisipDepan(mahasiswa data){
	List *Baru = NewList(data);
	
	if(Head->Next == NULL){
		Head->Next = Baru;
		Head->Back = Baru;
		Baru->Next = Head;
		Baru->Back = Head;
	}else {
		Baru->Next = Head->Next;
		Baru->Back = Head;
		(Head->Next)->Back = Baru;
		Head->Next = Baru;
	}
}

void SisipBelakang(mahasiswa data){
List *Baru = NewList(data);
	
	if(Head->Next == NULL){
		Head->Next = Baru;
		Head->Back = Baru;
		Baru->Next = Head;
		Baru->Back = Head;
	}else {
		Baru->Next = Head;
		Baru->Back = Head->Back;
		(Head->Back)->Next = Baru;
		Head->Back = Baru;
	}
}

void SisipTerurut(mahasiswa data){
	List *Baru = NewList(data);
	
	if(Head->Next == NULL){
		Head->Next = Baru;
		Head->Back = Baru;
		Baru->Next = Head;
		Baru->Back = Head;
	}else {
		List *pNow = Head->Next;
		while(pNow != Head && pNow->data.nim < Baru->data.nim){
			pNow = pNow->Next;
		}
		Baru->Next = pNow;
		Baru->Back = pNow->Back;
		(pNow->Next)->Next = Baru;
		pNow->Back = Baru;
	}

void Tampil(){
	if(Head->Next == NULL){
		printf("Data Masih Kosong\n\n");
	}else{
		List *pNow = Head->Next;
		
		printf("NIM\tNAMA\tIPK\n");
		while
			printf("%d\t%s\t%2.f\n",pNow->data.nim, pNow->data.nama, pNow->data.ipk);
			pNow = pNow->Next;	
		}	
	}


void HapusDepan(){
	List *Hapus = Head->Next;
	
	if(Hapus->Next == Head){
		Head->Next = NULL;
		Head->Back = NULL;
	}else{
		Head->Next = Hapus->Next;
		(Hapus->Next)->Back = Head;
	}
	Hapus->Next = NULL;
	Hapus->Back = NULL;
	}
}

void HapusBelakang(){
	List *Hapus = Head->Back;
		
		if(Hapus->Next == Head){
		Head->Next = NULL;
		Head->Back = NULL;
	}else {
		Head->Back = Hapus->Back;
		(Hapus->Back)->Next = Head;
	}
	Hapus->Next = NULL;
	Hapus->Back = NULL;
}

void HapusCari(int data){
	List *Hapus = Head->Next;
	
	while(Hapus != Head && Hapus->data.nim != NIM){
		Hapus = Hapus->Next;
	}
	if(Head == Hapus){
		printf("Nim Tidak Dtemukan");
	}else{
		(Hapus->Back)->Next = Hapus->Next;
		(Hapus->Next)->Back = Hapus->Back;
	
		Hapus->Next = NULL;
		Hapus->Back = NULL;
	}
	
}

void Avarage(){
	List *pNow = Head->Next;
	float total = 0;
	int cnt = 0;
	
	while(pNow->Next != Head->Next){
		total += pNow->data.ipk;
		pNow = pNow->Next;
		cnt++;
	}
	if(total > 0){
		float avarage = total/cnt;
		printf("Rata rata nya adalah %f\n",avarage);
	}else{
		printf("Data belum tersedia\n");
	}
}

	












































