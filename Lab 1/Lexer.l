%{
#include <math.h>
#include <stdio.h>
%}

DIGIT [0-9]
IDENTIFIER [a-z]*
KEYWORD void|int
SYMBOL "("|")"|"{"|"}"
OPERATOR "+"|"-"|"*"|"/"="=="

%%
[ \t\n]+    /* skip whitespaces */
{KEYWORD}   printf("Keyword: %s \n", yytext);
{DIGIT}+    printf("Integer: %s (%d)\n", yytext, atoi(yytext));
{IDENTIFIER}    printf("Identifier: %s \n", yytext);
{SYMBOL}    printf("Symbol: %s \n", yytext);
{OPERATOR}    printf("Operator: %s \n", yytext);
.   printf( "Unknown character: %s\n", yytext );
%%

int yywrap()
{
  return 1;
}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	yylex();
	return 1;
}