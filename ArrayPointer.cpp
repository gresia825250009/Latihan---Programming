#include <stdio.h> // untuk printf dan scanf
#include <stdlib.h> // untuk malloc dan free

// Fungsi untuk membagi array menjadi dua bagian
// arrayA: pointer ke array sumber
// jml: jumlah elemen arrayA
// duplikat1 & duplikat2: pointer ke array hasil pembagian
void bagiArray(int *arrayA, int jml, int *duplikat1, int *duplikat2) {
    int *tengah = arrayA + (jml / 2); // pointer ke elemen tengah

    for (int i = 0; i < jml / 2; i++) {
        *(duplikat1 + i) = *(arrayA + i);   // isi duplikat1 dari awal
        *(duplikat2 + i) = *(tengah + i);   // isi duplikat2 dari tengah
    }
}

// Fungsi untuk menggandakan ukuran array
// arrayA: pointer ke array sumber
// jml: jumlah elemen arrayA
// return: pointer ke array hasil ganda
int* gandaArray(int *arrayA, int jml) {
    int *arrayGanda = (int*) malloc(sizeof(int) * jml * 2); // alokasi memori baru

    if (arrayGanda == NULL) {
        printf("Gagal alokasi memori.\n");
        exit(1);
    }

    for (int i = 0; i < jml; i++) {
        *(arrayGanda + i) = *(arrayA + i); // isi arrayGanda dengan arrayA
    }
    for (int i = jml; i < jml * 2; i++) {
        *(arrayGanda + i) = 0; // isi arrayGanda dengan angka 0
    }

    return arrayGanda;
}

int main() {
    // Array awal
    int jml = 10;
    int arrayA[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    // Array duplikat hasil pembagian
    int duplikat1[5], duplikat2[5];

    // Panggil fungsi pembagi array
    bagiArray(arrayA, jml, duplikat1, duplikat2);

    // Tampilkan hasil pembagian
    printf("Array awal: ");
    for (int *p = arrayA; p < arrayA + jml; p++) {
        printf("%d ", *p);
    }
    printf("\nArray Duplikat 1: ");
    for (int *p = duplikat1; p < duplikat1 + 5; p++) {
        printf("%d ", *p);
    }
    printf("\nArray Duplikat 2: ");
    for (int *p = duplikat2; p < duplikat2 + 5; p++) {
        printf("%d ", *p);
    }

    // Panggil fungsi pengganda array
    int *hasilGanda = gandaArray(arrayA, jml);

    // Tampilkan hasil penggandaan
    printf("\n\nArray hasil ganda: ");
    for (int *p = hasilGanda; p < hasilGanda + (jml * 2); p++) {
        printf("%d ", *p);
    }

    // Bebaskan memori hasilGanda
    free(hasilGanda);

    return 0;
}
