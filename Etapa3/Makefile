#INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
#   Trabalho - Etapa 3 | Joao Pedro Ferreira, 324521



etapa3: y.tab.c lex.yy.c
	gcc -o etapa3 lex.yy.c
y.tab.c: parser.y
	yacc -d parser.y
lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c y.tab.c etapa3
