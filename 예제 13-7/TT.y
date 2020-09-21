%{
%}

%token ID

%%
S:L '=' R
 | R;
L:'*'R
 | ID;
R:L;
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
