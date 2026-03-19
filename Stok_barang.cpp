#include <stdio.h>

void input_user(int rak[5][50], int stok[5]){
    printf("===== INPUT STOK BARANG ======\n");
    for (int i = 0; i < 5; i++){
        printf("Rak %d\n", i + 1);
        printf("Masukkan nama barang rak %d: ", i + 1);
        scanf(" %[^\n]", rak[i]);
        printf("Masukkan jumlah stok rak %d: ", i + 1);
        scanf("%d", &stok[i]);
    }
    printf("\n");
}

void tambah_stok(int rak[5][50], int stok[5], int tambah){
    int rak_pilihan;
    printf("=========== TAMBAH STOK BARANG ===========\n");
    printf("Pilih rak: ");
    scanf("%d", &rak_pilihan);
    printf("Rak %d: %s\n", rak_pilihan, rak[rak_pilihan - 1]);
    printf("Masukkan jumlah stok: ");
    scanf("%d", &tambah);
    stok[rak_pilihan - 1] += tambah;
    printf("\n");
}

void kurang_stok(int rak[5][50], int stok[5], int kurang){
    int rak_pilihan;
    printf("\n=========== MENGURANGI STOK BARANG ===========\n");
    printf("Pilih rak: ");
    scanf("%d", &rak_pilihan);
    printf("Rak %d: %s\n", rak_pilihan, rak[rak_pilihan - 1]);
    printf("Masukkan jumlah stok: ");
    scanf("%d", &kurang);
    stok[rak_pilihan - 1] -= kurang;
    printf("\n");
}

int main(){
    int rak[5][50];
    int stok[5];
    int tambah, kurang;
    int pilihan;

    input_user(rak, stok);

    do{
        printf("\n=========== MENU STOK BARANG ===========\n");
        printf("1. Tampilkan rak\n");
        printf("2. Tambah stok barang\n");
        printf("3. Kurangi stok barang\n"); 
        printf("4. Grafik laporan stok barang\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        
        switch(pilihan){
            case 1:
                printf("\n=========== DAFTAR RAK ===========\n");
                for(int i = 0; i < 5; i++){
                    printf("Rak %d: %s \t= %d barang\n", i + 1, rak[i], stok[i]);
                }
                break;
            case 2:
                tambah_stok(rak, stok, tambah);
                break;
            case 3:
                kurang_stok(rak, stok, kurang);
                break;
            case 4:
                printf("\n=========== GRAFIK LAPORAN STOK BARANG ===========\n");
                for(int i = 0; i < 5; i++) {
                    printf("Rak %d: %s \t= ", i + 1, rak[i]);
                    for(int j = 0; j < stok[i]; j++) {
                        printf("|");
                    }
                    printf(" (%d items)\n", stok[i]);
                }
                break;
            case 5:
                printf("Keluar dari program. Terima kasih :)\n");
                break;
            default:
                printf("Pilihan tidak tersedia\n");
                break;
        }
    }while(pilihan != 5);
    return 0;
}