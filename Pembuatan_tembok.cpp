#include <stdio.h>

int main(){
    int P_tembok;
    int T_tembok;

    printf("====== MENGHITUNG BIAYA PEMBUATAN TEMBOK ======\n");
    printf("\n***PENULISAN HARGA TIDAK MEMAKAI TITIK***\n");
    printf("\nPanjang tembok: ");
    scanf("%d", &P_tembok);
    printf("Tinggi tembok: ");
    scanf("%d", &T_tembok);
    
    int luas_Tembok = P_tembok * T_tembok;
    printf("\nLuas tembok adalah %d m^2\n", luas_Tembok);
    
    int jumlah_material;
    printf("Jumlah material yang diperlukan: ");
    scanf("%d", &jumlah_material);
    
    char material[10][35];
    int harga[10];
    int biaya_material = 0;
    int i;
    for(int i = 1; i < jumlah_material; i++){
        printf("\nMaterial yang diperlukan [%d]: \n", i);
        scanf("%s", &material[i]);
        printf("Harga %s: ", material[i]);
        scanf(" %d", &harga[i]);
        biaya_material += harga[i];
    }

    printf("\nDaftar material: \n");
    for(int i = 1; i < jumlah_material; i++){
        printf("- %s : %d\n", material[i], harga[i]);
    }
    
    int biaya_tukang;
    printf("\nBiaya Tukang per m^2: \n");
    scanf("%d", &biaya_tukang);
    int biaya_perM = biaya_material + biaya_tukang;
    int biaya_total = luas_Tembok * biaya_perM;

    printf("\nLuas tembok                  = %d m^2\n", luas_Tembok);
    printf("-----------------------------------------------------------\n");
    printf("Total biaya material         = Rp%d\n", biaya_material);
    printf("Biaya tukang per m^2         = Rp%d\n", biaya_tukang);
    printf("--------------------------------------------------------+++\n");
    printf("Total biaya per m^2          = Rp%d\n", biaya_perM);
    printf("===========================================================\n");
    printf("Total biaya pembuatan tembok = Rp%d\n", biaya_total);
    printf("===========================================================\n");

    return 0;
}