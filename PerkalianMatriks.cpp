#include <stdio.h>

int main(){
    int baris1, kolom1, baris2, kolom2;

    printf("========== PERKALIAN MATRIKS ==========\n\n");
    printf("Perkalian dua matriks hanya dapat dilakukan jika jumlah kolom matriks = jumlah baris matriks\n");
    printf("Masukan jumlah baris matriks pertama: ");
    scanf("%d", &baris1);
    printf("Masukan jumlah kolom matriks pertama: ");
    scanf("%d", &kolom1);
    printf("Masukan jumlah baris matriks kedua: ");
    scanf("%d", &baris2);
    printf("Masukan jumlah baris matriks kedua: ");
    scanf("%d", &kolom2);

    if (kolom1 != baris2) {
        printf("Matriks tidak dapat dikalikan satu sama lain.\n");
    } else {
        printf("Matriks dapat dikalikan satu sama laian.\n");
        int matriks1[baris1][kolom1];
        int matriks2[baris1][kolom2];
        int hasil[baris1][kolom2];
        printf("Masukan elemen matrks pertama: \n");
        for (int i = 0; i < baris1; i++) {
            for (int j = 0; j < kolom1; j++) {
                printf("Elemen [%d][%d]: ", i + 1, j+1);
                scanf("%d", &matriks1[i][j]);
            }
        } 
        printf("Masukan elemen matriks kedua: \n");
        for (int i = 0; i < baris2; i++) {
            for (int j = 0; j < kolom2; j++) {
                printf("elemen [%d][%d]: ", i+1, j+1);
                scanf("%d", &matriks2[i][j]);
            }
        }
        for (int i = 0; i < baris1; i++) {
            for (int j = 0; j < kolom2; j++) {
                hasil[i][j] = 0;
                for (int k = 0; k < kolom1; k++) {
                    hasil[i][j] += matriks1[1][k] * matriks2[k][j];
                }
            }
        } 
        printf("Hasil perkalian matriks: \n");
        for (int i = 0; i < baris1; i++) {
            for (int j = 0; j <  kolom2; j++) {
                printf("|%d| \n", hasil[i][j]);
            }
        }
        printf("\n");
    } 
    return 0;
}