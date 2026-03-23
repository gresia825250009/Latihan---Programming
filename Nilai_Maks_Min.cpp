#include <stdio.h>

int main() {
    int angka[5];
    int maks = 0;   

    printf("Masukkan 5 angka:\n");
    for (int i = 0; i < 5; i++) {
        printf("Angka ke-%d: ", i + 1);
        scanf("%d", &angka[i]);
        if (angka[i] > maks) {
            maks = angka[i];
        }
    }

    printf("Angka yang dimasukan: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", angka[i]);
    }
    printf("\n");

    maks = angka[0];
    for (int i = 1; i < 5; i++) {
        if (angka[i] > maks) {
            maks = angka[i];
        }
    }

    printf("Nilai maksimum adalah: %d\n", maks);

    FILE *file = fopen("MaxValue.txt", "w");
    if (file == NULL) {\
        file = fopen("MaxValue.txt", "w");
        fscanf(file, "%d", &maks);
        fclose(file);
    }
    fprintf(file, "Nilai maksimum adalah: %d\n", maks);
    fclose(file);
    return 0;
}