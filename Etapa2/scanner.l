%{
    //INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
    //  Etapa 2 
   //Joao Pedro Ferreira, 324521
    
#include "y.tab.h"
#include "hash.h"

int running = 1;
int lineNumber = 1;

%}

%x COMMENT_BLOCK
%x COMMENT_LINE

%%

if                      {return KW_IF;}
else                    {return KW_ELSE;}
while                   {return KW_WHILE;}
return                  {return KW_RETURN;}
char                    {return KW_CHAR;}
int                     {return KW_INT;}
float                   {return KW_FLOAT;}
code                    {return KW_CODE;}
input                   {return KW_INPUT;}
print                   {return KW_PRINT;}

"=="                    {return OPERATOR_EQ;}
"!="                    {return OPERATOR_DIF;}
"<="                    {return OPERATOR_LE;}
">="                    {return OPERATOR_GE;}


"\n"                    {++lineNumber;}
[ \t]
"'"."'"                 {addToHashTable(yytext, LIT_CHAR); return LIT_CHAR;}
"\""[^\"]+"\""          {addToHashTable(yytext, LIT_STRING); return LIT_STRING;}
[0-9]+                  {addToHashTable(yytext, LIT_INT); return LIT_INT;}
[0-9]+"."[0-9]+         {addToHashTable(yytext, LIT_REAL); return LIT_REAL;}
[a-zA-Z0-9_]+           {addToHashTable(yytext, TK_IDENTIFIER); return TK_IDENTIFIER;}
"//"                    {BEGIN(COMMENT_LINE);}
"///"                   {BEGIN(COMMENT_BLOCK);}
[-,;()[\]{}=+*/%<>&|~]  {return yytext[0];}

.                       {return TOKEN_ERROR;}

<COMMENT_LINE>.
<COMMENT_LINE>"\n"      {++lineNumber; BEGIN(INITIAL);}

<COMMENT_BLOCK>"\\\\\\"       {BEGIN(INITIAL);}
<COMMENT_BLOCK>.
<COMMENT_BLOCK>\n             {++lineNumber;}

%%

#include "y.tab.c"
#include "hash.c"
#include "main.c"

int getLineNumber(void)
{
    return lineNumber;
}
    
int isRunning(void)
{
    return running;
}

void initMe(void)
{
    initializeHashTable();
}
    
int yywrap()
{
    running = 0;
    return 1;
}
