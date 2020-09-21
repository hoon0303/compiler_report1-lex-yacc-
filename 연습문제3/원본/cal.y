%{
%}
%token NAME NUMBER
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS
%%
start : NAME '=' expr
      | expr { printf("= %d\n", $1);}
      ;
expr : expr '+' expr {$$ = $1 + $3;}
      | expr '-' expr {$$ = $1 - $3;}
      | expr '*' expr {$$ = $1 * $3;}
      | expr '/' expr
	{ if($3==0) yyerror("divide by zero");
	else $$ = $1 + $3;
	}
      | '-' expr %prec UMINUS { $$ = -$2; }
      | '(' expr ')' { $$ = $1; }
      | NUMBER
      ;
%%
#include "lexyy.c"
void yyerror(char *s)
{
	printf("%s\n", s);
}
int main(void)
{
	return yyparse();
}
