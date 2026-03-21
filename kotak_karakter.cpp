#include <stdio.h>

int main() {
    int n;
    char C1, C2, C3;

    printf("Masukkan banyak n: ");
    scanf("%d", &n);
    printf("Masukkan karakter 1: ");
    scanf(" %c", &C1);
    printf("Masukkan karakter 2: ");
    scanf(" %c", &C2);
    printf("Masukkan karakter 3: ");
    scanf(" %c", &C3);

    printf("\n");

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n) {
                printf("%c ", C1);
            } 
            else if (j == 1 || j == n) {
                printf("%c ", C2);
            } 
            else {
                printf("%c ", C3);
            }
        }
        printf("\n");
    }

    return 0;
}