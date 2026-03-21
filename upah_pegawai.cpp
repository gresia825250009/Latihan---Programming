#include <stdio.h>

int main(){
    int jam_kerja;
    int upah_Per_Jam;
    printf("++++++++++===== MENGHITUNG UPAH KERJA =====++++++++++\n");
    printf("\n***PENULISAN HARGA TIDAK MEMAKAI TITIK***\n");
    printf("\nAnda bekerja berapa lama dalam sehari (per jam)? ");
    scanf("%d", &jam_kerja);
    printf("\nBerapa upah anda per jam? ");
    scanf("%d", &upah_Per_Jam);

    int upah_harian = jam_kerja * upah_Per_Jam;
    int upah_seminggu = upah_harian * 7;

    printf("\nUpah kerja anda dalam sehari dengan\n- bekerja selama %d jam\n- Upah perjamnya Rp%d\nJadi, upah perhari Rp%d dan upah kerja dalam seminggu Rp%d", jam_kerja, upah_Per_Jam, upah_harian, upah_seminggu);

    return 0;
}