#INF01147 - Compiladores | 2023/2 | Prof. Marcelo Johann
#   Trabalho - Etapa 2 | Joao Pedro Ferreira, 324521



etapa2: y.tab.c lex.yy.c
	gcc -o etapa2 lex.yy.c
y.tab.c: parser.y
	yacc -d parser.y
lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c y.tab.c etapa2
