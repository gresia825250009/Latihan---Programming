// Hanna Nathalia 825250015
#include <stdio.h>

int main() {

    int i, j; // i = loop baris, j = loop bintang/spasi

    // bagian atas
    for (i = 5; i >= 1; i -= 2) {

        // loop untuk spasi
        for (j = 0; j < (5 - i) / 2; j++) {
            printf(" ");
        }

        // loop untuk bintang
        for (j = 0; j < i; j++) {
            printf("*");
        }

        printf("\n");
    }

    // bagian bawah
    for (i = 3; i <= 5; i += 2) {

        // loop untuk spasi
        for (j = 0; j < (5 - i) / 2; j++) {
            printf(" ");
        }

        // loop untuk bintang
        for (j = 0; j < i; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}