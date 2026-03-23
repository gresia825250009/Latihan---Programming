#include <stdio.h>

void HargaPpn (int Harga_barang) {
    int Ppn, Total_harga, bayar;

    Ppn = 10 * Harga_barang / 100;

    bayar = Harga_barang + Ppn;

    printf("Harga barang = Rp.%d\n", Harga_barang);
    printf("Ppn = Rp.%d\n", Ppn);
    printf("Total harga yang harus dibayar = Rp.%d\n", bayar);
}

int main () {
    int Harga_barang;
    printf("Masukan harga barang: ");
    scanf("%d", &Harga_barang);

    HargaPpn(Harga_barang);

    return 0;
}