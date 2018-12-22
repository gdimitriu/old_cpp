/* Programul SERVER pentru remote shell */
/*
	Copyright 2000 Gabriel Dimitriu

	This file is part of Remote Shell.
	This file contains the implementation of the server for Remote Shell.
	
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
#include<sys/wait.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#define SIZE 512
#define PORT 12345

static char buff[SIZE+3];			//bufferul de mesaj
static char noend[3]="000";		//mesaj de neterminare pipe
static char end[3]="END";			//mesaj de terminare
char argument[SIZE];				//argumentul
FILE *fpipe;						//pipe
pid_t client;					//pid pentru procese
int status;
int main()
{
int listen_socket,	//socket pentru ascultare
	server_socket,		//socket pentru server
	client_len;			//lungimea adresei client
struct sockaddr_in
	server_addr,		//adresa serverului
	client_addr;		//adresa clientului
int i;
	//creare socket
	if((listen_socket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("listen error");
		exit(1);
	}
	memset((char *)&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	//legare (bind)
	if(bind(listen_socket,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
	{
		perror("bind error");
		close(listen_socket);
		exit(2);
	}
	if(listen(listen_socket,5)<0)
	{
		perror("listen socket error");
		close(listen_socket);
		exit(3);
	}
	client_len=sizeof(client_addr);
	while(1)
	{
		//acceptare conexiune
		if((server_socket=accept(listen_socket,(struct sockaddr *)&client_addr,&client_len))<0)
		{
			perror("accept error");
			close(listen_socket);
			exit(4);
		}
		if((client=fork())<0)
		{
			perror("fork client error");
			close(server_socket);
			close(listen_socket);
			exit(5);
		}
		if(client==0)	//proces client
		{
			while(1)
			{
				memset((char *)&buff,0,sizeof(buff));
				memset((char *)&argument,0,sizeof(argument));
				recv(server_socket,buff,SIZE,0);
				if(strcmp(buff,"exit")==0) 
				{
					send(server_socket,"exit",4,0);
					close(server_socket);
					exit(6);
				}
				strcpy(argument,buff);
				if((fpipe=(FILE *)popen(argument,"r"))==(FILE *)NULL)
				{
					perror("error open pipe");
					exit(7);
				}
				while(!feof(fpipe))
				{
					memset((char *)&buff,0,sizeof(buff));
					fread(buff,sizeof(char),SIZE,fpipe);
					if(!feof(fpipe)) for(i=0;i<3;i++) buff[SIZE+i]=noend[i];
					else for(i=0;i<3;i++) buff[SIZE+i]=end[i];
					send(server_socket,buff,SIZE+3,0);
				}
				pclose(fpipe);
			}
		}
		if((client=waitpid(client,&status,0))<0)
		{
			perror("error waitpid client");
			close(listen_socket);
			exit(7);
		}
	}
}