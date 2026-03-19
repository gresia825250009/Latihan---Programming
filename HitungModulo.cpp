#include <stdio.h>

int main(){
    int angka1;
    int angka2;

    printf("---------- MENGHITUNG MODULO ----------\n");
    printf("\nMasukan angka pertama: ");
    scanf("%d", &angka1);
    printf("Masukan angka kedua: ");
    scanf("%d", &angka2);
    
    int hasil = angka1 - angka2 * (angka1/angka2);
    printf("%d mod %d = %d ", angka1, angka2, hasil);

    return 0;
}