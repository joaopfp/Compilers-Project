%{
    //INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
    //  Etapa 2 
   //Joao Pedro Ferreira, 324521

    #include <stdio.h>
    #include <stdlib.h>
    #include "hash.h"
    #include "ast.h"

    int yylex();
	int yyerror(char *message);
    extern int getLineNumber();
    AST_NODE *root;
%}

%code requires
{
    #include "hash.h"
    #include "ast.h"
}

%union{
    HASH_ENTRY *symbol; 
    AST_NODE *ast;
}


%token KW_CHAR
%token KW_INT
%token KW_FLOAT
%token KW_CODE
%token KW_IF
%token KW_ELSE
%token KW_WHILE
%token KW_INPUT
%token KW_PRINT
%token KW_RETURN



%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_DIF


%token <symbol> TK_IDENTIFIER
%token <symbol> LIT_INT
%token <symbol> LIT_REAL
%token <symbol> LIT_CHAR
%token <symbol> LIT_STRING


%token TOKEN_ERROR

%left '+' '-' '*' '/'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '&' '|' '~'


%start program

%type <ast>program 
%type <ast>start
%type <ast>declaration_list
%type <ast>declaration
%type <ast>implementation_list
%type <ast>implementation
%type <ast>command 
%type <ast>command_list
%type <ast>print_function 
%type <ast>argument_list 
%type <ast>next_argument 
%type <ast>expression 
%type <ast>vector_elements 
%type <ast>parameters_list 
%type <ast>next_parameter 
%type <ast>parameter 
%type <ast>type 
%type <ast>literal    


%%

program: start                                                              {root=$$;astree_print(0, root);}

start:
        | declaration_list implementation_list                              {$$=astree_create(AST_START, 0, $1, $2, 0, 0);}
        ;

declaration_list:                                                           {$$=0;}
                | declaration declaration_list                              {$$=astree_create(AST_DECLARATION_LIST, 0, $1, $2, 0, 0);} 
                ;


declaration: type TK_IDENTIFIER '=' literal ';'                             {$$=astree_create(AST_DECLARATION, $2, $1, $4, 0, 0);}            
                | type TK_IDENTIFIER '[' LIT_INT ']' vector_elements ';'    {$$=astree_create(AST_DECLARATION_VECTOR, $2, $1, astree_create(AST_SYMBOL, $4, 0, 0, 0, 0), $6, 0);} 
                | type TK_IDENTIFIER '(' parameters_list ')' ';'            {$$=astree_create(AST_DECLARATION_FUNCTION, $2, $1, $4, 0, 0);}

implementation_list: implementation implementation_list                     {$$=astree_create(AST_IMPLEMENTATION_LIST, 0, $1, $2, 0, 0);}
                    |                                                       {$$=0;}
                    ;


implementation: KW_CODE TK_IDENTIFIER command                               {$$=astree_create(AST_IMPLEMENTATION, $2, $3, 0, 0, 0);}
                ;


command: KW_PRINT print_function ';'                                        {$$=astree_create(AST_PRINT, 0, $2, 0, 0, 0);}
        | '{' command_list '}'                                              {$$=astree_create(AST_COMMAND_BLOCK, 0, $2, 0, 0, 0);}
        | KW_RETURN expression ';'                                          {$$=astree_create(AST_RETURN, 0, $2, 0, 0, 0);}
        | TK_IDENTIFIER '=' expression ';'                                  {$$=astree_create(AST_ATTRIBUTION, $1, $3, 0, 0, 0);}
        | TK_IDENTIFIER '[' expression ']' '=' expression ';'               {$$=astree_create(AST_VECTOR_ATTRIBUTION, $1, $3, $6, 0, 0);}
        | KW_IF '(' expression ')' command                                 {$$=astree_create(AST_IF, 0, $3, $5, 0, 0);}
        | KW_IF '(' expression ')' command KW_ELSE command                   {$$=astree_create(AST_IF_ELSE, 0, $3, $5, $7, 0);}
        | KW_WHILE '(' expression ')' command                               {$$=astree_create(AST_WHILE, 0, $3, $5, 0, 0);}
        ;

command_list: command command_list                                          {$$=astree_create(AST_COMMAND_LIST, 0, $1, $2, 0, 0);}
                |                                                           {$$=0;}
                ;


print_function: LIT_STRING                                                  {$$=astree_create(AST_SYMBOL, $1, 0, 0, 0, 0);}
                | expression                                                {$$=$1;}
                ;

argument_list: expression next_argument                                     {$$=astree_create(AST_ARGUMENT_LIST, 0, $1, $2, 0, 0);}
            |                                                               {$$=0;}
            ;
next_argument: ',' expression next_argument                                 {$$=astree_create(AST_NEXT_ARGUMENT, 0, $2, $3, 0, 0);}
            |                                                               {$$=0;}
            ;

expression: literal                                                         {$$=$1;}
            | TK_IDENTIFIER                                                 {$$=astree_create(AST_SYMBOL, $1, 0, 0, 0, 0);}
            | TK_IDENTIFIER '[' expression ']'                              {$$=astree_create(AST_VECTOR, $1, $3, 0, 0, 0);}
            | TK_IDENTIFIER '(' argument_list ')'                           {$$=astree_create(AST_FUNCTION, $1, $3, 0, 0, 0);}
            | '(' expression ')'                                            {$$=astree_create(AST_PARENTHESIS, 0, $2, 0, 0, 0);}
            | expression OPERATOR_LE expression                             {$$=astree_create(AST_LE, 0, $1, $3, 0, 0);}
            | expression OPERATOR_GE expression                             {$$=astree_create(AST_GE, 0, $1, $3, 0, 0);}
            | expression OPERATOR_EQ expression                             {$$=astree_create(AST_EQ, 0, $1, $3, 0, 0);}
            | expression OPERATOR_DIF expression                            {$$=astree_create(AST_DIF, 0, $1, $3, 0, 0);}
            | expression '+' expression                                     {$$=astree_create(AST_SUM, 0, $1, $3, 0, 0);}
            | expression '-' expression                                     {$$=astree_create(AST_SUB, 0, $1, $3, 0, 0);}
            | expression '*' expression                                     {$$=astree_create(AST_MUL, 0, $1, $3, 0, 0);}
            | expression '/' expression                                     {$$=astree_create(AST_DIV, 0, $1, $3, 0, 0);}
            | expression '<' expression                                     {$$=astree_create(AST_LESS, 0, $1, $3, 0, 0);}
            | expression '>' expression                                     {$$=astree_create(AST_GREATER, 0, $1, $3, 0, 0);}
            | expression '&' expression                                     {$$=astree_create(AST_AND, 0, $1, $3, 0, 0);}
            | expression '|' expression                                     {$$=astree_create(AST_OR, 0, $1, $3, 0, 0);}
            | expression '~' expression                                     {$$=astree_create(AST_NOT, 0, $1, $3, 0, 0);}
            | KW_INPUT '(' type ')'                                         {$$=astree_create(AST_INPUT, 0, $3, 0, 0, 0);}
            ;


vector_elements: literal vector_elements                                    {$$=astree_create(AST_VECTOR_ELEMENTS, 0, $1, $2, 0, 0);}
                |                                                           {$$=0;}
                ;




parameters_list:                                                               {$$=0;}
                |   parameter next_parameter                                   {$$=astree_create(AST_PARAMETERS_LIST, 0, $1, $2, 0, 0);}
                ;


next_parameter:                                                                 {$$=0;}
                |   ',' parameter next_parameter                                {$$=astree_create(AST_NEXT_PARAMETER, 0, $2, $3, 0, 0);}
                ;

parameter: type TK_IDENTIFIER                                               {$$=astree_create(AST_PARAMETER, $2, $1, 0, 0, 0);}
            ;


type: KW_CHAR                                                               {$$=astree_create(AST_TYPE_CHAR, 0, 0, 0, 0, 0);}
    | KW_INT                                                                {$$=astree_create(AST_TYPE_INT, 0, 0, 0, 0, 0);}
    | KW_FLOAT                                                              {$$=astree_create(AST_TYPE_FLOAT, 0, 0, 0, 0, 0);}
    ;

literal: LIT_CHAR                                                           {$$=astree_create(AST_SYMBOL, $1, 0, 0, 0, 0);}
    | LIT_INT                                                               {$$=astree_create(AST_SYMBOL, $1, 0, 0, 0, 0);}
    | LIT_REAL                                                              {$$=astree_create(AST_SYMBOL, $1, 0, 0, 0, 0);}
    ;


%%

int yyerror(char *err){
	
	fprintf(stderr, "Syntax Error in line %d\n", getLineNumber());
	exit(3);
}

AST_NODE* getAST(){
    return root;
}