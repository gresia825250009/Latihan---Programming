#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define BARIS 15
#define KOLOM 6

char bangku[BARIS][KOLOM];
const char* FILE_KURSI = "Kursi.txt";
const char* FILE_HARGA = "Harga.txt";
const char* FILE_BAGASI = "Bagasi.txt";

void simpanKursi() {
    FILE *f = fopen(FILE_KURSI, "w");
    if (!f) 
        return;
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            fprintf(f, "%c ", bangku[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
void bacaKursi() {
    FILE *f = fopen(FILE_KURSI, "r");
    if (!f) {
        for (int i = 0; i < BARIS; i++)
            for (int j = 0; j < KOLOM; j++)
                bangku[i][j] = '_';
        simpanKursi();
        return;
    }
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            if (fscanf(f, " %c", &bangku[i][j]) != 1) bangku[i][j] = '_';
        }
    }
    fclose(f);
}

int hargaTiketKelasFile(const char *kelas) {
    FILE *f = fopen("Harga.txt", "r");
    if (!f) {
        if (strcmp(kelas, "First Class") == 0) 
            return 1500000;
            if (strcmp(kelas, "Business Class") == 0) 
                return 1000000;
                if (strcmp(kelas, "Economy Class") == 0)
                    return 600000;
    }

    char line[200];
    char nama[100];
    int harga;
    while (fgets(line, sizeof(line), f))  {
        if (sscanf(line, " %[^=]=%d", nama, &harga) == 2) {
            if (strcmp(nama, kelas) == 0) {
                fclose(f);
                return harga;
            }
        }
    }
    fclose(f);
    if (strcmp(kelas, "First Class") == 0) 
        return 1500000;
    if (strcmp(kelas, "Business Class") == 0) 
        return 1000000;
        return 600000;
}


void simpanHargaKursi() {
    FILE *f = fopen(FILE_HARGA, "r");
    if (f) { 
        fclose(f); 
        return; 
    }f = fopen(FILE_HARGA, "w");
        if (!f) 
        return;

    fprintf(f, "First Class = 1500000\n"
    "Business Class = 1000000\n" "Economy Class = 600000\n");
    fclose(f);
}

int hargaBagasiFile(char kode) {
    FILE *f = fopen("Bagasi.txt", "r");
    if (!f) {
        if (toupper(kode) == 'A') 
            return 100000;
        if (toupper(kode) == 'B') 
            return 175000;
        if (toupper(kode) == 'C') 
            return 300000;
        return 0;
    }

    char line[100];
    char kodeFile;
    int harga;
    while (fgets(line, sizeof(line), f)) {
        if (sscanf(line, " %c=%d", &kodeFile, &harga) == 2) {
            if (toupper(kodeFile) == toupper(kode)) {
                fclose(f);
                return harga;
            }
        }
    }
    fclose(f);
    if (toupper(kode) == 'A') 
        return 100000;
    if (toupper(kode) == 'B') 
        return 175000;
    if (toupper(kode) == 'C') 
        return 300000;
    return 0;
}


void simpanFileBagasi() {
    FILE *f = fopen(FILE_BAGASI, "r");
    if (f) { 
        fclose(f);
        return; 
    } f = fopen(FILE_BAGASI, "w");
        if (!f) 
        return;

    fprintf(f, "A = 100000\n"
        "B = 175000\n" "C = 300000\n");
    fclose(f);
}

const char* kelasDariBaris(int nomorBaris) {
    if (nomorBaris >= 1 && nomorBaris <= 2) 
        return "First Class";
    if (nomorBaris >= 3 && nomorBaris <= 5) 
        return "Business Class";
        return "Economy Class";
}

int hargaKelasDefaultByBaris(int nomorBaris) {
    if (nomorBaris >= 1 && nomorBaris <= 2) 
        return 1500000;
    if (nomorBaris >= 3 && nomorBaris <= 5) 
        return 1000000;
        return 600000;
}

void printStruk(char nama[], int banyakPemesanan, const char* kelas, int barisKursiArr[], char kolomKursiArr[], int hargaPerKursi, int hargaBagasiPerTiket, int totalBayar) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("\n====================== STRUK PEMBAYARAN ======================\n");
    printf("Nama               : %s\n", nama);
    printf("Banyak Pemesanan   : %d tiket\n", banyakPemesanan);
    printf("Kelas Penerbangan  : %s\n", kelas);
    printf("Nomor Kursi        : ");
    for (int i = 0; i < banyakPemesanan; i++) {
        printf("%d%c", barisKursiArr[i], kolomKursiArr[i]);
        if (i < banyakPemesanan - 1) 
            printf(", ");
    }
    printf("\n");
    if (hargaBagasiPerTiket > 0)
        printf("Tambahan Bagasi    : Rp %d per tiket\n", hargaBagasiPerTiket);
    else
        printf("Tambahan Bagasi    : Tidak ada\n");
        printf("Harga per Kursi    : Rp %d\n", hargaPerKursi);
        printf("Waktu Pemesanan    : %02d-%02d-%04d %02d:%02d:%02d\n", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min, t->tm_sec);
        printf("--------------------------------------------------------------\n");
        printf("TOTAL PEMBAYARAN   : Rp %d\n", totalBayar);
        printf("==============================================================\n");
        printf("Terima kasih sudah memesan tiket!\n\n");
}

void tampilKursi() {
    printf("\nDenah Kursi (_ = kosong, X = terisi, A/B/C = terisi+bagasi)\n\n");
    printf("    A B C D E F\n");
    for (int i = 0; i < BARIS; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < KOLOM; j++) {
            printf("%c ", bangku[i][j]);
        }
        printf("\n");
    }
}
void pesanKursi() {
    int banyak;
    printf("\nBerapa tiket yang mau dipesan? ");
    if (scanf("%d", &banyak) != 1 || banyak <= 0) {
        while (getchar() != '\n');
            printf("Input tidak valid.\n");
            return;
    }

    char nama[100];
    int barisArr[100];
    char kolomArr[100];
    int hargaPerKursi = 0;
    int hargaBagasiPerTiket = 0;
    int totalBayar = 0;

    printf("Masukkan nama pemesan: ");
    scanf(" %[^\n]", nama);

    printf("\nDaftar harga kelas (lihat file %s):\n", FILE_HARGA);
    FILE *f = fopen(FILE_HARGA, "r");
    if (f) {
        char line[200];
        while (fgets(line, sizeof(line), f)) printf("%s", line);
        fclose(f);
    } else {
        printf("Kelas Utama (First Class) : 1500000 (Baris 1 - 2)\nKelas Bisnis (Business Class) : 1000000 (Baris 3 - 5)\nKelas Ekonomi (Economy Class) : 600000 (Baris 6 - 15)\n");
    }

    for (int i = 0; i < banyak; i++) {
        int br;
        char kol;
        printf("\n-- Pemesanan ke-%d --\n", i + 1);

        printf("Masukkan nomor baris (1-%d): ", BARIS);
        if (scanf("%d", &br) != 1) { 
            while(getchar()!='\n'); 
                printf("Input salah.\n"); 
                i--; 
                continue; }
        if (br < 1 || br > BARIS) { 
            printf("Nomor baris di luar jangkauan.\n"); 
            i--; 
            continue; 
        }

        printf("Masukkan kolom (A-F): ");
        scanf(" %c", &kol);
        kol = toupper(kol);
        if (kol < 'A' || kol > 'F') { 
            printf("Kolom tidak valid.\n"); 
            i--; 
            continue; 
        }

        int ji = kol - 'A';
        if (bangku[br - 1][ji] != '_') {
            printf("Kursi sudah terisi, pilih lain.\n");
            i--; continue;
        }

        const char *kelas = kelasDariBaris(br);
        hargaPerKursi = hargaTiketKelasFile(kelas);

        char tambahBagasi = 'N';
        int hargaBag = 0;
        printf("Tambah bagasi untuk tiket ini? (y/n): ");
        scanf(" %c", &tambahBagasi);
        if (toupper(tambahBagasi) == 'Y') {
            char kode;
            printf("\n====== Bagasi ======\n- A: 0-5kg = Rp 100.000\n- B: >5-10kg = Rp 175.000\n- C: >10-20kg = Rp 300.000)\nPilih kode bagasi (A/B/C): ");
            scanf(" %c", &kode);
            kode = toupper(kode);
            hargaBag = hargaBagasiFile(kode);
            bangku[br - 1][ji] = kode;
        } else {
            bangku[br - 1][ji] = 'X';
        }

        barisArr[i] = br;
        kolomArr[i] = kol;
        hargaBagasiPerTiket = hargaBag; 

        totalBayar += hargaPerKursi + hargaBag;

        simpanKursi();
    }

    const char *kelasUtama = kelasDariBaris(barisArr[0]);
    printStruk(nama, banyak, kelasUtama, barisArr, kolomArr, hargaPerKursi, hargaBagasiPerTiket, totalBayar);
}

void batalPemesanan() {
    int br;
    char kol;
    tampilKursi();
    
    printf("\nMasukkan baris yang mau dibatalkan: ");
    if (scanf("%d", &br) != 1) { 
        while(getchar()!='\n'); 
            printf("Input salah.\n"); 
            return; 
    }
    
    printf("Masukkan kolom yang mau dibatalkan (A-F): ");
    scanf(" %c", &kol);
    kol = toupper(kol);
    
    if (br < 1 || br > BARIS || kol < 'A' || kol > 'F') { 
        printf("Input tidak valid.\n"); 
        return; 
    }
    
    int ji = kol - 'A';
    if (bangku[br - 1][ji] == '_') {
        printf("Kursi ini sudah kosong.\n");
    } else {
        bangku[br - 1][ji] = '_';
        simpanKursi();
        printf("Pembatalan berhasil.\n");
    }
}

void rekomendasiKursi() {
    int pilih, mulai, akhir;
    printf("\nPilih kelas untuk rekomendasi:\n");
    printf("1. First Class (Baris 1-2)\n");
    printf("2. Business Class (Baris 3-5)\n");
    printf("3. Economy Class (Baris 6-15)\n");
    printf("Pilihan: ");
    if (scanf("%d", &pilih) != 1) { 
        while(getchar()!='\n'); 
        printf("Input salah.\n"); 
        return; 
    } if (pilih == 1) { 
        mulai = 1; 
        akhir = 2; 
    } else if (pilih == 2) { 
        mulai = 3; 
        akhir = 5; 
    } else { 
        mulai = 6; 
        akhir = 15; 
    }

    printf("\nRekomendasi kursi kosong (paling depan per kelas):\n");
    for (int i = mulai - 1; i <= akhir - 1; i++) {
        for (int j = 0; j < KOLOM; j++) {
            if (bangku[i][j] == '_') {
                printf("Rekomendasi: %d%c\n", i + 1, 'A' + j);
                return;
            }
        }
    }
    printf("Maaf, tidak ada kursi kosong di kelas ini.\n");
}

void statistikKursi() {
    int kursiIsi = 0, kursiKosong = 0;
    long long totalPendapatan = 0;

    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            if (bangku[i][j] == '_') {
                kursiKosong++;
            } else {
                kursiIsi++;
                int harga = hargaKelasDefaultByBaris(i + 1);
                totalPendapatan += harga;
            }
        }
    }

    int jumlahKursi = BARIS * KOLOM;
    printf("\n================== Statistik Kursi & Pendapatan ==================\n");
    printf("Total kursi         : %d\n", jumlahKursi);
    printf("Kursi terisi        : %d\n", kursiIsi);
    printf("Kursi kosong        : %d\n", kursiKosong);
    printf("Persentase terisi   : %.2f%%\n", (kursiIsi / (float)jumlahKursi) * 100);
    printf("---------------------------------------------------------------\n");
    printf("Total pendapatan (perkiraan) : Rp %lld\n", totalPendapatan);
    printf("=================================================================\n");
}
void resetKursi() {
    char user[50], pass[50];
    printf("\nMasukkan username admin: ");
    scanf(" %49s", user);
    printf("Masukkan password admin: ");
    scanf(" %49s", pass);
    if (strcmp(user, "Admin") == 0 && strcmp(pass, "1234") == 0) {
        for (int i = 0; i < BARIS; i++)
            for (int j = 0; j < KOLOM; j++)
                bangku[i][j] = '_';
        simpanKursi();
        printf("Reset berhasil. Semua kursi kini kosong.\n");
    } else {
        printf("Username atau password salah.\n");
    }
}

void menuUtama() {
    int pilih;
    bacaKursi();
    do {
        printf("\n===== MENU UTAMA =====\n");
        printf("1. Tampilkan Kursi\n");
        printf("2. Pesan Kursi\n");
        printf("3. Batalkan Pemesanan\n");
        printf("4. Rekomendasi Kursi\n");
        printf("5. Statistik & Pendapatan\n");
        printf("6. Reset Data (Admin)\n");
        printf("7. Keluar\n");
        printf("Pilih (1-7): ");
        if (scanf("%d", &pilih) != 1) { 
            while(getchar()!='\n'); 
            printf("Input salah.\n"); 
            continue; }

        switch (pilih) {
            case 1: 
                tampilKursi(); 
                break;
            case 2: 
                pesanKursi(); 
                break;
            case 3: 
                batalPemesanan(); 
                break;
            case 4: 
                rekomendasiKursi(); 
                break;
            case 5: 
                statistikKursi(); 
                break;
            case 6: 
                resetKursi(); 
                break;
            case 7: 
                printf("Terima kasih. Sampai jumpa!\n"); 
                break;
            default: 
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (pilih != 7);
}

int main() {
    printf("Program Pemesanan Kursi Pesawat\n");
    printf("File yang dipakai: %s, %s, %s\n", FILE_KURSI, FILE_HARGA, FILE_BAGASI);

    
    simpanFileBagasi();
    simpanHargaKursi();

    menuUtama();
    return 0;
}
