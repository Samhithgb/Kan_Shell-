%{
   #include<stdio.h>
   #include<stdlib.h>
   #include<unistd.h>
   #include<string.h>
   #include<sys/types.h>
   #include<sys/wait.h>
   char path[60],arg1[20],arg2[20],command[20],opt[5];
%}
%union{
  char *string;
  char *a;
  char *opt;
  
}
%type <string> NARGS ARGS ARG1 LS EXIT
%type <a> ID
%type <opt> OPT

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
    		if(strcasecmp(command,"exit")==0)
    		{
    			printf("**********************************************************************\n");
    		  sleep(1);
    			
    	printf("...Saving your session with jarvis\n");
    	  sleep(1);
    	printf("...Enter again to ahve a nice interaction next time\n");
    	  sleep(1);
    	printf("...Thanking you for your time and patience\n");
    	  sleep(1);
    	printf("...Goodbye...");
            sleep(1);
            killpg(getppid(),SIGTERM); 
    }
    
    
    		if(strcasecmp(command,"add")==0)
    		{
    			strcpy(command,"./add.sh");
    		}
    		if(strcasecmp(command,"subtract")==0)
    		{
    			strcpy(command,"./sub.sh");
    		}
    		if(strcasecmp(command,"multiply")==0)
    		{
    			strcpy(command,"./mul.sh");
    		}
    		if(strcasecmp(command,"divide")==0)
    		{
    			strcpy(command,"./div.sh");
    		}
       		strcpy(path,"/home/samhith/shell/sanbin/");
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
  	printf("Command not found or Wrong Usage\n");
     	return 0;
}
int main(int argc,char* argv[])
{  
	
   	system("clear");
   	printf("WELCOME TO JARVIS\nPlease enter your query and commands\nListed commands will be exectued\n");
  	while(1)
   	{
		
 	   	printf("Your Query:");	
		yyparse();
 	}     
return 0;
}

