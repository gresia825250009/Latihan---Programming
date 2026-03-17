#include <stdio.h>

int main(){
    float harga_pokok;

    printf("----------|| MENGHITUNG HARGA JUAL ||----------\n");
    printf("\nHarga pokok atau modal  : ");
    scanf("%f", &harga_pokok);

    float transport = harga_pokok * 0.15;
    float pph = harga_pokok * 0.10;
    float sewa_toko = harga_pokok * 0.20;
    float biaya_tambahan = harga_pokok + transport + pph + sewa_toko;
    
    printf("\nHarga pokok                 :%.2f\n", harga_pokok);
    printf("Biaya transport 15%%         :%.2f\n", transport);
    printf("Biaya pajak (pph 10%%)       :%.2f\n", pph);
    printf("Biaya sewa toko 20%%         :%.2f\n", sewa_toko);
    printf("-----------------------------------------------------+++\n");
    printf("TOTAL BIAYA TAMBAHAN        :%.2f\n", biaya_tambahan);

    float laba = 0.10;
    float harga_jual = biaya_tambahan + laba;
    printf("--------------------------------------------------------\n\n");
        
    printf("-----------------------------------------------------+++\n");
    printf("HARGA JUAL(keuntungan 10%%)  :%.2f\n", harga_jual);
    printf("--------------------------------------------------------\n");
    return 0;

}