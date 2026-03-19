#include <stdio.h>

// contoh input: 01/01/01 menjadi 1 Januari 2001
void konversiTanggal (int tanggal, int bulan, int tahun) {
    //fungsi untuk konversi tanggal menjadi format yang lebih mudah dibaca

    //1. membuat switch case untuk menentukan nama bulan berdasarkan angka bulan yang dimasukan
    switch (bulan) {
        //2. menampilkan hasil konversi tanggal dengan format "tanggal bulan tahun"
        case 1:
            printf("%d Januari %d\n", tanggal, tahun);
            break;
        case 2:
            printf("%d Februari %d\n", tanggal, tahun);
            break;
        case 3:
            printf("%d Maret %d\n", tanggal, tahun);
            break;
        case 4:
            printf("%d April %d\n", tanggal, tahun);
            break;
        case 5:
            printf("%d Mei %d\n", tanggal, tahun);
            break;
        case 6:
            printf("%d Juni %d\n", tanggal, tahun);
            break;
        case 7:
            printf("%d Juli %d\n", tanggal, tahun);
            break;
        case 8:
            printf("%d Agustus %d\n", tanggal, tahun);
            break;
        case 9:
            printf("%d September %d\n", tanggal, tahun);
            break;
        case 10:
            printf("%d Oktober %d\n", tanggal, tahun);
            break;
        case 11:
            printf("%d November %d\n", tanggal, tahun);
            break;
        case 12:
            printf("%d Desember %d\n", tanggal, tahun);
            break;
        default:
            printf("Bulan yang dimasukan tidak valid.\n");
    }
}

int main() {
    int tanggal, bulan, tahun;

    printf("Masukan tanggal (dd mm yyyy): ");
    scanf("%d %d %d", &tanggal, &bulan, &tahun);

    konversiTanggal(tanggal, bulan, tahun);

    return 0;
}