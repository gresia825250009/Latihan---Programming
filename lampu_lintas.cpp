#include <stdio.h>

int main(){
    char warna_lampu;

    printf("ooooo-- LAMPU LALU LINTAS --ooooo\n");
    printf("- Merah --> M\n- Kuning --> K\n- Hijau --> H\n");

    printf("Masukan warna lampu lalu lintas (M/K/H): ");
    scanf("%s", &warna_lampu);

    switch (warna_lampu){
    case 'M':
        printf("Lampu lalu lintas MERAH, berhenti!");
        break;
    case 'K':
        printf("Lampu lalu lintas KUNING, pelan-pelan!");
        break;
    case 'H':
        printf("Lampur lalu lintas HIJAU, jalan!");
        break;
    default:
        printf("Lampu lalu lintas tidak berfungsi");
        break;
    }
    
    return 0;
}