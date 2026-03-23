#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nama[50];
    int skor;
    int level;
} Pemain;

#define MAKS_PEMAIN 100 
Pemain daftarPemain[MAKS_PEMAIN];
int jumlahPemain = 0;
bool gameOver;
const int lebar = 20;
const int tinggi = 17;
int x, y, fruitX, fruitY, score;
int ekorX[100], ekorY[100];
int panjang_ular;
int level = 1;
int delay = 300;
char pemainSekarang[50];

enum eArah { STOP = 0, KIRI, KANAN, ATAS, BAWAH };
eArah arah;

bool loginAdmin() {
    char user[20], pass[20];
    printf("=== LOGIN ADMIN ===\n");
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    if (strcmp(user, "Admin") == 0 && strcmp(pass, "1234") == 0) { // mengecek 
        printf("Login berhasil!\n\n");
        return true;
    } else {
        printf("Login gagal! Coba lagi.\n\n");
        return false;
    }
}

void bacaDataDariFile() {
    FILE *file = fopen("data_pemain.txt", "r"); // ini adalah membuka file untuk membaca data pemain
    if (file == NULL) {
        jumlahPemain = 0;
        return;
    }

    jumlahPemain = 0;
    while (fscanf(file, "%s %d %d", daftarPemain[jumlahPemain].nama, &daftarPemain[jumlahPemain].skor, &daftarPemain[jumlahPemain].level) == 3) {
        jumlahPemain++;
    }
    fclose(file); // ini adalah menutup file setelah membaca data pemain
}

void tulisDataKeFile() { // fungsi untuk menulis data pemain ke file
    FILE *file = fopen("data_pemain.txt", "w");
    for (int i = 0; i < jumlahPemain; i++) {
        fprintf(file, "%s %d %d\n", daftarPemain[i].nama,
                daftarPemain[i].skor, daftarPemain[i].level);
    }
    fclose(file);
}

void simpanHasilPemain(char nama[], int skor, int level) {
    if (jumlahPemain < MAKS_PEMAIN) {
        strcpy(daftarPemain[jumlahPemain].nama, nama);
        daftarPemain[jumlahPemain].skor = skor;
        daftarPemain[jumlahPemain].level = level;
        jumlahPemain++;
    }
}

void tampilkanData() {
    printf("\n=== DATA PEMAIN ===\n");
    if (jumlahPemain == 0) {
        printf("Tidak ada data.\n");
    } else {
        for (int i = 0; i < jumlahPemain; i++) {
            printf("%d. %s || Skor: %d || Level: %d\n",
                i + 1,
                daftarPemain[i].nama,
                daftarPemain[i].skor,
                daftarPemain[i].level);
        }
    }
}

void cariData() {
    char cari[50];
    printf("Masukkan nama pemain yang dicari: ");
    scanf("%s", cari);

    bool ditemukan = false;
    for (int i = 0; i < jumlahPemain; i++) {
        if (strcmp(daftarPemain[i].nama, cari) == 0) {
            printf("Ditemukan: %s - Skor: %d, Level: %d\n",
                daftarPemain[i].nama,
                daftarPemain[i].skor,
                daftarPemain[i].level);
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        printf("Pemain tidak ditemukan!\n");
    }
}

void mulai_permainan() {
    gameOver = false;
    arah = STOP;
    x = lebar / 2;
    y = tinggi / 2;
    fruitX = rand() % lebar;
    fruitY = rand() % tinggi;
    score = 0;
    panjang_ular = 0;
    level = 1;
    delay = 300;
}

void layar() {
    system("cls");
    for (int i = 0; i < lebar + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < tinggi; i++) {
        for (int j = 0; j < lebar; j++) {
            if (j == 0) printf("#");
            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else {
                bool print = false;
                for (int k = 0; k < panjang_ular; k++) {
                    if (ekorX[k] == j && ekorY[k] == i) {
                        printf("o");
                        print = true;
                        break;
                    }
                }
                if (!print) printf(" ");
            }
            if (j == lebar - 1) printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < lebar + 2; i++) printf("#");
    printf("\nScore: %d\tLevel: %d\n", score, level);
}

void arah_ular() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': 
                arah = KIRI; 
                break;
            case 'd': 
                arah = KANAN; 
                break;
            case 'w': 
                arah = ATAS; 
                break;
            case 's': 
                arah = BAWAH; 
                break;
            case 'x': 
                gameOver = 
                true; 
                break;
        }
    }
}

void logic() {
    int sebelumX = ekorX[0];
    int sebelumY = ekorY[0];
    int sebelum2X, sebelum2Y;
    ekorX[0] = x;
    ekorY[0] = y;

    for (int i = 1; i < panjang_ular; i++) {
        sebelum2X = ekorX[i];
        sebelum2Y = ekorY[i];
        ekorX[i] = sebelumX;
        ekorY[i] = sebelumY;
        sebelumX = sebelum2X;
        sebelumY = sebelum2Y;
    }

    switch (arah) {
        case KIRI:  
            x--; 
            break;
        case KANAN: 
            x++; 
            break;
        case ATAS:  
            y--; 
            break;
        case BAWAH: 
            y++; 
            break;
    }

    if (x >= lebar || x < 0 || y >= tinggi || y < 0) gameOver = true;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % lebar;
        fruitY = rand() % tinggi;
        panjang_ular++;

        if (score % 50 == 0) {
            level++;
            if (delay > 100) delay -= 40;
            printf("\nNaik ke Level %d!\n", level);
            Sleep(1000);
        }
    }

    for (int i = 0; i < panjang_ular; i++) {
        if (ekorX[i] == x && ekorY[i] == y) gameOver = true;
    }
}

void menu() {
    int pilihan;
    do {
        printf("\n=== MENU UTAMA ===\n");
        printf("1. Main Game\n");
        printf("2. Lihat Data Pemain\n");
        printf("3. Cari Pemain\n");
        printf("4. Keluar program\n");
        printf("Pilih (1-4): ");
        scanf("%d", &pilihan);

        switch (pilihan) { // mengecek pilihan untuk menampilkan menu sesuai pilihan
            case 1:
                printf("Masukkan nama pemain: ");
                scanf("%s", pemainSekarang);
                mulai_permainan();
                while (!gameOver) {
                    layar();
                    arah_ular();
                    logic();
                    Sleep(delay);
                }
                printf("\nGAME OVER!\nSkor: %d | Level: %d\n", score, level);
                simpanHasilPemain(pemainSekarang, score, level);
                tulisDataKeFile();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                cariData();
                break;
            case 4:
                tulisDataKeFile();
                printf("Keluar program...\n");
                break;
            default:
                printf("Pilihan tidak tersedia!\n");
        }
    } while (pilihan != 4);
}

int main() {
    srand(time(0));
    system("cls");

    printf(" === HUNGRY SNAKE BOARD GAME ===\n\n");

    while (!loginAdmin());

    bacaDataDariFile();
    menu();

    return 0;
}