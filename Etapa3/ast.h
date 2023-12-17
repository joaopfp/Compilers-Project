//INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
//   Trabalho - Etapa 3 | Joao Pedro Ferreira, 324521

#ifndef ASTREE
#define ASTREE

#define MAX_SONS 4

#define AST_DECLARATION_LIST 1
#define AST_DECLARATION 2
#define AST_DECLARATION_VECTOR 3
#define AST_DECLARATION_FUNCTION 4
#define AST_IMPLEMENTATION_LIST 5
#define AST_IMPLEMENTATION 6
#define AST_PRINT 7
#define AST_RETURN 8
#define AST_ATTRIBUTION 9
#define AST_VECTOR_ATTRIBUTION 10
#define AST_IF 11
#define AST_IF_ELSE 12 
#define AST_WHILE 13
#define AST_COMMAND_BLOCK 14
#define AST_COMMAND_LIST 15
#define AST_PRINT_STRING 16
#define AST_PRINT_EXPRESSION 17
#define AST_ARGUMENT_LIST 18
#define AST_NEXT_ARGUMENT 19
#define AST_SYMBOL 20
#define AST_VECTOR 21
#define AST_FUNCTION 22
#define AST_PARENTHESIS 23
#define AST_LE 24
#define AST_GE 25
#define AST_EQ 26
#define AST_DIF 27
#define AST_SUM 29
#define AST_SUB 30
#define AST_MUL 31
#define AST_DIV 32
#define AST_LESS 33
#define AST_GREATER 34 
#define AST_AND 35
#define AST_OR 36
#define AST_NOT 37
#define AST_INPUT 38
#define AST_VECTOR_ELEMENTS 40 
#define AST_PARAMETERS_LIST 41
#define AST_NEXT_PARAMETER 42
#define AST_PARAMETER 43
#define AST_TYPE_CHAR 44
#define AST_TYPE_INT 45
#define AST_TYPE_FLOAT 46
#define AST_START 47

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct AST_NODE
{
    int type;
    HASH_ENTRY *symbol;
    struct AST_NODE *sons[MAX_SONS];
} AST_NODE;


AST_NODE* astree_create(int type, HASH_ENTRY* symbol, AST_NODE* son0, AST_NODE* son1, AST_NODE* son2, AST_NODE* son3);

void astree_print(int level, AST_NODE *node);

void uncompileAST(AST_NODE *root, FILE *file);

#endif