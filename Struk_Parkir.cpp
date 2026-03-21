#include <stdio.h>
#include <string.h>

struct StrukParkir {
    char namaPelanggan[50];
    char jenisKendaraan[50];
    int lamaP;
};

int biayaP (char* jenisKendaraan, int lamaP) {
    int biaya = 0;

    if (strcmp(jenisKendaraan, "Mobil") == 0) {
        biaya = lamaP * 5000;
    } else if (strcmp(jenisKendaraan, "Motor") == 0) {
        biaya = lamaP * 2500;
    } else if (strcmp(jenisKendaraan, "Truck") == 0) {
        biaya = lamaP * 10000;
    } else {
        printf("Jenis kendaraan tidak valid.\n");
    }   
    
    if (lamaP > 5) {
            biaya *= 0.9;
        }

    return biaya;
}

int totalBiayaP(struct StrukParkir struk[], int jumlahKendaraan) {
    int totalBiaya = 0;
    for (int i = 0; i < jumlahKendaraan; i++) {
        totalBiaya += biayaP(struk[i].jenisKendaraan, struk[i].lamaP);
    }
    return totalBiaya;
}

void strukParkir(struct StrukParkir struk[], int jumlahKendaraan) {
    int totalBiaya = totalBiayaP(struk, jumlahKendaraan);
    
    FILE *file = fopen("struk_parkir.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("\n\n================ STRUK PARKIR =================\n");
    printf("Nama Pelanggan  : %s\n", struk[0].namaPelanggan);
    printf("-----------------------------------------------\n");

    fprintf(file, "\n\n================ STRUK PARKIR =================\n");
    fprintf(file, "Nama Pelanggan  : %s\n", struk[0].namaPelanggan);
    fprintf(file, "-----------------------------------------------\n");
    

    for (int i = 0; i < jumlahKendaraan; i++) {
        int biaya = biayaP(struk[i].jenisKendaraan, struk[i].lamaP);
        
        printf("\nKendaraan ke-%d  : %s\n", i + 1, struk[i].jenisKendaraan);
        printf("Lama Parkir     : %d\n", struk[i].lamaP);
        printf("Biaya Parkir    : %d\n", (biaya));

        fprintf(file, "\nKendaraan ke-%d  : %s\n", i + 1, struk[i].jenisKendaraan);
        fprintf(file, "Lama Parkir     : %d jam\n", struk[i].lamaP);
        fprintf(file, "Biaya Parkir    : %d\n", biaya);
    }

    printf("\n-----------------------------------------------\n");
    printf("Total Biaya Parkir  : %d\n", totalBiaya);

    fprintf(file, "\n-----------------------------------------------\n");
    fprintf(file, "Total Biaya Parkir  : %d\n", totalBiaya);
    
    fclose(file);   
    
}

int main() {
    struct StrukParkir struk[100];
    char namaPelanggan[50];
    int jumlahKendaraan;
    
    printf("Masukkan nama pelanggan: ");
    scanf(" %49[^\n]", (namaPelanggan));

    printf("Masukkan jumlah kendaraan yang parkir: ");
    scanf("%d", &jumlahKendaraan);

    while (jumlahKendaraan >= 4 || jumlahKendaraan <= 0) {
        printf("Jumlah kendaraan harus antara 1 dan 3. Silakan masukkan kembali: ");
        scanf("%d", &jumlahKendaraan);
    }

    for (int i = 0; i < jumlahKendaraan; i++) {
        printf("Masukkan jenis kendaraan ke-%d (Mobil/Motor/Truck): ", i + 1);
        scanf(" %s", struk[i].jenisKendaraan);
        
        printf("Masukkan lama parkir (dalam jam) untuk kendaraan ke-%d: ", i + 1);
        scanf("%d", &struk[i].lamaP);
    }

    strcpy(struk[0].namaPelanggan, namaPelanggan);
    strukParkir(struk, jumlahKendaraan);

    return 0;
}