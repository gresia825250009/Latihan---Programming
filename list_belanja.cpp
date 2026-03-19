#include <stdio.h>

struct barang {
    char nama[50];
    int harga;
};

void list_belanja() {
    int banyak_barang;

    printf("Masukkan banyak jenis barang yang dibeli: ");
    scanf("%d", &banyak_barang);

    struct barang daftar_barang[banyak_barang];

    for (int i = 0; i < banyak_barang; i++) {
        printf("\nMasukkan nama barang ke-%d: ", i + 1);
        scanf("%s", daftar_barang[i].nama);
        printf("Masukkan harga barang ke-%d: ", i + 1);
        scanf("%d", &daftar_barang[i].harga);
    }

    FILE *file = fopen("daftar_belanja.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menulis.\n");
        return;
    }
    
    fprintf(file, "===== DAFTAR BELANJA =====\n");
    int total_harga = 0;
    for (int i = 0; i < banyak_barang; i++) {
        fprintf(file, "Barang ke-%d: %s - Harga: %d\n", i + 1, daftar_barang[i].nama, daftar_barang[i].harga);
        total_harga += daftar_barang[i].harga;
    }
    fprintf(file, "Total harga: %d\n", total_harga);
    fclose(file);
    
    printf("\n========= DAFTAR BELANJA =========\n");
    
    for (int i = 0; i < banyak_barang; i++) {
        printf("Barang ke-%d: %s - Harga: %d\n", i + 1, daftar_barang[i].nama, daftar_barang[i].harga);
    }
}

int main() {
    list_belanja();
    return 0;
}