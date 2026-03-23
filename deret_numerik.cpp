#include <stdio.h>

int main(){
    int x, y, angka;

    printf("----- DERET NUMERIK -----\n");
    printf("Masukan x untuk deret angka: ");
    scanf("%d", &x);
    printf("Masukan y untuk deret angka: ");
    scanf("%d", &y);
    printf("Deret Angka: ");
    
    angka = y;
    for(int i = 1; i <= x; i++){
        printf("%d ", angka);
        angka += x;
    }

    return 0;
}