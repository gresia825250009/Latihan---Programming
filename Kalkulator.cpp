#include <stdio.h>

int tambah(int a, int b)
{
    int hasil = a + b;
    return hasil;
}

int kurang(int a, int b) 
{
    int hasil = a - b;
    return hasil;
}

int kali(int a, int b) 
{
    int hasil = a * b;
    return hasil;
}

int bagi(int a, int b) {
    if (b != 0) {
        int hasil = a / b;
        return hasil;
    } else {
        printf("Error: Division by zero\n");
        return 0; 
    }
}

int main() {
    int angka1, angka2;
    int operasi;
    while (true) {   
        printf("=========== LATIHAN 1 ===========\n\n");
        printf("Masukkan angka 9999 jika ingin keluar dari program.\n\n"); 
        printf("Masukkan angka pertama: ");
        scanf("%d", &angka1);
        if (angka1 == 9999) {
            printf("Keluar dari program.\n");
            {
            break;
            }
        }
        printf("Masukkan angka kedua: ");
        scanf("%d", &angka2);
        printf("Pilih operasi \n1: tambah(+)\n2: kurang(-)\n3: kali(x)\n4: bagi(:)\n--> ");
        scanf("%d", &operasi);   
        if (operasi == 1) {
            printf("Hasil %d + %d = %d\n", angka1, angka2, tambah(angka1, angka2));
        } else if (operasi == 2) {
            printf("Hasil %d - %d = %d\n", angka1, angka2, kurang(angka1, angka2));
        } else if (operasi == 3) {
            printf("Hasil %d x %d = %d\n", angka1, angka2, kali(angka1, angka2));
        } else if (operasi == 4) {
            printf("Hasil %d : %d = %d\n", angka1, angka2, bagi(angka1, angka2));
        } else {
            printf("Operasi tidak valid\n");
        }
    }

}