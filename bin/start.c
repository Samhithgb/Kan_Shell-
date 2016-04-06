#include<stdio.h>
#include "lex.yy.c"
#include "y.tab.c"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
printf("Welcome \n");
yyparse();
return 0;
}

