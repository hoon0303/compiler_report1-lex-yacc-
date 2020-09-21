%{
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void yyerror(char *s);
int fibonacci(int n);
clock_t start, finish;
double duration;
%}
%token NUMBER
%nonassoc UMINUS
%%
S : 
      'f' S { if($2<=0) {yyerror("error");}
	else {
	start = clock();
	printf("answer : %d\n",fibonacci($2));
	finish = clock();
	duration = (double)(finish-start)/CLOCKS_PER_SEC;
	printf("time : %f",duration); }}
      | NUMBER
      ;
%%
void yyerror(char *s)
{
	printf("%s\n", s);
}
int fibonacci(int n)
{
	if(n==1 || n==2)
		return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}
int main(void)
{
	printf("fibonacci number\n");
	return yyparse();
}
