#include<stdio.h>

//tipe bentukan
typedef struct
{
    int nim;
    char nama[255];
    float ipk;
} mahasiswa;

typedef struct list{
    //data
    mahasiswa data;
    struct list *Next;
}queue;
queue *depan = NULL, *belakang = NULL;

void addq(mahasiswa data){
    queue *baru = new queue;
    baru->data = data;
    baru->Next = NULL;

    if (depan == NULL){
        depan = baru;
    }else {
        belakang->Next = baru;
    }
    belakang = baru;
}
void deleteq(){
    if(depan == belakang){
        belakang = belakang->Next;
    }
    depan = depan->Next;
}

void tampil(){
    queue *pNow = depan;
    if(pNow == NULL) {
        printf("Data kosong\n");
    } else {
        printf("NIM NAMA IPK\n");
        while(pNow != NULL){
            printf("%d %s %.2f\n", pNow->data.nim, pNow->data.nama, pNow->data.ipk);
            pNow = pNow->Next;
        }
    }
}

int main () {
    char pilihan;
    mahasiswa mhs;

    do{
        printf("Masukan NIM = "); scanf("%d", &mhs.nim);
        printf("Masukan NAMA = ");scanf("%s", mhs.nama);
        printf("Masukan IPK = ");scanf("%f", &mhs.ipk);
        addq(mhs);

        printf("Masukan Data lagi? (y/t)");
        fflush(stdin); scanf("%c", &pilihan);

    } while (pilihan == 'y' || pilihan == 'Y');
    tampil();
    deleteq();
    tampil();

    return 0;
}
