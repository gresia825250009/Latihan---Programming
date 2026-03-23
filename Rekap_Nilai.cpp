#include <stdio.h>

int nilai_tugas, nilai_uts, nilai_uas, jumlah_mahasiswa;
int nilai_akhir, nilai_remedial, sblm_remed;
int maxNilai = 0, minNilai = 0;
int totalNilai = 0, rata_rata;
int nilaiA = 0, nilaiB = 0, nilaiC = 0, nilaiD = 0;
int i;

int rekapNilai() {
    for(i = 0; i < jumlah_mahasiswa; i++) {
        printf("\nMahasiswa ke-%d\n", i+1);
        printf("Masukan nilai tugas: ");
        scanf("%d", &nilai_tugas);
        printf("Masukan nilai UTS: ");
        scanf("%d", &nilai_uts);
        printf("Masukan nilai UAS: ");
        scanf("%d", &nilai_uas);

        nilai_akhir = (nilai_tugas * 0.3) + (nilai_uts * 0.3) + (nilai_uas * 0.4);
        printf("Nilai akhir: %d\n", nilai_akhir);
        sblm_remed = nilai_akhir;

    }

    return nilai_akhir;
}

void remedial() {
    if (nilai_akhir <= 60) {
        printf("Masukan nilai remedial: ");
        scanf("%d", &nilai_remedial);
        if (nilai_remedial > nilai_akhir) {
            nilai_akhir = nilai_remedial;
        } else {
            nilai_akhir = sblm_remed;
        }
    printf("Nilai sebelum remedial: %d\n", sblm_remed);
    }
}

int rataRata() {
    
    for (i = 0; i < jumlah_mahasiswa; i++) {
        if (i == 0) {
            maxNilai = nilai_akhir;
            minNilai = nilai_akhir;
        } else {
            if (nilai_akhir > maxNilai) 
                maxNilai = nilai_remedial;
            if (nilai_akhir < minNilai) 
                minNilai = nilai_akhir;
        }

        totalNilai += nilai_akhir;

        if (nilai_akhir >= 80) {
            nilaiA++;
        } else if (nilai_akhir >= 70) {
            nilaiB++;
        } else if (nilai_akhir >= 60) {
            nilaiC++;
        } else {
            nilaiD++;
        }
    }

    rata_rata = totalNilai / jumlah_mahasiswa;

}

void output() {
    printf("Masukan jumlah mahasiswa: ");
    scanf("%d", &jumlah_mahasiswa);

    rekapNilai();
    remedial();
    rataRata();

    printf("\n===== REKAP NILAI =====\n");
    printf("Nilai tertinggi: %d\n", maxNilai);
    printf("Nilai terendah: %d\n", minNilai);
    printf("Rata-rata nilai: %d\n", rata_rata);
    printf("Jumlah nilai A: %d\n", nilaiA);
    printf("Jumlah nilai B: %d\n", nilaiB);
    printf("Jumlah nilai C: %d\n", nilaiC);
    printf("Jumlah nilai D: %d\n", nilaiD);
}