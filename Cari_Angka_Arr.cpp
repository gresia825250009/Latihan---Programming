#include <stdio.h>

int cariAngka(int array[], int n, int angka) {
    int kiri = 0, kanan = n - 1, tengah, hasil = -1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (array[tengah] == angka) {
            hasil = tengah;
            break;
        } else if (array[tengah] < angka) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return hasil;
}

int main () {
    int data[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n = sizeof(data) / sizeof(data)[0];
    int cari;

    printf("Masukkan angka yang ingin dicari: ");
    scanf("%d", &cari);

    int hasil = cariAngka(data, n, cari);
    if (hasil != -1) {
        printf("Angka %d ditemukan pada indeks %d\n", cari, hasil);
    } else {
        printf("Angka %d tidak ditemukan dalam array\n", cari);
    }
    return 0;
}