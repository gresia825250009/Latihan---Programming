#include <stdio.h>

int main (){
    int nilai[10];
    for (int i = 0; i < 10; i++){
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
    }

    // daftar bilangan ganjil dan genap
    printf("\nDaftar bilangan ganjil: ");
    for (int i = 0; i < 10; i++){
        if (nilai[i] % 2 == 1){
            printf("%d ", nilai[i]);
        }
    }
    printf("\nDaftar bilangan genap: ");
    for (int i = 0; i < 10; i++){
        if (nilai[i] % 2 == 0){
            printf("%d ", nilai[i]);
        }
    }

    return 0;
}