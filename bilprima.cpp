#include <stdio.h>

// fungsi untuk menentukan apakah suatu bilangan adalah bilangan prima
int prima (int n) {
    int i, prima = 1;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            prima = 0;
            break;
        }
    }
    return prima;
}

int main () {
    int n, i;
    printf("Masukan sebuah bilangan: ");
    scanf("%d", &n);

    // menampilkan bilangan prima yang lebih kecil atau sama dengan n
    printf("Bilangan prima yang lebih kecil atau sama dengan %d adalah: ", n);
    for (i = 2; i <= n; i++) {
        if (prima(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}