#include <stdio.h>

struct Mahasiswa {
    char nama[50];
    int nim;
    float ipk;
};

int main() {
    int n;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    struct Mahasiswa mhs[n];
    for (int i = 0; i < n; i++) {
        printf("\nMasukkan nama mahasiswa %d: ", i + 1);
        scanf("%s", mhs[i].nama);
        printf("Masukkan NIM mahasiswa %d: ", i + 1);
        scanf("%d", &mhs[i].nim);
        printf("Masukkan IPK mahasiswa %d: ", i + 1);
        scanf("%f", &mhs[i].ipk);
    }
    printf("\n=== Data mahasiswa ===\n");
    for (int i = 0; i < n; i++) {
        printf("Nama    : %s\n", mhs[i].nama);
        printf("NIM     : %d\n", mhs[i].nim);
        printf("IPK     : %.2f\n", mhs[i].ipk);
        printf("\n");
    }
    return 0;
}
