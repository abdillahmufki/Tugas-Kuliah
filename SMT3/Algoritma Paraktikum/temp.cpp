#include<stdio.h>
#include<string.h>

typedef struct{
	int nim;
	char nama[255];
	float ipk;	
}mahasiswa;

typedef struct simpul{
	mahasiswa data;
	struct simpul *Next;	
}List;

List *Head, *Baru;

List *NewList(mahasiswa data){
	List *BARU = new List;
	BARU->data.nim = data.nim;
	strcpy(BARU->data.nama, data.nama);
	BARU->data.ipk = data.ipk;
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
	Head->Next = NULL;
}

int main (){
	int pilihan;
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
				printf("Masukkan Nim Yang Ingin Dihapus =  "); scanf("%d,&nim");
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
	Baru = NewList(data);
	
	if(Head->Next == NULL){//inout pertama kali
		Head->Next = Baru;
		Baru->Next = Head->Next;
	}else{//input didepan
		List *pNow = Head->Next;
		while(pNow->Next != Head->Next){
			pNow = pNow->Next;
		}
		Baru->Next = Head->Next;
		Head->Next = Baru;
		pNow->Next = Baru;
	}
}

void SisipBelakang(mahasiswa data){
	Baru = NewList(data);
	
	if(Head->Next == NULL){//inout pertama kali
		Head->Next = Baru;
	}else{//input didepan
		List *pNow = Head->Next;
		while(pNow->Next != Head->Next){
		pNow = pNow->Next;
		}
		pNow->Next = Baru;
	}
		Baru->Next = Head->Next;
}

void SisipTerurut(mahasiswa data){
	Baru = NewList(data);
	
	if(Head->Next == NULL){//inout pertama kali
		Head->Next = Baru;
		Baru->Next = Head->Next;
	}else{//input didepan
		List *pNow = Head->Next, *temp = Head->Next;
		
		do{
			if(pNow->data.nim < Baru->data.nim){
				temp = pNow;
			pNow = pNow->Next;
			}else{
				break;
			}
		}while(pNow != Head->Next);	
		
		if(pNow == temp){
			while(pNow->Next != Head->Next){
				pNow = pNow->Next;
		}
		Baru->Next = Head->Next;
		Head->Next = Baru;
		pNow->Next = Baru;
		
	}else{
		Baru->Next = pNow;
		temp->Next = Baru;
		}
	}	
}

void Tampil(){
	List *pNow = Head->Next;
	
	if(Head->Next == NULL){
		printf("Data Masih Kosong\n");
	}else{
		printf("NIM\tNAMA\tIPK\n");
		do{
			printf("%d\t%s\t%2.f\n",pNow->data.nim, pNow->data.nama, pNow->data.ipk);
			pNow = pNow->Next;	
		}while(pNow != Head->Next );
		printf("\n");	
	}
}

void HapusDepan(){
	List *pNow = Head->Next, *Hapus = Head->Next;
	
	if(Hapus->Next == Head->Next){
		Head->Next = NULL;
		Hapus->Next = NULL;

	}else{
	while(pNow->Next != Head->Next){
		pNow= pNow->Next;
	}
	Head->Next = Hapus->Next;
	pNow->Next = Hapus->Next;
	Hapus->Next = NULL;
	}
}

void HapusBelakang(){
	List *pNow = Head->Next, *Hapus = Head->Next;
	
	if(Hapus->Next == Head->Next){
		Head->Next = NULL;
		Hapus->Next = NULL;

	}else{
		while(Hapus->Next != Head->Next){
			pNow = Hapus;
			Hapus = Hapus->Next;
		}
		pNow->Next = Head->Next;
		Hapus->Next = NULL;
	}
}

void HapusCari(int data){
	List *pNow = Head->Next, *Hapus = Head->Next;
	
	while(Hapus->Next != Head->Next && Hapus->data.nim != data){
		pNow = Hapus;
		Hapus = Hapus->Next;
	}
	
	if(Hapus->data.nim != data){
		printf("Data Tidak Ditemukan\n");
	}else if(pNow == Hapus){
		if(Hapus->Next == Head->Next){
			Head->Next = NULL;
		}else{
			while(pNow->Next != Head->Next){
				pNow = pNow->Next;
			}
			Head->Next = Hapus->Next;
			pNow->Next = Hapus->Next;
		}
	}else{
		pNow->Next = Hapus->Next;
	}
	Hapus->Next = NULL;
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

void SearchData(int NIM){
	List *pNow = Head->Next;
	bool notExist = true;
	while(pNow->Next != Head->Next){
		printf("cek"); 
		if(pNow->data.nim == NIM){
			printf("NIM\tNAMA\tIPK\n");
			printf("%d\t%s\t%2.f\n",pNow->data.nim, pNow->data.nama, pNow->data.ipk);
			notExist = false;
			break;
		}
		pNow = pNow->Next;
	}
	if(notExist){
		printf("Data tidak ditemukan\n");
	}
}
	












































