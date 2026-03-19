#include <stdio.h>

int main(){
    int baris, kolom;

    printf("========== PENGURANGAN MATRIKS ==========\n\n");
    printf("Pengurangan dua matriks hanya dapat dilakukan jika kedua matriks memiliki ukuran yang sama\n");
    printf("Masukan jumlah baris matiks: ");
    scanf("%d", &baris);
    printf("Masukan jumlah kolom matriks: ");
    scanf("%d", &kolom);
    
    int matriks1[baris][kolom];
    int matriks2[baris][kolom];
    int hasil [baris][kolom];
    
    printf("Masukan elemen matriks pertama: \n");
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++){
            printf("Elemen [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriks1[i][j]);
        }
    }
    printf("Masukan elemen matriks kedua: \n");
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++){
            printf("Elemen [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriks2[i][j]);
        }
    }
    for (int i = 0; i < baris; i ++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
        }
    }
    printf("Hasil pengurangan matriks: \n");
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            printf("|%d| \n", hasil[i][j]);
        }
        printf("\n");
    }
    return 0;
}