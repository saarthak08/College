%{
	//Definitions
	#include<stdio.h>
%}

brackets \([^\)]*\)(\.[^\)]*\))?
variable [a-z][_a-z0-9]*


%%


"s"+{brackets} 								{ printf("\n%s : [Sine Function]",yytext); return 1;}

"c"+{brackets} 								{ printf("\n%s : [Cos Function]",yytext); return 2;}

"l"+{brackets} 								{ printf("\n%s : [Logarithm Function]",yytext); return 3;}

"e"+{brackets} 								{ printf("\n%s : [Exponential Function]",yytext); return 4;}

"define "+{variable}+{brackets} { printf("\n%s : [User Defined Function]",yytext); return 5;}

scale|ibase|obase|last|for|while|if|else|continue|break|return|halt|read|sqrt|length|quit|warranty|limits|define|auto { 												
 												
 											  printf("\n%s : [Keyword]",yytext); return 6; }
											

{variable}									{ printf("\n%s : [Variable]",yytext); return 7; }

[0-9]+										{ printf("\n%s : [Number]",yytext); return 8; }

","											{ printf("\n%s : [Comma]",yytext); return 9; }

"="|"+="|"-="|"*="|"/="|"%="				{ printf("\n%s : [Assignment Operator]",yytext); return 10; }

";"											{ printf("\n%s : [Semi Colon]",yytext); return 11; }

"+"|"-"|"*"|"/"|"%"|"^"						{ printf("\n%s : [Arithmetic Operator]",yytext); return 12; }

"++"|"--"									{ printf("\n%s : [Increment/Decrement Operator]",yytext); return 13; }

"<"|">"|"<="|">="|"!="|"=="					{ printf("\n%s : [Relational Operator]",yytext); return 14; }

"||"|"&&"|"!"								{ printf("\n%s : [Boolean Logical Operator]",yytext); return 15; }

"("|")"|"{"|"}"|"["|"]"						{ printf("\n%s : [Bracket]",yytext); return 16; }

\".*\"										{ printf("\n%s : [String]",yytext); return 17; }

"#".*										{ printf("\n%s : [SingleLine Comment]",yytext); return 18; }

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       	{ printf("\n%s : [MultiLine Comment]",yytext); return 19; }


%%




//Code Section

int main() {
	
	printf("Tokens: \n");

	//yylex parses the rules & return the token number.
	while(yylex());

	return 0;
}

/* 
When yyin() reads the input file & End-Of-File (EOF) is encountered, it checks yywrap() function.
If yywrap returns 1, then it stops scanning. If yywrap returns 0, then it continues scanning.
Here we have returned 1, so it will stop scanning when EOF is encountered. 
*/
int yywrap() {
	return 1;
} 