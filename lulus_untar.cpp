#include <stdio.h>

int main(){
    int sks, skpi, lama_studi;
    float ipk;
    char skripsi, ilmiah, sertifikasi;
    int lulus = 1;

    printf("-------------- PROGRAM KELULUSAN MAHASISWA UNTAR ------------\n");
    printf("\nMasukan jumlah SKS: ");
    scanf("%d", &sks);
    printf("\nMasukan IPK: ");
    scanf("%f", &ipk);
    printf("\nMasukan lama masa studi: ");
    scanf("%d", &lama_studi);
    printf("\nApakah lulus skripsi (y/n): ");
    scanf("%s", &skripsi);
    printf("\nSudah memiliki tulisan ilmiah (y/n): ");
    scanf("%s", &ilmiah);
    printf("\nMasukan jumlah poin SKPI: ");
    scanf("%d", &skpi);
    printf("\nSudah memiliki sertifikasi (y/n): ");
    scanf("%s", &sertifikasi);

    printf("\n-------------------------------------------------\n");
    if(sks >= 144){
        printf("- Jumlah SKS anda %d memenuhi kelulusan.\n", sks);
    } else{
        printf("- Jumlah SKS anda %d belum memenuhi kelulusan.\n", sks);
        lulus = 0;
    }
    
    if(ipk >= 2.4 && ipk <= 4.0){
        printf("- IPK anda %.1f memenuhi kelulusan.\n", ipk);
    } else{
        printf("- IPK anda %.1f belum memenuhi kelulusan.\n", ipk);
        lulus = 0;
    }
    
    if(lama_studi <= 16){
        printf("- Lama Masa studi anda %d semester, memenuhi kelulusan.\n", lama_studi);
    } else{
        printf("- Lama masa studi anda %d semester, belum memenuhi kelulusan.\n", lama_studi);
        lulus = 0;
    }
    
    if(skripsi != 'n'){
        printf("- Skripsi anda lulus.\n");
    } else{
        printf("- Skripsi anda tidak lulus.\n");
        lulus = 0;
    }
    
    if(skpi >= 150){
        printf("- Jumlah point SKPI anda %d, lulus\n", skpi);
    } else{
        printf("- Jumlah point SKPI anda %d, belum memenuhi kelulusan.\n", skpi);
        lulus = 0;
    }
    
    if(sertifikasi == 'y'){
        printf("- Sudah memiliki sertifikasi.\n");
    } else{
        printf("- Belum memiliki sertifikasi.\n");
        lulus = 0;
    }
    
    printf("\n==================== HASIL KELULUSAN =====================\n");
    if (lulus == 1){
        printf("\nSelamat, anda dinyatakan LULUS sebagai mahasiswa Universitas Tarumanegara!");
    } else{
        printf("\nMaaf, anda TIDAK LULUS!\nAnda belum memenuhi syarat kelulusan sebagai berikut:\n1. SKS minimum 144.\n2. IPK minimum 2.4.\n3. Lama masa studi maksimal 16 semester.\n4. Wajib lulus skripsi.\n5. Sudah memiliki tulisan ilmiah.\n6. Memiliki point SKPI sejumlah minimal 150.\n7. Sudah memiliki sertifikasi.");
    }
    
    return 0;
}