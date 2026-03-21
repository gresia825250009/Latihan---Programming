

// no 5 masi failed
#include <stdio.h>
#include <string.h>

int main() {
    int total = 0, beli = 0;
    char a[20], b[20], c[20];
    int air = 10000;
    int jus = 15000;
    int soda = 15000;
    int kopi = 20000;
    int teh = 15000;
    int jumlah = total;

    printf("Vending Machine Neta\n");

    while (beli < 4 && total <= 50000)
    {
        printf("Daftar Produk:\n");
        printf("A. Air Mineral = Rp 10.000\n");
        printf("B. Jus = Rp 15.000\n");
        printf("C. Soda = Rp 15.000\n");
        printf("D. Kopi = Rp 20.000\n");
        printf("E. Teh = Rp 15.000\n");
        printf("Masukkan Kode pembelian pertama (contoh: jus): ");
        scanf("%s", a);
        if (strcmp(b, "x") == 0 || strcmp(c, "x") == 0)
        {
            break;
        }

        if (strcmp(a, "a") == 0)
        {
            total += air;
            beli++;
        }
        else if (strcmp(a, "b") == 0)
        {
            total += jus;
            beli++;
        }
        else if (strcmp(a, "c") == 0)
        {
            total += soda;
            beli++;
        }
        else if (strcmp(a, "d") == 0)
        {
            total += kopi;
            beli++;
        }
        else if (strcmp(a, "e") == 0)
        {
            total += teh;
            beli++;
        } jumlah++;

        printf("Masukkan Kode pembelian kedua (contoh: jus), jika tidak ada masukkan 'x': ");
        scanf("%s", b);
        if (strcmp(b, "x") == 0 || strcmp(c, "x") == 0)
        {
            break;
        }
        if (strcmp(b, "a") == 0)
        {
            total += air;
            beli++;
        }
        else if (strcmp(b, "b") == 0)
        {
            total += jus;
            beli++;
        }
        else if (strcmp(b, "c") == 0)
        {
            total += soda;
            beli++;
        }
        else if (strcmp(b, "d") == 0)
        {
            total += kopi;
            beli++;
        }
        else if (strcmp(b, "e") == 0)
        {
            total += teh;
            beli++;
        } jumlah++;

        printf("Masukkan Kode pembelian ketiga (contoh: jus), jika tidak ada masukkan 'x': ");
        scanf("%s", c);
        if (strcmp(b, "x") == 0 || strcmp(c, "x") == 0)
        {
            break;
        }
        if (strcmp(c, "a") == 0)
        {
            total += air;
            beli++;
        }
        else if (strcmp(c, "b") == 0)
        {
            total += jus;
            beli++;
        }
        else if (strcmp(c, "c") == 0)
        {
            total += soda;
            beli++;
        }
        else if (strcmp(c, "d") == 0)
        {
            total += kopi;
            beli++;
        }
        else if (strcmp(c, "e") == 0)
        {
            total += teh;
            beli++;
        } jumlah++;

        if (total > 50000)
        {
            printf("Total pembelian anda adalah: Rp %d\n", total);
            printf("Total harga pembelian sudah maksimum\n");
            {
                break;
            }
        }
        else if (beli > 3)
        {
            printf("Pembelian produk sudah maksimum");
            {
                break;
            }
        }

    }


    printf("Total pembelian anda adalah: Rp %d\n", jumlah);
    printf("Barang belanja anda: %s, %s, %s\n", a, b, c);
    printf("Terima kasih telah berbelanja di Vending Machine Neta\n");
    return 0;
}