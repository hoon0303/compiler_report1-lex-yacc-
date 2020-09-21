%{
%}
%%
S:C C;
C:'c' C
 | 'd';
%%
main()
{
	yyparse();
	printf("The Parsing Complete \n");
}
yyerror()
{
	printf("syntax error \n");
	exit(0);
}
