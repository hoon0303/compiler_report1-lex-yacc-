%{
#include "y.tab.h"
%}

letter	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*

%%
"("	return(yytext[0]);
"*"	return(yytext[0]);
")"	return(yytext[0]);
"+"	return(yytext[0]);
{id}	return(ID);
[ \n\t\b];
