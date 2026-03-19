#include <stdio.h>

int main(){
    int suhu[7];

    printf("===== INPUT SUHU SELAMA 7 HARI ======\n");
    for (int i = 0; i < 7; i++){
        printf("Hari ke-%d: ", i + 1);
        scanf("%d", &suhu[i]);
    }
    printf("\n");

    printf("\n===== SUHU SELAMA 7 HARI ======\n");
    for (int i = 0; i < 7; i++){
        printf("Hari ke-%d: %d\n", i + 1, suhu[i]);
    }
    
    int panas = suhu[0];
    int dingin = suhu[0];
    int jumlah = 0;
    for (int i = 1; i < 7; i++){
        if (suhu[i] > panas){
            dingin = suhu[i];
        }
        if (suhu[i] < panas){
            dingin = suhu[i];
        }
        jumlah += suhu[i];
    }
    float ratarata = jumlah / 7.0;
    printf("\n===== HASIL PERHITUNGAN ======\n");
    printf("Suhu paling panas\t: %d\n", panas);
    printf("suhu paling dingin\t: %d\n", dingin);
    printf("Rata-rata suhu\t\t: %.2f\n", ratarata);
    return 0;
}