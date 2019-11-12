%option noyywrap
/* avoid dependency with library fl  ookkkk*/

%{
#include "y.tab.h"
#include "Table_des_symboles.h"
#include <stdio.h>

%}

whitespace          [ \t\r\n\f]+

digit               [0-9]
alpha               [a-zA-Z]
alnum              [a-zA-Z0-9]

integer             [[:digit:]]+
float               [[:digit:]]+\.[[:digit:]]*
boolean             "true"|"false"

identifier          [[:alpha:]][[:alnum:]_]*

escape              \\([\\"'ntbr ])
string              \"({escape}|[^"\\])*\"


%%
"++"         { return CONCAT;}
"+"          { return PLUS;}
"-"          { return MOINS;}
"*"          { return MULT;}
"/"          { return DIV;}
"="          { return EQ;}
"<"          { return ISLT;}
">"          { return ISGT;}
"<="         { return ISLEQ;}
">="         { return ISGEQ;}
"=="         { return ISEQ;}
"!"          { return NOT;}
"&&"         { return AND;}
"||"         { return OR;}

"let"        {return LET;}
"in"         {return IN;}
"if"         {return IF;}
"then"       {return THEN;}
"else"       {return ELSE;}


{boolean}    {return BOOL;}

"("          {return LPAR;}
")"          {return RPAR;}
"["          {return LBR;}
"]"          {return RBR;}
","          {return VIR;}
";"          {return PV;}

{float}      {yylval.val.valf = atof(yytext); yylval.val.type=Float;return FLOAT; }
{integer}    {yylval.val.value = atoi(yytext); yylval.val.type=Int; return NUM; }
{identifier} {yylval.val.sid = string_to_sid(yytext); return ID;}
{string}     {return STRING;}
{whitespace} ;
