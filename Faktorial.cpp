#include <stdio.h>

int faktor (int n) {
    int F;
    F = 1;
    for (int i = n; i >= 1; i -= 1) {
        F = F * i;
    }

    return F;
}

int main () {
    int n, fakt;
    printf("Masukan nilai n: ");
    scanf("%d", &n);

    if (n > 1) {
        fakt = faktor(n);
    } else {
        fakt = 1;
    }

    printf("Faktorial dari %d adalah %d\n", n, fakt);

    return 0;
}