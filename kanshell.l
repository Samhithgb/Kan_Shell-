%{
  #include<stdio.h>
  #include "y.tab.h"
  char path[100];
%}

%%
"dinanka"|"file patti prakatisu"|"swacha madu"|"koodisu"|"bhagisu"|"kale"|"gunisu"|"hosa file tere"|"tariku"|"h"|"sahaya"|"firefox"|"antarjaala"|"facebook" {yylval.string=strdup(yytext);return NARGS;}
"hosa directory tere"|"directory tegedu haku"|"file tegedu haku" {yylval.string=strdup(yytext);return ARG1;}
"prati madu"|"sthala badalayisu"|"jote goodisu"|"huduku"  {yylval.string=strdup(yytext);return ARGS;}
"mugisu"|"stop"|"nillisu"|"nirgamisu" {return EXIT;}
[a-zA-Z][a-zA-Z0-9]* {yylval.a=strdup(yytext);return ID;}
[a-zA-Z][a-zA-Z0-9]*\.[a-zA-Z]+ {yylval.a=strdup(yytext);return ID;}
\n {;}
%%
