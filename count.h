//Baljit Kaur
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define SIZE 50000000

typedef struct Entry{
	int key;
	char address[17];
	struct Entry *next;
}Entry_t;

Entry_t *table[SIZE];

unsigned long long hextodec(char *str);
int isValid(char *str);

