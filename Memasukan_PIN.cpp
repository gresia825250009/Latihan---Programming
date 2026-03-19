#include <stdio.h>

int main() {
    int pin, pinSimpan, konfirmasi, percobaan = 0; 

    while (1) {
        printf("Masukkan PIN ATM (4 digit): "); 
        scanf("%d", &pin); 

        if (pin < 1000 || pin > 9999) { 
            printf("Error: PIN harus 4 digit!\n\n"); 
            continue;
        }

        printf("Apakah Anda yakin ingin menyimpan PIN ini? (1 = Ya, 0 = Ulang): ");
        scanf("%d", &konfirmasi); 

        if (konfirmasi == 1) {
            pinSimpan = pin;
            printf("PIN berhasil disimpan!\n\n"); 
            break;
        } else {
            printf("Ulangi input PIN.\n\n"); 
        }
    } 

    printf("Masukkan PIN untuk login:\n"); 

    while (percobaan < 3) { 
        int pinCoba;
        printf("PIN: "); 
        scanf("%d", &pinCoba); 

        if (pinCoba == pinSimpan) { 
            printf("Login berhasil. Selamat menggunakan ATM!!\n"); 
            return 0;
        } else {
            percobaan++;
            printf("PIN salah! Percobaan tersisa: %d\n", 3 - percobaan); 
        }
    } 

    printf("Kartu Anda Diblokir!\n");
    return 0;
}