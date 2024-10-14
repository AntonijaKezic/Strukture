#define _CRT_SECURE_NO_WARNINGS
#define MAX 1024 
#include <stdio.h>

int NumberOfRows(const char*); 

int main() {
    int numOfRows = 0;
    // Poziv funkcije koja broji redove u datoteci "imedat.txt"
    numOfRows = NumberOfRows("imedat.txt");
    return 0;
}

int NumberOfRows(const char* fileName) {
    FILE* fp = NULL;
    int numOfRows = 0;
    char buffer[MAX] = {}; // Prazan buffer za čitanje redaka

    fp = fopen(fileName, "r");
    if (!fp) {
        // Ako se datoteka ne može otvoriti, vraća -1 kao oznaku greške
        return -1;
    }
    while (!feof(fp)) {
        fgets(buffer, MAX, fp);
        numOfRows++;
    }
    fclose(fp);

    return numOfRows; // Vraća broj redova u datoteci
}
