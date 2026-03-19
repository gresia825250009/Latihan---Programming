#include <stdio.h>

int main(){
    int baris = 5;
    for(int i = 0; i < 5; i ++){
        for(int spasi = 1; spasi < baris - i; spasi ++){
           printf(" "); 
        }
        int angka = 1;
        for (int j = 0; j <= i; j++){
        printf("%d ", angka);
        angka = angka * (i - j) /  (j + 1);
        }
        printf("\n");
    } 
    return 0;
}