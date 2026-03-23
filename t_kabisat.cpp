#include <stdio.h>

int main(){
    int tahun;

    printf("====== TAHUN KABISAT =====\n");
    printf("Masukan tahun: ");
    scanf("%d", &tahun);

    if (tahun % 400 == 0){
        printf("\nTahun %d adalah tahun kabisat.", tahun);
    } else if (tahun % 100 == 0){
        printf("\nTahun %d adalah tahun kabisat.", tahun);
    } else if(tahun % 4 == 0){
        printf("\nTahun %d adalah bukan tahun kabisat.", tahun);
    } else{
        printf("\nTahun %d adalah bukan tahun kabisat.", tahun);
    }
    
    return 0;
}