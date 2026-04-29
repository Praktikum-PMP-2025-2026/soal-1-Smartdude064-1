/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Faiz Azmi Irwan (13224040)
 *   Nama File           : soal1_prak.c
 *   Deskripsi           : Program yang berfungsi dalam sorting artefak dengan mengimplementasikan structure dimana artefak harus di-sort
 *                         berdasarkan kategori (alfabetis naik), tahun naik, nilai turun, nama (alfabetis naik) sehingga artefak terurut
 *                         dengan rapih sesuai spesifikasi soal.
 * 
 */

#include <stdio.h>
#include <string.h>

// deklarasi variabel struct
typedef struct {
    char nama[101];
    char kategori[101];
    int tahun;
    int nilai;
} Artefak;

// deklarasi array dari struct
Artefak array[10001];

// prosedur untuk melakukan sorting artefak menggunakan bubble sort
void sort_artefak(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int tukar = 0;

            // Aturan 1: kategori alfabetis naik
            if (strcmp(array[j].kategori, array[j+1].kategori) > 0) {
                tukar = 1;
            } 
            // Aturan 2: Jika kategori sama, tahun naik
            else if (strcmp(array[j].kategori, array[j+1].kategori) == 0) {
                // tahun lebih kecil diutamakan
                if (array[j].tahun > array[j+1].tahun) {
                    tukar = 1;
                } 
                // Aturan 3: Jika kategori dan tahun sama, nilai turun
                else if (array[j].tahun == array[j+1].tahun) {
                    // nilai lebih besar diutamakan
                    if (array[j].nilai < array[j+1].nilai) {
                        tukar = 1;
                    }
                    // Aturan 4: Jika kategori, tahun, dan nilai sama, nama alfabetis naik
                    else if (array[j].nilai == array[j+1].nilai) {
                        // alfabetis lebih awal diutamakan
                        if (strcmp(array[j].nama, array[j+1].nama) > 0) {
                        tukar = 1;
                        } 
                    }
                    
                }
            }

            // Pertukaran posisi array
            if (tukar == 1) {
                Artefak temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// fungsi utama
int main() {
    // deklarasi variabel perulangan
    int N;
    scanf("%d ", &N);

    // looping input masing-masing artefak
    for (int i = 0; i < N; i++) {
        scanf("%s %s %d %d", array[i].nama, array[i].kategori, &array[i].tahun, &array[i].nilai); //Perbaikan 1: pada input integer tidak menggunakan tanda '&'
    }

    // Untuk verifikasi isi struct sesuai dengan inputnya
    /*for (int i = 0; i < N; i++) {
        printf("%s %s %d %d\n", array[i].nama, array[i].kategori, array[i].tahun, array[i].nilai);
    }
    printf("============================================\n");*/

    // pemanggilan prosedur sorting artefak
    sort_artefak(N);

    // looping output artefak yang telah terurut sesuai spesifikasi
    for (int i = 0; i < N; i++) {
        printf("%s %s %d %d\n", array[i].nama, array[i].kategori, array[i].tahun, array[i].nilai);
    }

    return 0;
}
