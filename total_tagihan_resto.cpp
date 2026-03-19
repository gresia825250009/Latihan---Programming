#include <stdio.h>

int main(){
    double total_harga_makanan;
    double total_harga_minuman;
    
    printf("\n***PENULISAN HARGA TIDAK MEMAKAI TITIK***\n");
    printf("\nBerapa total harga makanan anda: Rp");
    scanf("%lf", &total_harga_makanan);
    printf("Berapa total harga minuman anda: Rp");
    scanf("%lf", &total_harga_minuman);
    
    double subtotal = total_harga_makanan + total_harga_minuman;

    double pajak = subtotal * 0.11;
    double layanan = subtotal * 0.05;
    double jumlah = subtotal + pajak + layanan;

    printf ("\n================ TAGIHAN RESTORAN ===============\n");
    printf("\nHarga Makanan          : Rp%.2f\n", total_harga_makanan);
    printf("Harga Makanan          : Rp%.2f\n", total_harga_minuman);
    printf("----------------------------------------------+++\n");
    printf("Total harga F&B        : Rp%.2f\n", subtotal);
    printf("\nBiaya pajak 11%%        : Rp%.2f\n", pajak);
    printf("Biaya layanan 5%%       : Rp%.2f\n", layanan);
    printf("----------------------------------------------+++\n");
    printf("Total                  : Rp%.2f", jumlah);

    return 0;
    
}