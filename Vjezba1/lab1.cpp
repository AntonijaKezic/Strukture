#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024


int NumOffRows(char* filename);
void get_row(char* filename, int row_count, struct Studenti* student);

struct Studenti
{
	char ime[20];
	char prezime[20];
	int bodovi;

};

int main() {
	int n = 0;
	int i = 0;
	char* filename = "imena.txt";
	n = NumOffRows(filename);
	if (n <= 0) {
		printf("No rows found or error in counting rows.\n");
		return n;
	}
	struct Studenti* student = malloc(n * sizeof(struct Studenti));
	if (student == NULL) {
		printf("greska u alokaciji");
		return ERROR_ALLOCATTING_MEMORY;

	}
	get_row(filename, n, student);


	for (i = 0; i < n; i++) {
		printf("%s\t%s\t%d\n", student[i].ime, student[i].prezime, student[i].bodovi);
	}
	return 0;

}
int NumOffRows(char* filename) {
	FILE* fp = NULL;
	char buffer[BUFFER_SIZE];
	int row_counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Error opening file\n");
		return ERROR_OPENING_FILE;
	}
	while (!feof(fp)) {
		fgets(buffer, BUFFER_SIZE, fp);
		//sscanf() doma napravi mozda
		++row_counter;
	}

	fclose(fp);
	return row_counter;
}
void get_row(char* filename, int row_count, struct Studenti* student) {
	int i = 0;
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("error opening file\n");
		return;
	}
	for (int i = 0; i < row_count; i++) {
		fscanf(fp, "%s", student[i].ime);
		fscanf(fp, "%s", student[i].prezime);
		fscanf(fp, "%d", &student[i].bodovi);
	}
	fclose(fp);
}

/*
struct _person;
typefed struct _person* position;
typedef struct _person
{
	char name[MAX_SIZE];
	char lastName[MAX_SIZE];
	int birthYear;

	position next;
}Person;

int main()
{
	Person head = {
	.name = {0},
	.lastName = {0},
	.birthYear = {0},
	.next = NULL
	};

	return 0;
}

int CreatePerson(char* name, char* lastName, int birthYear) {
	Position newPerson = NULL;
	newPerson = (Position)malloc(sizeof(Person));
	if (newPerson == NULL) {
		printf("Memorija nije alocirana\n");
		return NULL;
}
	strcpy(newPerson->name, name);
	strcpy(newPerson->lastName, lastName);
	newPerson->birthYear = birthYear;
	newPerson->next=NULL;
		return newPerson;
}

int PrependList(Position head, char* name, char* lastName, int birtYear)
	{
		position newPerson = NULL;
		newPerson = CreatePerson(name, lastName, birthYear);
if (!newPerson)
{
	printf("Failed in person creation");
	return -1;
}
last = FindLast(head);

int InsertAfter(position prev, position newPerson) {
	newPerson->next = prev->next;
	prev->next = newPerson;
	return EXIT_SUCCES;
}

newPerson->next = head->next;
head->next = newPerson;
return EXIT_SUCCES;
}
	
int PrintList(position first)
{
	position temp = NULL;
	temp = first;
	while (temp != NULL)
	{
		printf("%s %s %d", temp->name, temp->lastName, temp->birthYear);
		temp = temp->next;
	}
	return EXIT_SUCCES;	return EXIT_SUCCES;
}

int AppendList(Position head, char* name, char* lastName, int birtYear) {
	position newPerson = NULL;
	position last = NULL;

	newPerson=CreatePerson(name, lastName, birthYear)
}

position FindLast(position head) {
	position last = NULL;
	last = head;
	while (last->next != NULL) {
		last = last->next;
	}
	return last;
}

position  FindByLastName(position first, char* lastName, int birtYear) {
	position temp = NULL;
	temp = first;
	while (temp) {
		if (strcmp(lastName, temp->lastName) == 0{
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}

int Delete(position head, char* name) {
	position prev = NULL;
		position toDelete = NULL;

		prev = FindPrev(head, name);
	toDelete = prev->next;
	prev->next = toDelete->next;
	free(toDelete);
	return EXIT_SUCCES;
}

*/
