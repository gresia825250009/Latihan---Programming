#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int angka, angka_rahasia;
    int percobaan = 0;
    char nama_user[50];
    srand(time(0));
    angka_rahasia = rand() % 10 + 1;
    
    printf("\n=============------- GAME CUYPY ------===========\n");
    printf("HELLO SELAMAT DATANG DI GAME CUYPY\n");
    printf("Siapa nama kamu: ");
    scanf("%s", &nama_user);
    printf("\nHALLO %s!!! selamat datang di game CUYPY\n", nama_user);
    
    do {
        printf("\n=============------- GAME CUYPY ------===========\n");
        printf("\n|1| |2| |3| |4| |5| |6| |7| |8| |9| |10|");
        printf("\n________________________________________________");
        printf("\nTebak CUYPY ada di angka berapa: ");
        scanf("%d", &angka);
        percobaan ++;

        if(angka < angka_rahasia){
            printf("\nTebakan anda SALAH, angka terlalu kecil!\n");
        } else if (angka > angka_rahasia){
            printf("\nTebakan anda SALAH, angka terlalu besar!\n");
        } else {
            printf("Tebakan anda BENAR! CUYPY ada di angka %d\n", angka_rahasia);
            printf("Jumlah percobaan: %d\n", percobaan);
        }    
    }while (angka != angka_rahasia);
    
    return 0;
}