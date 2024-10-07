#define _CRT_SECURE_NO_WARNINGS
//#define ERROR_OF 1
#define MAX 1024
#include <stdio.h>

int NumberOfRows(const char*);

int main() {
	int numOfRows = 0;
	numOfRows = NumberOfRows("imedat.txt");

	printf("Hello World");
	return 0;
}

int NumberOfRows(const char* fileName) {
	FILE* fp = NULL;
	int numOfRows = 0;
	char buffer[MAX] = {};

	fp = fopen(fileName, "r");
	if (!fp) {
		return -1;
}
	while (!feof(fp)) {
		fgets(buffer, );
		numOfRows++;
	}



/* 
int OpenFile(char *fileName) {
	FILE *fp = NULL;
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("");
		return ERROR;
	}
}
*/
