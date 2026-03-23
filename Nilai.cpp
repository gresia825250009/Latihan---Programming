#include <stdio.h>

void input (char huruf, float A, float B, float C, float D, float E) {
    if (huruf == 'A') {
        A = 4.0;
    }
    else if (huruf == 'B') {
        B = 3.0;
    }
    else if (huruf == 'C') {
        C = 2.0;
    }
    else if (huruf == 'D') {
        D = 1.0;
    } else if (huruf == 'E') {
        D = 0.0;
    }

}

void output (float nilai, char hasil) {

    if (nilai >= 90.0 && nilai <= 100) {
        hasil = 'A';
    }
    else if (nilai >= 80.0 && nilai <= 89.9) {
        hasil = 'B';
    }
    else if (nilai >= 70.0 && nilai <= 79.9) {
        hasil = 'C';
    }
    else if (nilai >= 60.0 && nilai <= 69.0) {
        hasil = 'D';
    } else if (nilai >= 0.0 && nilai <= 49.9) {
        hasil = 'E';
    }
}

int main () {
    char huruf, hasil;
    float A, B, C, D, E, nilai;

    printf("Masukan nilai huruf (A, B, C, D, E): ");
    scanf("%c", &huruf);

    input(huruf, A, B, C, D, E);

    printf("Masukan nilai numerik (0-100): ");
    scanf("%f", &nilai);

    input(huruf, A, B, C, D, E);
    output(nilai, hasil);

    printf("Nilai huruf %c memiliki nilai numerik %.1f\n", huruf, nilai);
    printf("Nilai numerik %.1f memiliki nilai huruf %c\n", nilai, hasil);

    return 0;
}