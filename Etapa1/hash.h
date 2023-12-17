/* 
    ETAPA 1. Compiladores - 2023/2. Prof. Marcelo Johann
    Aluno: João Pedro Ferreira Pereira
*/

#ifndef HASH
#define HASH

#define HASH_SIZE 1000

typedef struct HashTableEntry {
    char* value;
    int index;
    struct HashTableEntry* next;
} HashTableEntry;

HashTableEntry* HashTable[HASH_SIZE];

void initializeHashTable(void);

int calculateHashValue(char* value);

HashTableEntry* findValueInHashTable(char* value);

HashTableEntry* insertValueInHashTable(int index, char* value);

void displayHashTable(void);

#endif