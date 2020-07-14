/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of Parallel Computing Laboratory.
	This file implement a simple shell with pipe and background processes.
	
    Parallel Computing Laboratory is free software; you can redistribute 
	it and/or modify it under the terms of the GNU General Public License 
	as published by the Free Software Foundation; either version 2 of the
	License, or (at your option) any later version.

    Parallel Computing Laboratory is distributed in the hope that it will 
	be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
	of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Parallel Computing Laboratory; if not, write to the Free 
	Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  
	02111-1307  
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	static char message[512]; 	//linia de comanda
	char **argv1,**argv2;
	char *temp;
	int pipedesc[2];
	pid_t pid1,pid2;	//pid of the process
	int flag;	//exit flag
	int ant,i,j; //pentru verificarea nr de argumente
	int offset;
	int pipef; //pipe
	int back; //background
	int lungime;
	int nrarg1,nrarg2;
	flag=0;
	while(flag==0)
	{
		printf("$");fflush(stdout);
		gets(message); //read the command
		fflush(stdin);
		if(strcmp(message,"exit")!=0) //verify if it is exit
		{
			nrarg1=nrarg2=pipef=back=0; //initializations
			//verify the numbers of arguments
			for(i=0;i<strlen(message)+1;i++)
			{
				if(message[i]=='|')  //if I have pipe
				{
					pipef=i;
					nrarg1++;
				}
				if(message[i]=='&') //if I have background
				{
					back=1;
					nrarg1++;
				}
				if(message[i]==' '||message[i]=='\0') //in other cases
				{
					if(pipef==0) //if I have space before pipe
					{
						if(message[i+1]!='|')	nrarg1++;
					}
					else if(message[i-1]!='|') nrarg2++; //if I have space after pipe
				}
			}
			//add 1 for the terminator
			nrarg1++; 
			nrarg2++;
			//memory allocation for arguments
			argv1=(char **)calloc(nrarg1,sizeof(char *));
			if(pipef!=0)	argv2=(char **)calloc(nrarg2,sizeof(char *));
			//compute the length of the first argument
			if(pipef!=0) lungime=pipef;
			else lungime=strlen(message)+1;
			ant=j=0;
			//split the arguments
			for(i=0;i<lungime+1;i++)
				if(message[i]==' '||message[i]=='\0'||message[i]=='&'||message[i]=='|')
				{
					if(ant==0) offset=0; //for the first time
					else offset=ant;
					temp=(char *)calloc(100,sizeof(char));
					//copy the string
					memcpy(temp,message+offset,i-ant);
					//put the terminator
					if(message[i]!='\0') temp[i-ant]='\0';
					ant=i+1;
					argv1[j]=temp;
					j++;
				}
			argv1[nrarg1-1]=(char *)0; //put the terminator
			if(pipef!=0) //if I have pipe
			{
				pipef++;
				if(message[pipef]==' ') ant=pipef+1;
				else ant=pipef;
				j=0;
				for(i=ant;i<strlen(message)+1;i++)
					if(message[i]==' '||message[i]=='\0')
					{
						if(ant==pipef||ant==pipef+1) offset=ant; //for first time
						else	offset=ant+1;
						temp=(char *)calloc(100,sizeof(char));
						//copy the string
						memcpy(temp,message+offset,i-ant);
						//put the terminator
						if(message[i]!='\0') temp[i-ant]='\0';
						ant=i;
						argv2[j]=temp;
						j++;
					}
				argv2[nrarg2-1]=(char *)0; //put the terminator
				//make the pipe
				if(pipe(pipedesc)==-1)
				{
					perror("pipe");
					exit(-1);
				}
			}
			pid1=fork();
			if(pid1==0) //I am in son
			{
				if(pipef!=0)
				{
					close(pipedesc[0]);
					close(1); //close stdout
					dup(pipedesc[1]); //duplicate the stdout
					close(pipedesc[1]);
				}
				execvp(argv1[0],argv1); //execute the command
			}
			else //I am in father
			{
				if(pipef!=0) //if I have pipe
				{	
					pid2=fork();
					if(pid2==0) //I am in son
					{
						close(pipedesc[1]);
						close(0); //close stdin
						dup(pipedesc[0]); //duplicate the stdin
						close(pipedesc[0]);
						execvp(argv2[0],argv2); //execute the command
					}
					for(i=0;i<nrarg2-1;i++) free(argv2[i]);
					free(argv2);
					close(pipedesc[0]);
					close(pipedesc[1]);
					waitpid(pid2,NULL,0); 
				}
				//free the memory
				for(i=0;i<nrarg1-1;i++) free(argv1[i]);
				free(argv1);
				//wait for the son if it isn't in background
				if(back==0)	waitpid(pid1,NULL,0); 
			}
		}
		else flag=1;
	}
}
