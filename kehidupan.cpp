#include <stdio.h>

int main(){
    int budget;
    char hari[25];
    
    printf("========== PENGELUARAN HARIAN ==========\n");
    printf("\n***PENULISAN HARGA TIDAK MEMAKAI TITIK***\n");
    printf("\nPengeluaran hari: ");
    scanf("%s", &hari);
    printf("\nBerapa budget hari ini: Rp");
    scanf("%d", &budget);

    int jumlah_pengeluaran;
    char pengeluaran[25][50];
    int harga[20];
    int total = 0;
    printf("\nJumlah pengeluaran: ");
    scanf("%d", &jumlah_pengeluaran);
    int i;
    for(int i = 1; i <= jumlah_pengeluaran; i ++){
        printf("\nPengeluaran ke-[%d]: ", i);
        scanf("%s", &pengeluaran[i]);
        printf("Harga %s: Rp", pengeluaran[i]);
        scanf(" %d", &harga[i]);
        total += harga[i];
    }
    printf("\nCatatan pengeluaran hari ini: \n");
    for (int i = 1; i <= jumlah_pengeluaran; i++){
        printf("- %s : Rp%d\n", pengeluaran[i], harga[i]);
    }
    int sisa = budget - total;
    printf("\n============= Pengeluaran Hari %s ==============\n", hari);
    printf("\nTotal pengeluaran = Rp%d", total);
    printf("\nSisa duit         = Rp%d\n", sisa);
    printf("\n==================================================");

    
    return 0;
}