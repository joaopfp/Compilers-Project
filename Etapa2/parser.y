%{
    //INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
    //  Etapa 2 
   //Joao Pedro Ferreira, 324521

    #include <stdio.h>
    #include <stdlib.h>
    #include "hash.h"

    int yylex();
	int yyerror(char *message);
    extern int getLineNumber();


%}

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
%token TK_IDENTIFIER
%token LIT_INT
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR

%left '+' '-' '*' '/'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '&' '|' '~'

%start program

%%

program: declaration_list implementation_list

declaration_list: declaration declaration_list
                | 
                ;


declaration: type TK_IDENTIFIER '=' literal ';'
                | type TK_IDENTIFIER '[' LIT_INT ']' vector_elements ';'
                | type TK_IDENTIFIER '(' parameters_list ')' ';'

implementation_list: implementation implementation_list
                    | 
                    ;


implementation: KW_CODE TK_IDENTIFIER command
                ;


command: KW_PRINT print_function ';'
        | command_block
        | KW_RETURN expression ';'
        | TK_IDENTIFIER '=' expression ';'
        | TK_IDENTIFIER '[' expression ']' '=' expression ';'
        | KW_IF '(' expression ')' command 
        | KW_IF '(' expression ')' command KW_ELSE command 
        | KW_WHILE '(' expression ')' command 
        | ';' 
        ;

command_block: '{' command command_list '}'
                | '{' '}'
                ;


command_list: command command_list 
                | 
                ;


print_function: LIT_STRING
                | expression
                ;

argument_list: expression next_argument 
            | 
            ;
next_argument: ',' expression next_argument
            | 
            ;

expression: literal 
            | TK_IDENTIFIER
            | TK_IDENTIFIER '[' expression ']'
            | TK_IDENTIFIER '(' argument_list ')'
            | '(' expression ')'
            | expression OPERATOR_LE expression
            | expression OPERATOR_GE expression
            | expression OPERATOR_EQ expression
            | expression OPERATOR_DIF expression
            | expression '+' expression
            | expression '-' expression
            | expression '*' expression
            | expression '/' expression
            | expression '<' expression
            | expression '>' expression
            | expression '&' expression
            | expression '|' expression
            | expression '~' expression
            | KW_INPUT '(' type ')'
            ;


vector_elements: literal vector_elements
                | 
                ;

parameters_list: parameter next_parameter
                | 
                ;


next_parameter: ',' parameter next_parameter
            | 
            ;

parameter: type TK_IDENTIFIER
            ;


type: KW_CHAR
    | KW_INT
    | KW_FLOAT
    ;

literal: LIT_CHAR
    | LIT_INT 
    | LIT_REAL
    ;


%%

int yyerror(char *err){
	
	fprintf(stderr, "Syntax Error in line %d\n", getLineNumber());
	exit(3);
}
