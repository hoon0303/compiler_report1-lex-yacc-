%{
%}

%token ID

%%
E:E'+'T
 | T;
T:T'*'F
 | F;
F:'('E')'
 | ID;
%%
main()
{
	if(yyparse()==0)
	{

		printf("The Parsing Complete \n");
	}
	else
	{
		printf("syntax error \n");
	}
}
