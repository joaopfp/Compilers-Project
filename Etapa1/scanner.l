%{
/* 
    ETAPA 1. Compiladores - 2023/2. Prof. Marcelo Johann
    Aluno: João Pedro Ferreira Pereira
*/
	#include "tokens.h"
	#include "hash.h"

	int Running = 1;
	long int LineNumber = 1;
%}

%x COMMENT_BLOCK
%x COMMENT_LINE

%%
char                        { return KW_CHAR;}
int                         { return KW_INT;}
float                       { return KW_FLOAT;}
code                        { return KW_CODE;}
if                          { return KW_IF;}
else                        { return KW_ELSE;}
while                       { return KW_WHILE;}
input                       { return KW_INPUT;} 
print                       { return KW_PRINT;}
return                      { return KW_RETURN;}
[-,;:()\[\]{}+*%/<>=&$|]   { return yytext[0];}
">="                        { return OPERATOR_GE;}
"<="                        { return OPERATOR_LE;}
"=="                        { return OPERATOR_EQ;}
"!="                        { return OPERATOR_DIF;}
[a-zA-Z_][a-zA-Z_0-9]*      { insertValueInHashTable(TK_IDENTIFIER, yytext); return TK_IDENTIFIER;}
[0-9]+						{ insertValueInHashTable(LIT_INT, yytext); return LIT_INT;}
[0-9]+\.[0-9]+            { insertValueInHashTable(LIT_REAL, yytext); return LIT_REAL;}
\n                          {LineNumber++; }
[ \t] 
"///"                       {BEGIN(COMMENT_BLOCK);}
"//"                        {BEGIN(COMMENT_LINE);}
'.'                         {insertValueInHashTable(LIT_CHAR, yytext); return LIT_CHAR;     }
\"(\\.|[^"])*\"             {insertValueInHashTable(LIT_STRING, yytext); return LIT_STRING;   }
.                           {return TOKEN_ERROR;  }


<COMMENT_LINE>.
<COMMENT_LINE>\n            {BEGIN(INITIAL); ++LineNumber;}

<COMMENT_BLOCK>"\\\\\\"     {BEGIN(INITIAL);}
<COMMENT_BLOCK>. 
<COMMENT_BLOCK>\n           {++LineNumber;}

%%

#include "hash.c"
#include "main.c"

void initMe(void){
	initializeHashTable();
}

int getLineNumber(void){
	return LineNumber;
}

int isRunning(void){
	return Running;
}

int yywrap(){
    Running = 0;
    return 1;
}