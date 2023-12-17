#include "hash.h"
#include "ast.h"
#include <stdlib.h>
#include <stdio.h>

AST_NODE* astree_create(int type, HASH_ENTRY* symbol, AST_NODE* son0, AST_NODE* son1, AST_NODE* son2, AST_NODE* son3){
    AST_NODE *node = calloc(1, sizeof(AST_NODE));
    node->type = type;
    node->symbol = symbol;
    node->sons[0] = son0;
    node->sons[1] = son1;
    node->sons[2] = son2;
    node->sons[3] = son3;

    return node;
}

void astree_print(int level, AST_NODE *node){
  if(node == NULL)
    return;

  int i;
  for(i = 0; i < level; i++)
    fprintf(stderr, "  ");

  fprintf(stderr, "AST( ");

  switch(node->type){
    case AST_START: fprintf(stderr, "AST_START"); break;
    case AST_DECLARATION_LIST: fprintf(stderr, "AST_DECLARATION_LIST"); break;
    case AST_DECLARATION: fprintf(stderr, "AST_DECLARATION"); break;
    case AST_DECLARATION_VECTOR: fprintf(stderr, "AST_DECLARATION_VECTOR"); break;
    case AST_DECLARATION_FUNCTION: fprintf(stderr, "AST_DECLARATION_FUNCTION"); break;
    case AST_IMPLEMENTATION_LIST: fprintf(stderr, "AST_IMPLEMENTATION_LIST"); break;
    case AST_IMPLEMENTATION: fprintf(stderr, "AST_IMPLEMENTATION"); break;
    case AST_PRINT: fprintf(stderr, "AST_PRINT"); break;
    case AST_RETURN: fprintf(stderr, "AST_RETURN"); break;
    case AST_ATTRIBUTION: fprintf(stderr, "AST_ATTRIBUTION"); break;
    case AST_VECTOR_ATTRIBUTION: fprintf(stderr, "AST_VECTOR_ATTRIBUTION"); break;
    case AST_IF : fprintf(stderr, "AST_IF"); break;
    case AST_IF_ELSE: fprintf(stderr, "AST_IF_ELSE"); break;
    case AST_WHILE: fprintf(stderr, "AST_WHILE"); break; 
    case AST_COMMAND_BLOCK: fprintf(stderr, "AST_COMMAND_BLOCK"); break;
    case AST_COMMAND_LIST: fprintf(stderr, "AST_COMMAND_LIST"); break;
    case AST_PRINT_STRING: fprintf(stderr, "AST_PRINT_STRING"); break;
    case AST_PRINT_EXPRESSION: fprintf(stderr, "AST_PRINT_EXPRESSION"); break;
    case AST_ARGUMENT_LIST: fprintf(stderr, "AST_ARGUMENT_LIST"); break;
    case AST_NEXT_ARGUMENT: fprintf(stderr, "AST_NEXT_ARGUMENT"); break; 
    case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL"); break;
    case AST_VECTOR: fprintf(stderr, "AST_VECTOR"); break;
    case AST_FUNCTION: fprintf(stderr, "AST_FUNCTION"); break;
    case AST_PARENTHESIS: fprintf(stderr, "AST_PARENTHESIS"); break;
    case AST_LE: fprintf(stderr, "AST_LE"); break;
    case AST_GE: fprintf(stderr, "AST_GE"); break;
    case AST_EQ: fprintf(stderr, "AST_EQ"); break;
    case AST_DIF: fprintf(stderr, "AST_DIF"); break; 
    case AST_SUM: fprintf(stderr, "AST_SUM"); break;
    case AST_SUB: fprintf(stderr, "AST_SUB"); break; 
    case AST_MUL: fprintf(stderr, "AST_MUL"); break; 
    case AST_DIV: fprintf(stderr, "AST_DIV"); break;
    case AST_LESS: fprintf(stderr, "AST_LESS"); break; 
    case AST_GREATER: fprintf(stderr, "AST_GREATER"); break; 
    case AST_AND: fprintf(stderr, "AST_AND"); break; 
    case AST_OR: fprintf(stderr, "AST_OR"); break; 
    case AST_NOT: fprintf(stderr, "AST_NOT"); break;
    case AST_INPUT: fprintf(stderr, "AST_INPUT"); break; 
    case AST_VECTOR_ELEMENTS: fprintf(stderr, "AST_VECTOR_ELEMENTS"); break; 
    case AST_PARAMETERS_LIST: fprintf(stderr, "AST_PARAMETERS_LIST"); break; 
    case AST_NEXT_PARAMETER: fprintf(stderr, "AST_NEXT_PARAMETER"); break; 
    case AST_PARAMETER: fprintf(stderr, "AST_PARAMETER"); break; 
    case AST_TYPE_CHAR: fprintf(stderr, "AST_TYPE_CHAR"); break; 
    case AST_TYPE_INT: fprintf(stderr, "AST_TYPE_INT"); break; 
    case AST_TYPE_FLOAT: fprintf(stderr, "AST_TYPE_FLOAT"); break; 
  }

  if(node->symbol != NULL)
    fprintf(stderr, ", %s )\n", node->symbol->text);
  else
    fprintf(stderr, " )\n");

  for(i = 0; i < MAX_SONS; i++)
    astree_print(level+1, node->sons[i]);
}

void uncompileAST(AST_NODE *node, FILE *file){

  if(node == NULL)
    return;

  switch(node->type){

    case AST_START:
      uncompileAST(node->sons[0], file);
      uncompileAST(node->sons[1], file);
      break;

    case AST_DECLARATION_LIST:
      uncompileAST(node->sons[0], file);
      uncompileAST(node->sons[1], file);
      break;
    
    case AST_DECLARATION:
      uncompileAST(node->sons[0], file);
      fprintf(file, "%s = ", node->symbol->text);
      uncompileAST(node->sons[1], file);
      fprintf(file, ";\n");
      break;

    case AST_DECLARATION_VECTOR:
      uncompileAST(node->sons[0], file);
      fprintf(file, " %s[", node->symbol->text);
      uncompileAST(node->sons[1], file);
      fprintf(file, "]");
      uncompileAST(node->sons[2], file);
      fprintf(file, ";\n");
      break;

    case AST_DECLARATION_FUNCTION:
      uncompileAST(node->sons[0], file);
      fprintf(file, " %s(", node->symbol->text);
      uncompileAST(node->sons[1], file);
      fprintf(file, ")");      
      uncompileAST(node->sons[2], file);
      fprintf(file, ";\n");
      break;
    
    case AST_TYPE_CHAR: 
      fprintf(file, "char ");
      break; 
    
    case AST_TYPE_INT:
      fprintf(file, "int ");
      break; 
    
    case AST_TYPE_FLOAT: 
      fprintf(file, "float ");
      break;
    
    case AST_SYMBOL :
      fprintf(file, "%s", node->symbol->text);
      break;
    
    case AST_IMPLEMENTATION_LIST:
      uncompileAST(node->sons[0], file);
      uncompileAST(node->sons[1], file);
      break; 
    
    case AST_IMPLEMENTATION:
      fprintf(file, "code ");
      fprintf(file, " %s\n", node->symbol->text);
      uncompileAST(node->sons[0], file);
      break;

    case AST_PRINT:
      fprintf(file, "print ");
      uncompileAST(node->sons[0], file);
      fprintf(file, ";\n");
      break;

    case AST_RETURN:
      fprintf(file, "return ");
      uncompileAST(node->sons[0], file);
      fprintf(file, ";\n");
      break;
    
    case AST_ATTRIBUTION:
      fprintf(file, "%s = ", node->symbol->text);
      uncompileAST(node->sons[0], file);
      fprintf(file, ";\n");
      break;
    
    case AST_VECTOR_ATTRIBUTION:
      fprintf(file, "%s[", node->symbol->text);
      uncompileAST(node->sons[0], file);
      fprintf(file, "] = ");
      uncompileAST(node->sons[1], file);
      fprintf(file, ";\n");
      break;
    
    case AST_IF:
      fprintf(file, "if (");
      uncompileAST(node->sons[0], file);
      fprintf(file, ") ");
      uncompileAST(node->sons[1], file);
      break;

    
    case AST_IF_ELSE: 
      fprintf(file, "if (");
      uncompileAST(node->sons[0], file);
      fprintf(file, ")");
      uncompileAST(node->sons[1], file);
      fprintf(file, " else ");
      uncompileAST(node->sons[2], file);
      break;
    

    case AST_WHILE:
      fprintf(file, "while (");
      uncompileAST(node->sons[0], file);
      fprintf(file, ")\n");
      uncompileAST(node->sons[1], file);
      break;

    case AST_COMMAND_BLOCK:
      fprintf(file, "{\n");
      uncompileAST(node->sons[0], file);
      fprintf(file, "\n}\n");
      break;
    
    case AST_COMMAND_LIST:
      uncompileAST(node->sons[0], file);
      uncompileAST(node->sons[1], file);
      break;
    
    case AST_ARGUMENT_LIST:
      uncompileAST(node->sons[0], file);
      uncompileAST(node->sons[1], file);
      break; 
    
    case AST_NEXT_ARGUMENT:
      fprintf(file, ", ");
      uncompileAST(node->sons[0], file);
      uncompileAST(node->sons[1], file);
      break; 
    
    case AST_VECTOR:
      fprintf(file, "%s", node->symbol->text);
      fprintf(file, "[");
      uncompileAST(node->sons[0], file);
      fprintf(file, "]");
      break;
    
    case AST_FUNCTION: 
      fprintf(file, "%s", node->symbol->text);
      fprintf(file, "(");
      uncompileAST(node->sons[0], file);
      fprintf(file, ")");
      break;
    
    case AST_PARENTHESIS:
      fprintf(file, "(");
      uncompileAST(node->sons[0], file);
      fprintf(file, ")");
      break;
    
    case AST_LE: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " <= ");
      uncompileAST(node->sons[1], file);
      break;

    case AST_GE: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " >= ");
      uncompileAST(node->sons[1], file);
      break; 
    
    case AST_EQ:
      uncompileAST(node->sons[0], file);
      fprintf(file, " == ");
      uncompileAST(node->sons[1], file);
      break;
    
    case AST_DIF: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " != ");
      uncompileAST(node->sons[1], file);
      break;
    
    case AST_SUM: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " + ");
      uncompileAST(node->sons[1], file);
      break; 

    case AST_SUB: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " - ");
      uncompileAST(node->sons[1], file);
      break; 

    case AST_MUL: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " * ");
      uncompileAST(node->sons[1], file);
      break; 
    
    case AST_DIV: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " / ");
      uncompileAST(node->sons[1], file);
      break; 

    case AST_LESS: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " < ");
      uncompileAST(node->sons[1], file);
      break; 

    case AST_GREATER: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " > ");
      uncompileAST(node->sons[1], file);
      break; 

    
    case AST_AND: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " & ");
      uncompileAST(node->sons[1], file);
      break; 

    case AST_OR: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " | ");
      uncompileAST(node->sons[1], file);
      break;     

    case AST_NOT: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " ~ ");
      uncompileAST(node->sons[1], file);
      break;
    
    case AST_INPUT:
      fprintf(file, "input(");
      uncompileAST(node->sons[0], file);
      fprintf(file, ")");
      break;

    case AST_VECTOR_ELEMENTS: 
      uncompileAST(node->sons[0], file);
      fprintf(file, " ");
      uncompileAST(node->sons[1], file);
      break; 
    
    case AST_PARAMETERS_LIST:
      uncompileAST(node->sons[0], file);
      uncompileAST(node->sons[1], file);
      break;

    case AST_NEXT_PARAMETER:
      fprintf(file, ",");
      uncompileAST(node->sons[0], file);
      uncompileAST(node->sons[1], file);
      break; 
    
    case AST_PARAMETER:
      uncompileAST(node->sons[0], file);
      fprintf(file, "%s", node->symbol->text);
      break;
    
  }
}