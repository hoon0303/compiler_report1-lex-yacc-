%{
#include<stdio.h>
#include<ctype.h>
%}

%token DIGIT

%%

line : expr '\n' {putchar('\n');}
     ;
expr : expr '+' term {putchar('+');}
      | expr '-' term {putchar('-');}
      | term
      ;
term : DIGIT {printf("%d", yylval);}
      ;
%%
int main()
{
	if(yyparse()==0) printf("The Parsing Complete \n\n");
	else printf("syntax error \n\n");
}
