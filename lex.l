%{
  #include<stdio.h>
  #include "y.tab.h"
%}

%%
"date"|"pwd"|"ls"|"whoami"|"clear" {yylval.string=strdup(yytext);return NARGS;}
"rsls" {yylval.string=strdup(yytext);return LS;}
"l" {yylval.opt=(yytext);return OPT;}
"mkdir" {yylval.string=strdup(yytext);return ARG1;}
"rsmv"|"rscp"|"cat"|"grep"	{yylval.string=strdup(yytext);return ARGS;}
[a-zA-Z][a-zA-Z0-9]* {yylval.a=strdup(yytext);return ID;}
. {;}
\n {;}
%%

