#include <stdio.h>
#include <math.h>

// diketahui rumus ABC untuk menghitung akar-akar dari persamaan kuadarat -B+ sqrt(D) / 2A 

// fungsi untuk menghitung akar pertama
float HitungAkar1 (float a, float b, float D) {
    float akar1;

    akar1 = (-b + sqrt(D)) / (2 * a);

    return akar1;
}

float HitungAkar2 (float a, float b, float D) {
    float akar2;

    akar2 = (-b - sqrt(D)) / (2 * a);

    return akar2;
}

float HitungD (float a, float b, float c) {
    float D;

    D = pow(b, 2) - (4 * a * c);

    return D;
}

int main () {
    float a, b, c, D, akar1, akar2;

    printf("Masukan nilai a: ");
    scanf("%f", &a);

    printf("Masukan nilai b: ");
    scanf("%f", &b);

    printf("Masukan nilai c: ");
    scanf("%f", &c);

    D = HitungD(a, b, c);

    // memeriksa nilai D untuk menentukan jenis akar yang dimiliki oleh persamaan kuadrat
    if (D > 0) {
        // memanggil fungsi untuk menghitung akar-akar dari persamaan kuadrat
        akar1 = HitungAkar1(a, b, D);
        akar2 = HitungAkar2(a, b, D);
        printf("Akar-akar dari persamaan kuadrat adalah %.2f dan %.2f\n", akar1, akar2);
    } else if (D == 0) {
        akar1 = HitungAkar1(a, b, D);
        printf("Persamaan kuadrat memiliki satu akar yaitu %.2f\n", akar1);
    } else {
        printf("Persamaan kuadrat tidak memiliki akar real\n");
    }

    return 0;
}