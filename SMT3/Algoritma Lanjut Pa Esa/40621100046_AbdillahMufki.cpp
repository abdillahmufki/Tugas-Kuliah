#include<stdio.h>
#include<string.h>

// Abdillah Mufki Auzan Mubin - 40621100046 KLS A REG B1

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
	simpul -> data.nim =mhs.nim;
	strcpy(simpul -> data.nama , mhs.nama);
	simpul -> data.ipk =mhs.ipk;
	simpul -> Next = NULL;
	return simpul;
}

void sisiDepan(Mahasiswa mhs);
void sisiBelakang(Mahasiswa mhs);
void sisiTerurut(Mahasiswa mhs);
void tampil();

void inisialisasi(){
	Head = new List;
	Head-> Next = NULL;
	Tail = new List;
	Tail -> Next = NULL;
}
int main (){
	int pilihan;
	Mahasiswa data;
	
	inisialisasi();
	do{
		printf("MENU\n");
		printf("1. Sisip Depan \n");
		printf("2. Sisip Belakang \n");
		printf("3. Sisip Tengah \n");
		printf("4. Hapus Depan \n");
		printf("5. Hapus Belakang \n");
		printf("6. Hapus Tengah \n");
		printf("7. Rata - Rata / min max \n");
		printf("8. Cari Data \n");
		printf("9. Tampil \n");
		printf("0. Keluar \n");
		printf("Pilih Menu = "); scanf("%d",&pilihan);
		switch(pilihan){
			case 1:{
				printf("Masukan NIM = ");  scanf("%d",&data.nim);
				printf("Masukan NAMA = "); scanf("%s",&data.nama);
				printf("Masukan IPK = "); scanf("%f",&data.ipk);
				break;
			}
			case 2:{
			
				break;
			}
			case 3:{
			
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
				printf("Keluar dari");
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
void sisiDepan(Mahasiswa mhs){
	Baru = B(mhs);
	if(Head -> Next == NULL){
		Head -> Next = Baru;
		Tail -> Next = Baru;
	}else{
		Baru -> Next = Head -> Next;
		Head -> Next = Baru;
	}
}
void sisiBelakang(Mahasiswa mhs){
	Baru = B(mhs);
}
void sisiTerurut(Mahasiswa mhs){
	Baru = B(mhs);
}
void tampil(){
	List *pNow = Head -> Next;
	
	printf("NIM\tNAMA\tIPK\n");
	while(pNow != NULL){
		printf("%d\t%s\t%.2f\n",pNow -> data.nim,pNow -> data.nama ,pNow-> data.ipk);
		pNow = pNow -> Next;
	}
	printf("\n");
}
