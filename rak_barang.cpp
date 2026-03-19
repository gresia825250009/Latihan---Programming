#include <stdio.h>

int pilih, isirak[5];
int rakPilihan, jumlahTambah, jumlahHapus;
char rak[5][50];

void menu() {
    printf("           \n");
    printf("Menu:\n");
    printf("1. Tampilkan rak\n");
    printf("2. Tambah item ke rak\n");
    printf("3. Hapus item dari rak\n");
    printf("4. Lihat grafik kapasitas rak\n");
    printf("5. Keluar\n");
    printf("Pilih opsi: ");
    scanf("%d", &pilih);
}

void tampilRak() {
    printf("           \n");
    printf("== DAFTAR RAK ==\n");
    for(int i = 0; i < 5; i++) {
        printf("%d. Rak %s berisi %d\n", i + 1, rak[i], isirak[i]);
    }
}

void tambahItem() {
    printf("           \n");
    printf("Pilih rak untuk menambah item (1-5): ");
    scanf("%d", &rakPilihan);
    if(rakPilihan < 1 || rakPilihan > 5) {
        printf("Pilihan rak tidak valid.\n");
        return;
    }
    printf("Masukkan jumlah item yang akan ditambahkan ke rak %d: ", rakPilihan);
    scanf("%d", &jumlahTambah);
    isirak[rakPilihan - 1] += jumlahTambah;
    printf("Item berhasil ditambahkan ke rak %d.\n", rakPilihan);
    printf("Rak %s sekarang berisi %d item.\n", rak[rakPilihan - 1], isirak[rakPilihan - 1]);
}

void hapusItem() {
    printf("           \n");
    printf("Pilih rak untuk menghapus item (1-5): ");
    scanf("%d", &rakPilihan);
    if(rakPilihan < 1 || rakPilihan > 5) {
        printf("Pilihan rak tidak valid.\n");
        return;
    }
    printf("Masukkan jumlah item yang akan dihapus dari rak %d: ", rakPilihan);
    scanf("%d", &jumlahHapus);
    if(jumlahHapus > isirak[rakPilihan - 1]) {
        printf("Jumlah item yang dihapus melebihi isi rak.\n");
        return;
    }
    isirak[rakPilihan - 1] -= jumlahHapus;
    printf("Item berhasil dihapus dari rak %d.\n", rakPilihan);
    printf("Rak %s sekarang berisi %d item.\n", rak[rakPilihan - 1], isirak[rakPilihan - 1]);
}

void grafikRak() {
    printf("           \n");
    printf("==GRAFIK KAPASITAS RAK==\n");
    for(int i = 0; i < 5; i++) {
        printf("Rak %-10s: ", rak[i]);
        for(int j = 0; j < isirak[i]; j++) {
            printf("=");
        }
        printf(" (%d items)\n", isirak[i]);
    }
}

void keluar() {
    printf("           \n");
    printf("Keluar dari program.\n");
}


int main () {

    for(int i = 0; i < 5; i++) {
        printf("Masukkan nama item yang disimpan pada rak ke-%d: ", i + 1);
        scanf(" %[^\n]", rak[i]);
    }
    printf("           \n");
    printf("Isi rak:\n");
    for(int i = 0; i < 5; i++) {
        printf("masukkan jumlah isi rak %s: ", rak[i]);
        scanf("%d", &isirak[i]);
    }
    tampilRak();
    menu();
    while(pilih >= 1 && pilih <= 5) {
        switch(pilih) {
            case 1:
                tampilRak();
                break;
            case 2:
                tambahItem();
                break;
            case 3:
                hapusItem();
                break;
            case 4:
                grafikRak();
                break;
            case 5:
                keluar();
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        } 
        menu();
    }


}

