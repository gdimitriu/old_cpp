/* Programul client pentru remote shell */
/*
	Copyright 2000 Gabriel Dimitriu

	This file is part of Remote Shell.
	This file contains the implementation of the client for Remote Shell.
	
    Remote Shell is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Remote Shell is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Remote Shell; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#define SIZE 512
#define PORT 12345

static char consola[SIZE];			//buffer de consola
static char buff[SIZE+3];			//bufferul de date
static char data[SIZE];				//buffer pentru afisare
static char pager[SIZE];			//buffer pentru pager
static char sincro[3];				//buffer pentru sincronizare
int main(int argc, char **argv)
{
int client_socket;		//socketul client
struct sockaddr_in server_addr;
int i,j;						//contoare
int exit1,exit2,pipe;   //sincronizari
FILE *fpipe;				//pipe de iesire
	if(argc!=2)
	{
		printf("rshell_client adresa");
		exit(1);
	}
	memset((char *)&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);
	//creare socket
	if((client_socket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("error socket");
		exit(2);
	}
	//conectare
	if(connect(client_socket,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
	{
		perror("error connect");
		close(client_socket);
		exit(3);
	}
	exit1=0;
	while(exit1==0)
	{
		memset((char *)&consola,0,sizeof(consola));
		memset((char *)&data,0,sizeof(data));
		memset((char *)&pager,0,sizeof(pager));
		gets(consola);
		i=0;
		while((consola[i]!='|')&&(i<SIZE))
		{
			data[i]=consola[i];			
			i++;
			if(consola[i]=='|') pipe=1;
		}
		if(pipe==1)
		{
			j=0;i++;
			while(i<SIZE)
			{
				pager[j]=consola[i];
				i++;
				j++;
			}
		}
		if((strcmp(pager,"less")==0)||(strcmp(pager,"more")==0))
		{
			if((fpipe=(FILE *)popen(pager,"w"))==(FILE *)NULL)
			{
				perror("nu se poate deschide pipe");
				strcpy(data,"exit");
				pipe=0;
			}
			else pipe=1;
		}
		else pipe=0;
		if(strcmp(data,"exit")==0)
		{
			send(client_socket,data,strlen(data),0);
			memset((char *)&buff,0,sizeof(buff));
			recv(client_socket,buff,SIZE+3,0);
			for(i=0;i<SIZE;i++) data[i]=buff[i];
			printf("%s\n",data);
			close(client_socket);
			exit(0);
		}
		else
		{
			send(client_socket,data,strlen(data),0);
			exit2=0;
			while(exit2==0)
			{
				memset((char *)&buff,0,sizeof(buff));
				recv(client_socket,buff,SIZE+3,0);
				for(i=0;i<SIZE;i++) data[i]=buff[i];
				for(i=0;i<3;i++)	sincro[i]=buff[SIZE+i];
				if(strcmp(sincro,"END")==0) exit2=1;
				if(strcmp(sincro,"000")==0) exit2=0;
				if(pipe==0)		printf("%s ",data);
				if(pipe==1)		fprintf(fpipe,"%s",data);
				fflush(stdin);
			}
			if(pipe==0)	printf("\n");
			if(pipe==1)
			{
				fprintf(fpipe,"\n");
				pclose(fpipe);
			}
		}	
	}
	close(client_socket);
	exit(0);
}
