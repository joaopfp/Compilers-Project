//INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
//   Trabalho - Etapa 2 | Joao Pedro Ferreira, 324521

#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>

#define HASH_LEN 997

typedef struct HASH_ENTRY
{
    int type;
    char* text;
    struct HASH_ENTRY* next;
}HASH_ENTRY;

void initializeHashTable(void);
int calculateHashAddress(char *text);
HASH_ENTRY* findHashValue(char *text);
HASH_ENTRY* addToHashTable(char *text, int type);
void displayHashTable(void);

#endif
