#include <stdio.h>

int main(){
    // Deklarasi variabel
    int pilihan;
    float celcius,fahrenheit;
    char lanjut;

    // Perulangan ketika menginput pilihan konversi yang tidak valid 
    do{
        // Tampilan menu dan input pilihan konversi 
        printf("\n=== PROGRAM KONVERSI SUHU ===\n");
        printf("Menu Pilihan Konversi Suhu: \n");
        printf("1. Celcius ke Fahrenheit\n");
        printf("2. Fahrenheit ke Celcius\n");
        printf("Masukkan Pilihan konversi Suhu: ");
        scanf("%d", &pilihan);

        // Proses sesuai pilihan yang diinput
        if(pilihan == 1) {
            printf("Masukkan Suhu dalam Celcius (maksimal 3 digit): ");
            scanf("%f", &celcius);

            if(celcius > 999 || celcius < -999) {
                printf("Suhu tidak valid! Masukkan suhu antara -999 dan 999. \n");
            } else {
            fahrenheit = (celcius * 9 / 5) + 32 ;
            printf("Hasil: %.2f celsius = %.2f fahrenheit\n", celcius,fahrenheit);
            }

        } else if (pilihan == 2) {
            printf("Masukkan Suhu dalam Fahrenheit : ");
            scanf("%f", &fahrenheit);

            if(fahrenheit > 999 || fahrenheit < -999) {
                printf("Suhu tidak valid! Masukkan suhu antara -999 dan 999.\n");
            } else {
            celcius = (fahrenheit - 32) * 5 /9 ;
            printf("Hasil: %.2f fahrenheit = %.2f celcius\n", fahrenheit,celcius);
            }

        } else {
            printf("Pilihan tidak valid! Silahkan pilih 1 atau 2\n");
        }

        printf("Apakah Anda masih ingin melanjutkan (y/t): ");
        scanf(" %c", &lanjut);

    } while (lanjut == 'y' || lanjut == 'Y');
    
    return 0;
}