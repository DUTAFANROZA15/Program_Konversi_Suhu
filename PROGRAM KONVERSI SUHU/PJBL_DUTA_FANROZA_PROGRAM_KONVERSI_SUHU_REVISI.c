#include <stdio.h>
#include <time.h>

int main() {
    // Variabel untuk mencatat waktu mulai dan selesai
    clock_t start_time, end_time;
    double execution_time;

    // Deklarasi variabel
    FILE *inputFile, *outputFile;
    float suhu;
    char satuan;
    float hasil;
    char satuanHasil;

    // Catat waktu mulai
    start_time = clock();

    // Membuka file input_2.txt untuk membaca
    inputFile = fopen("input_2.txt", "r");
    if (inputFile == NULL) {
        printf("File input_2.txt tidak dapat dibuka!\n");
        return 1;
    }

    // Membuka atau membuat file output_2.txt untuk menulis
    outputFile = fopen("output_2.txt", "w");
    if (outputFile == NULL) {
        printf("File output_2.txt tidak dapat dibuat!\n");
        fclose(inputFile);
        return 1;
    }

    // Membaca setiap baris dari file input dan memproses operasinya
    while (fscanf(inputFile, "%f%c", &suhu, &satuan) != EOF) {
        if (satuan == 'C' || satuan == 'c') {
            hasil = (suhu * 9 / 5) + 32;
            satuanHasil = 'F';
            fprintf(outputFile, "%.2f%c = %.2f%c\n", suhu, 'C', hasil,satuanHasil); 
        } else if (satuan == 'F' || satuan == 'f') {
            hasil = (suhu - 32) * 5 / 9;
            satuanHasil = 'C';
            fprintf(outputFile, "%.2f%c = %.2f%c\n", suhu, 'F', hasil, satuanHasil);
        } else {
            fprintf(outputFile, "Error: Format tidak valid '%c'\n", satuan);
        }
    }

    // Menutup file
    fclose(inputFile);
    fclose(outputFile);

    // Catat waktu selesai
    end_time = clock();

    // Hitung waktu eksekusi dalam detik
    execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Tampilkan hasil waktu eksekusi
    printf("Proses selesai. Hasil disimpan di output_2.txt\n");
    printf("Waktu eksekusi: %.6f detik\n", execution_time);

    return 0;
}