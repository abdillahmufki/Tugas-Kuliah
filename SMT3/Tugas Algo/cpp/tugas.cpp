#include <stdio.h>
#include <string.h>

typedef struct list
{
    int nim;
    char nama[255];
    float ipk;
    struct list *next;
} mahasiswa;
mahasiswa *Awal = NULL, *Akhir = NULL;
mahasiswa *Baru;
struct list*del(struct list *Awal, int nim, char nama[255], float ipk);

void sisipDepan(int NIM, char NAMA[255], float IPK)
{
    Baru = new mahasiswa;
    Baru->nim = NIM;
    strcpy(Baru->nama, NAMA);
    Baru->ipk = IPK;

    if (Awal == NULL)
    {
        Awal = Baru;
        Akhir = Baru;
        Baru->next = NULL;
    }
    else
    {
        Baru->next = Awal;
        Awal = Baru;
    }
}
void sisipBelakang(int NIM, char NAMA[255], float IPK)
{
    Baru = new mahasiswa;
    Baru->nim = NIM;
    strcpy(Baru->nama, NAMA);
    Baru->ipk = IPK;

    if (Awal == NULL)
    {
        Awal = Baru;
    }
    else
    {
        Akhir->next = Baru;
    }
    Akhir = Baru;
    Baru->next = NULL;
}

void sisipTerurut(int NIM, char NAMA[255], float IPK)
{
    Baru = new mahasiswa;
    Baru->nim = NIM;
    strcpy(Baru->nama, NAMA);
    Baru->ipk = IPK;
    Baru->next = NULL;

    if (Awal == NULL)
    {
        Awal = Baru;
        Akhir = Baru;
    }
    else
    {
        mahasiswa *pNow = Awal, *temp = Awal;

        while (pNow->nim < Baru->nim && pNow->next != NULL)
        {
            temp = pNow;
            pNow = pNow->next;
        }

        if (pNow->nim > Baru->nim && pNow == temp)
        {
            Baru->next = Awal;
            Awal = Baru;
        }
        else
        {
            Baru->next = temp->next;
            temp->next = Baru;
        }
    }
}
struct list *del(struct list*Awal, int nim);
{
	struct list*temp, Awal*;
		if(Awal==NULL)
		{
			printf("List is empty\n");
			return Awal;
		}
}
void tampil()
{
    mahasiswa *pNow = Awal;
    printf("NIM NAMA IPK\n");
    while (pNow != NULL)
    {
        printf("%d %s %.2f\n", pNow->nim, pNow->nama, pNow->ipk);
        pNow = pNow->next;
    }
}
int main()
{
    int nim;
    char nama[255];
    float ipk;
    int pilihan;
    do
    {
        printf("Menu\n");
        printf("1. input data depan\n");
        printf("2. input data belakang\n");
        printf("3. input data terurut\n");
        printf("4. hapus data\n");
        printf("5. Tampil\n");
        printf("0. Keluar\n");
        printf("Pilih Menu : ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
        {
            printf("Masukkan NIM : ");
            scanf("%d", &nim);
            printf("Masukkan NAMA : ");
            scanf("%s", &nama);
            printf("Masukkan IPK : ");
            scanf("%f", &ipk);
            sisipDepan(nim, nama, ipk);
            break;
        }
        case 2:
        {
            printf("Masukkan NIM : ");
            scanf("%d", &nim);
            printf("Masukkan NAMA : ");
            scanf("%s", &nama);
            printf("Masukkan IPK : ");
            scanf("%f", &ipk);
            sisipBelakang(nim, nama, ipk);
            break;
        }
        case 3:
        {
            printf("Masukkan NIM : ");
            scanf("%d", &nim);
            printf("Masukkan NAMA : ");
            scanf("%s", &nama);
            printf("Masukkan IPK : ");
            scanf("%f", &ipk);
            sisipTerurut(nim, nama, ipk);
            break;
        }
        case 4:
        {
        	printf("Hapus Data : ");
        	scanf("%d", &nim);
        	Awal=del(Awal, nim);
		}
        case 5:
        {
            tampil();
            break;
        }
        case 0:
        {
            break;
        }
        }
        //	Baru->next = NULL;

    } while (pilihan != 0);
    return 0;
}
