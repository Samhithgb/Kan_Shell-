%{
   #include<stdio.h>
   #include<stdlib.h>
   #include<unistd.h>
   #include<string.h>
   #include<sys/types.h>
   #include<sys/wait.h>
   char path[60],arg1[20],arg2[20],command[25],opt[5];
   int pid;
   char name[100];
%}

%union{
  char *string;
  char *a;
   }

%type <string> NARGS ARGS ARG1 LS EXIT
%type <a> ID

%token NARGS ARGS ARG1 ID OPT LS EXIT
%%

S:F {
                pid_t pid=fork();
		if(pid==-1)
    		{
  		printf("fork Error\n");
      		exit(0);
    		}
  
         	if(pid==0)
    		{   
   
    		if((strcasecmp(command,"exit")==0)||(strcasecmp(command,"nillisu")==0)
    		||(strcasecmp	(command,"nirgamisu")==0))
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
    		if((strcasecmp(command,"firefox")==0)||(strcasecmp(command,"antarjaala")==0))
    		strcpy(command,"./firefox.sh");   
    		if((strcasecmp(command,"facebook")==0)) system("firefox www.fb.com");
    		
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
 F:NARGS{strcpy(command,(char*)$1);}
 |LS OPT{strcpy(command,(char*)$1);strcpy(opt,(char*)$2);}
 |ARG1 ID {strcpy(command,(char*)$1);strcpy(arg1,(void*)$2);} 
 |ARGS ID ID {strcpy(command,(char*)$1);strcpy(arg1,(void*)$2);strcpy(arg2,(void*)$3);};
 |EXIT {strcpy(command,"exit");}
 
%%
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


