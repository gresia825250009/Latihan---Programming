#include <stdio.h>

void urutArr(int array[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int sementara = array[j]; 
                array[j] = array[j + 1];
                array[j + 1] = sementara;
            }
        }
    }
}

int main() {
    printf("================== Mengurutkan Array ==================\n");
    int data[100];
    int n = sizeof(data) / sizeof(data[0]);
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Masukkan data ke-%d: ", i + 1);
        scanf("%d", &data[i]);
    }
    
    printf("\nData sebelum diurutkan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    urutArr(data, n);
    
    printf("Data setelah diurutkan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}