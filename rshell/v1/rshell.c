/* Programul client pentru remote shell */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#define SIZE 2048
#define PORT 12345

static char buff[SIZE];			//bufferul de mesaj
int main(int argc, char **argv)
{
int client_socket;	//socketul client
struct sockaddr_in server_addr;
int exit1=0;
int exit2=0;
	memset((char *)&server_addr,0,sizeof(server_addr));
	if(argc!=2)
	{
		printf("rshell_client adresa");
		exit(1);
	}
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
		exit(3);
	}
	while(exit1==0)
	{
		gets(buff);
		if(strcmp(buff,"exit")==0)
		{
			send(client_socket,buff,strlen(buff),0);
			memset((char *)&buff,0,sizeof(buff));
			recv(client_socket,buff,SIZE,0);
			printf("%s\n",buff);
			exit1=1;
		}
		else
		{
			send(client_socket,buff,strlen(buff),0);
			exit2=0;
			while(exit2==0)
			{
				memset((char *)&buff,0,sizeof(buff));
				recv(client_socket,buff,SIZE,0);
				if(strcmp(buff,"END")==0) exit2=1;
				else	printf("%s",buff);
			}
			printf("\n");
		}	
	}
	close(client_socket);
	exit(0);		
}