#include <stdio.h>

float ladang_pertanian(float nilai_tanggungan, float luas_tanah) {
    return 0.035 * nilai_tanggungan * luas_tanah;
}

float ladang_kacang_kedelai(float nilai_tanggungan, float luas_tanah) {
    return 2 * (0.035 * nilai_tanggungan * luas_tanah);
}

float ladang_bawang_merah(float nilai_tanggungan, float luas_tanah) {
    return 2 * (0.035 * nilai_tanggungan * luas_tanah);
}

float ladang_cabai(float nilai_tanggungan, float luas_tanah) {
    return 2 * (0.035 * nilai_tanggungan * luas_tanah);
}

float ladang_padi(float nilai_tanggungan, float luas_tanah) {
    return 1.5 * (0.035 * nilai_tanggungan * luas_tanah);
}

float ladang_singkong(float nilai_tanggungan, float luas_tanah) {
    return 1.5 * (0.035 * nilai_tanggungan * luas_tanah);
}

float ladang_jagung(float nilai_tanggungan, float luas_tanah) {
    return 1.5 * (0.035 * nilai_tanggungan * luas_tanah);
}

void slip_pembayaran(char nama_petani[100], int jenis_ladang[], float biaya_ladang[], int jumlah_ladang) {
    float total = 0;

    printf("\n===== SLIP PEMBAYARAN ASURANSI =====\n");
    printf("Nama Petani : %s\n", nama_petani);
    printf("------------------------------------\n");

    for (int i = 0; i < jumlah_ladang; i++) {
        printf("\n%d. ", i + 1);
        switch (jenis_ladang[i]) {
            case 1: printf("Ladang Pertanian"); break;
            case 2: printf("Ladang Kacang Kedelai"); break;
            case 3: printf("Ladang Bawang Merah"); break;
            case 4: printf("Ladang Cabai"); break;
            case 5: printf("Ladang Padi"); break;
            case 6: printf("Ladang Singkong"); break;
            case 7: printf("Ladang Jagung"); break;
            default: printf("Tidak Diketahui");
        }
        printf("\nBIAYA ASURANSI Rp %.2f\n\n", biaya_ladang[i]);
        total += biaya_ladang[i];
    }

    printf("------------------------------------\n");
    printf("TOTAL BIAYA ASURANSI: Rp %.2f\n", total);
    printf("====================================\n");
}

int main() {
    char nama_petani[100];
    float nilai_tanggungan[3];
    float luas_tanah[3];
    int jenis_ladang[3];
    float biaya_ladang[3];
    int jumlah_ladang = 3;

    printf("Masukkan nama petani: ");
    scanf("%99s", nama_petani);
    printf("Berapa jenis ladang yang dimiliki (1 sampai 3)? ");
    scanf("%d", &jumlah_ladang);

    if (jumlah_ladang < 1 || jumlah_ladang > 3) {
        printf("Jumlah ladang tidak valid! Harus antara 1 sampai 3.\n");
    }
    for (int i = 0; i < jumlah_ladang; i++) {
        printf("\n=== Data Ladang ke-%d ===\n", i + 1);
        printf("Pilih jenis ladang:\n");
        printf("1. Ladang Pertanian\n");
        printf("2. Ladang Kacang Kedelai\n");
        printf("3. Ladang Bawang Merah\n");
        printf("4. Ladang Cabai\n");
        printf("5. Ladang Padi\n");
        printf("6. Ladang Singkong\n");
        printf("7. Ladang Jagung\n");
        printf("Masukkan pilihan (1 - 7): ");
        scanf("%d", &jenis_ladang[i]);

        printf("Masukkan nilai tanggungan per hektar: ");
        scanf("%f", &nilai_tanggungan[i]);

        printf("Masukkan luas tanah (dalam hektar): ");
        scanf("%f", &luas_tanah[i]);

        switch (jenis_ladang[i]) {
            case 1:
                biaya_ladang[i] = ladang_pertanian(nilai_tanggungan[i], luas_tanah[i]);
                break;
            case 2:
                biaya_ladang[i] = ladang_kacang_kedelai(nilai_tanggungan[i], luas_tanah[i]);
                break;
            case 3:
                biaya_ladang[i] = ladang_bawang_merah(nilai_tanggungan[i], luas_tanah[i]);
                break;
            case 4:
                biaya_ladang[i] = ladang_cabai(nilai_tanggungan[i], luas_tanah[i]);
                break;
            case 5:
                biaya_ladang[i] = ladang_padi(nilai_tanggungan[i], luas_tanah[i]);
                break;
            case 6:
                biaya_ladang[i] = ladang_singkong(nilai_tanggungan[i], luas_tanah[i]);
                break;
            case 7:
                biaya_ladang[i] = ladang_jagung(nilai_tanggungan[i], luas_tanah[i]);
                break;
            default:
                printf("Jenis ladang tidak diketahui.\n");
                biaya_ladang[i] = 0;
        }
    }

    slip_pembayaran(nama_petani, jenis_ladang, biaya_ladang, jumlah_ladang);
    return 0;
}