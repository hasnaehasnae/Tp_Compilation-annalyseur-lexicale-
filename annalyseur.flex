%{
#define debug false 
#include "annalyseur.h"
int l=0 ;
%}
%option  noyywrap
%%
";" { printf("%s",yytext);return DEL ; }
[0-9]+ { printf("%s",yytext);  return INT ;   }
int { printf("%s",yytext); return TINT;}
true { printf("%s",yytext); return TRUE;}
false { printf("%s",yytext); return FALSE;}
bool { printf("%s",yytext); return BOOL ;}
bigen { printf("%s",yytext); return DEBUT ;}
[a-zA-Z_][0-9a-zA-Z_]* { printf("%s",yytext); return IDF ;}
"(" {printf("%s",yytext); return PAR1 ; }
 \n  {printf("%s",yytext); return LIGN; }
")" {printf("%s",yytext); return PAR2 ;}
"+" {printf("%s",yytext); return ADD ;}
"-" {printf("%s",yytext); return SUB ; }
"*" {printf("%s",yytext); return MULT ; }
"/" {printf("%s",yytext); return DIV ; }
"=" {printf ("%s" ,yytext); return EGAL; }


%%
