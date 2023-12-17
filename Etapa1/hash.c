#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initializeHashTable(void) {
    int i;
    for (i = 0; i < HASH_SIZE; i++)
        HashTable[i] = NULL;
}
 
int calculateHashValue(char* value) {
    unsigned long hashval = 5381; 
    int c;
 
    while ((c = *value++)) {
        hashval = ((hashval << 5) + hashval) + c; 
    }
 
    return hashval % HASH_SIZE;
}

HashTableEntry* findValueInHashTable(char* value) {
    int hashIdx = calculateHashValue(value);
    for(HashTableEntry* entry = HashTable[hashIdx]; entry; entry = entry->next)
        if(strcmp(value, entry->value) == 0) 
            return entry;
    
    return NULL;
}


void displayHashTable(void) {
    HashTableEntry* entry;
    for (int i = 0; i < HASH_SIZE; i++)
        for(entry = HashTable[i]; entry; entry = entry->next)
            printf("Table[%d] - index: %d value: %s\n", i, entry->index, entry->value);
}


HashTableEntry* insertValueInHashTable(int index, char* value) {
    HashTableEntry* newEntry = findValueInHashTable(value);
    if (newEntry) 
        return newEntry;

    int idx = calculateHashValue(value);
    newEntry = calloc(1, sizeof(HashTableEntry));
    newEntry->index = index;
    newEntry->value = calloc(strlen(value) + 1, sizeof(char));
    strcpy(newEntry->value, value);

    newEntry->next = HashTable[idx];
    HashTable[idx] = newEntry;

    return newEntry;
}
