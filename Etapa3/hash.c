//INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
//   Trabalho - Etapa 2 | Joao Pedro Ferreira, 324521

#include "hash.h"
HASH_ENTRY *Table[HASH_LEN];

void initializeHashTable(void)
{
    memset(Table, 0, sizeof(Table));
}


HASH_ENTRY *addToHashTable(char *text, int type)
{
    int address = calculateHashAddress(text);

    HASH_ENTRY *entryExists = findHashValue(text);
    if(entryExists)
    {
        return entryExists;
    }

    HASH_ENTRY *newEntry = (HASH_ENTRY*) calloc(1, sizeof(HASH_ENTRY));
    newEntry->type = type;
    newEntry->text = strdup(text);  // shortcut for calloc(strlen(text) + 1, sizeof(char)) and strcpy()

    newEntry->next = Table[address];
    Table[address] = newEntry;

    return newEntry;
}

void displayHashTable(void)
{
    HASH_ENTRY *tmpEntry = NULL;
    for(int i = 0; i < HASH_LEN; i++)
    {
        tmpEntry = Table[i];
        while(tmpEntry)
        {
            printf("Table[%d] has %s from type %d.\n", i, tmpEntry->text, tmpEntry->type);
            tmpEntry = tmpEntry->next;
        }
    }
}

int calculateHashAddress(char *text)
{
    int address = 1;
    char *tempText = text;
    while(*tempText) 
    {
        address = (address * (*tempText++)) % HASH_LEN + 1;
    }
    return address - 1;
}

HASH_ENTRY *findHashValue(char *text)
{
    int address = calculateHashAddress(text);
    HASH_ENTRY *tmpEntry = Table[address];

    while(tmpEntry)
    {
        if(strcmp(tmpEntry->text,text) == 0)
        {
            return tmpEntry;
        }
        tmpEntry = tmpEntry->next;
    }
    return NULL;
}