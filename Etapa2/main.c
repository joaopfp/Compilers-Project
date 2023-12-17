//INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
//   Trabalho - Etapa 2 | Joao Pedro Ferreira, 324521

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "y.tab.h"

int main(int argc, char **argv)
{
    int token;
    if(argc < 2)
    {
        fprintf(stderr,"Call: ./a.out file_name\n");
        exit(1);
    }
    yyin = fopen(argv[1],"r");
    
    initializeHashTable();
    
    yyparse();
    
    printf("Numero de linhas total do arquivo: %d\n",lineNumber);
    displayHashTable();
    exit(0);
}
