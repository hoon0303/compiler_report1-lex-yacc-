%{
%}
%%
[a-z]*	{return NAME;}
[0-9]*	{yylval = atoi(yylex); return NUMBER;}
[ \t]	;
"\n"	return 0;
.	return yytext[0];
%%
int yywrap()
{
	return 1;
}