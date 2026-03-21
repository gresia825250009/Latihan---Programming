#include <stdio.h>
#include <windows.h>

int main(){
    int angka;
    printf("------------- GAME SEGERA DIMULAI -------------\n");
    printf("Masukan angka untuk countdown: ");
    scanf("%d", &angka);

    printf("Game dimulai dalam hitungan\n");
    while (angka >= 1) {
        printf("%d\n", angka);
        Sleep(100);
        angka --;
    }
    printf("GAME SUDAH DIMULAI!");
    return 0;
}