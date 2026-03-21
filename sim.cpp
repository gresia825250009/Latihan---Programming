#include <stdio.h>

int main(){
    int umur;
    int nilai;

    printf("======----- APLIKASI SIM -----=====\n");
    printf("\nMasukan umur anda: ");
    scanf("%d", &umur);

    printf("Masukan nilai anda: ");
    scanf("%d", &nilai);
  
    if (umur >= 16){
        printf("- Umur %d tahun memenuhi.\n", umur);
        if (nilai >= 75){
            printf("- Nilai %d memenuhi dan lulus ujian teori dan praktik.\n", nilai);
        }
            printf ("\nSELAMAT ANDA LULUS KELAYAKAN APLIKASI SIM!!");
    }else{
        printf("Silahkan coba lagi tahun depan!!\nPastikan nilai ujian teori dan praktik serta umur anda memenuhi.");
    }
    
    return 0;
}