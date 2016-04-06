/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "kanshell.y"
   #include<stdio.h>
   #include<stdlib.h>
   #include<unistd.h>
   #include<string.h>
   #include<sys/types.h>
   #include<sys/wait.h>
   char path[60],arg1[20],arg2[20],command[25],opt[5];
   int pid;
   char name[100];
#line 12 "kanshell.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
  char *string;
  char *a;
  char *opt;
  
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 45 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NARGS 257
#define ARGS 258
#define ARG1 259
#define LS 260
#define EXIT 261
#define ID 262
#define OPT 263
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    2,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    2,    0,    0,    0,    6,    0,    1,    0,    4,    3,
    5,
};
static const YYINT yydgoto[] = {                          6,
    7,
};
static const YYINT yysindex[] = {                      -257,
    0, -256, -255, -258,    0,    0,    0, -254,    0,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
    0,
};
#define YYTABLESIZE 8
static const YYINT yytable[] = {                          1,
    2,    3,    4,    5,   10,    8,    9,   11,
};
static const YYINT yycheck[] = {                        257,
  258,  259,  260,  261,  263,  262,  262,  262,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 263
#define YYUNDFTOKEN 267
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NARGS","ARGS","ARG1","LS","EXIT",
"ID","OPT",0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : S",
"S : F",
"F : NARGS",
"F : LS OPT",
"F : ARG1 ID",
"F : ARGS ID ID",
"F : EXIT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 113 "kanshell.y"
int yyerror()
{
  	printf("%s,Kshamisi.Nimma adeshavu nanage tiliyuthilla.\n",name);
  	printf("%s,Nimma  mundina adeshavannu  nirikshisuttiddene...\n",name); 
     	return 0;
}

int main(int argc,char* argv[])
{  
	pid=getpid();
   	system("clear");
   	printf("Nimma Hesarannu Tilisi : ");
   	scanf("%s",name);
   	printf("%s,\nSusWagatha!\nNimma nirdeshanavannu tilisi\n",name);
  	while(1)
   	{
		printf("%s,Nimma Adesha Nirikshisuttidene :",name);	
		yyparse();
 	}     
return 0;
}


#line 206 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 25 "kanshell.y"
	{
        pid_t pid=fork();
	if(pid==-1)
    	{
  		printf("fork Error\n");
      		exit(0);
    	}
  
    	if(pid==0)
    	{   
   
    		if((strcasecmp(command,"exit")==0)||(strcasecmp(command,"nillisu")==0)||(strcasecmp(command,"nirgamisu")==0))
    		{
    		sleep(1);
    		printf("Upayogisiddakke dhanyavada. \n");
    	 	sleep(1);
    		printf("Nimma samayakkoskara dhanyavada..\n");
    		sleep(1);
    		printf("..Vandanegalu..");
         	sleep(1);
            	killpg(pid,SIGTERM); 
    }
    		 if(strcasecmp(command,"directory tegedu haku")==0) strcpy(command,"rmdir");
    		 if(strcasecmp(command,"prati madu")==0) strcpy(command,"cp");
   		 if((strcasecmp(command,"dinanka")==0)||(strcasecmp(command,"tariku")==0))strcpy(command,"date");
   		 if(strcasecmp(command,"hosa file tere")==0)strcpy(command,"gedit");
    		if(strcasecmp(command,"hosa directory tere")==0)strcpy(command,"mkdir");
    		if(strcasecmp(command,"file patti prakatisu")==0)strcpy(command,"ls");
    		if(strcasecmp(command,"swacha madu")==0)strcpy(command,"clean_the_screen");
    		if(strcasecmp(command,"sahaya")==0)strcpy(command,"./sahaya.sh");
    		if(strcasecmp(command,"file tegedu haku")==0)strcpy(command,"rm");
    		if(strcasecmp(command,"sthala badalayisu")==0)strcpy(command,"mv");
    		if(strcasecmp(command,"jote goodisu")==0)strcpy(command,"cat");
    		if(strcasecmp(command,"huduku")==0)strcpy(command,"grep");
    		if((strcasecmp(command,"firefox")==0)||(strcasecmp(command,"antarjaala")==0)) strcpy(command,"./firefox.sh");   
    		if((strcasecmp(command,"facebook")==0)) system("firefox www.fb.com");
    		if((strcasecmp(command,"nanu yaaru")==0)) { printf("Nivu Yaarendu Maretire %s?",name)}
         	if(strcasecmp(command,"koodisu")==0)
    		{
    		   
    			strcpy(command,"./add.sh");
    		}
    		if(strcasecmp(command,"kale")==0)
    		{
    			strcpy(command,"./sub.sh");
    		}
    		if(strcasecmp(command,"gunisu")==0)
    		{
    			strcpy(command,"./mul.sh");
    		}
    		if(strcasecmp(command,"bhagisu")==0)
    		{
    			strcpy(command,"./div.sh");
    		}
       		strcpy(path,"/home/samhith/shell/bin/");
        	strcat(path,command);
		if(opt!=NULL)
		{
			strcat(path,opt);
		}
		if(arg1!=NULL)
		{
			strcat(path," ");
			strcat(path,arg1);
		}
		if(arg2!=NULL)
		{
			strcat(path," ");
			strcat(path,arg2);
		} 
		
       		system(path);
		
		
	}
    /* This is the parent process.  Wait for the child to complete.  */
     wait(0);
	return 0;
	
	
}
break;
case 2:
#line 106 "kanshell.y"
	{strcpy(command,(char*)yystack.l_mark[0].string);}
break;
case 3:
#line 107 "kanshell.y"
	{strcpy(command,(char*)yystack.l_mark[-1].string);strcpy(opt,(char*)yystack.l_mark[0].opt);}
break;
case 4:
#line 108 "kanshell.y"
	{strcpy(command,(char*)yystack.l_mark[-1].string);strcpy(arg1,(void*)yystack.l_mark[0].a);}
break;
case 5:
#line 109 "kanshell.y"
	{strcpy(command,(char*)yystack.l_mark[-2].string);strcpy(arg1,(void*)yystack.l_mark[-1].a);strcpy(arg2,(void*)yystack.l_mark[0].a);}
break;
case 6:
#line 110 "kanshell.y"
	{strcpy(command,"exit");}
break;
#line 512 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
