/* Programul SERVER pentru remote shell */
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
#define PORT_COM 20000

static char buff[SIZE];			//bufferul de mesaj
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
int listen_socket_com,		//socket pentru ascultare pentru comunicatii
	server_socket_com,		//socket pentru server pentru comunicatii
	client_len_com;			//lungimea adresei client
struct sockaddr_in
	server_addr_com,		//adresa serverului pentru comunicatii
	client_addr_com;		//adresa clientului pentru
int n;
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
	//creare socket
	if((listen_socket_com=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("listen error comunicatii");
		exit(1);
	}
	memset((char *)&server_addr_com,0,sizeof(server_addr_com));
	server_addr_com.sin_family=AF_INET;
	server_addr_com.sin_port=htons(PORT_COM);
	server_addr_com.sin_addr.s_addr=htonl(INADDR_ANY);
	//legare (bind)
	if(bind(listen_socket_com,(struct sockaddr *)&server_addr_com,sizeof(server_addr_com))<0)
	{
		perror("bind error comunicatii");
		close(listen_socket_com);
		exit(2);
	}
	if(listen(listen_socket_com,5)<0)
	{
		perror("listen socket error comunicatii");
		close(listen_socket_com);
		exit(3);
	}
	client_len_com=sizeof(client_addr_com);
	while(1)
	{
		//acceptare conexiune
		if((server_socket=accept(listen_socket,(struct sockaddr *)&client_addr,&client_len))<0)
		{
			perror("accept error");
			close(listen_socket);
			close(listen_socket_com);
			exit(4);
		}
		if((client=fork())<0)
		{
			perror("fork client error");
			close(server_socket);
			close(listen_socket);
			close(listen_socket_com);
			exit(5);
		}
		if(client==0)	//proces client
		{
			//acceptare conexiune
			if((server_socket_com=accept(listen_socket_com,(struct sockaddr *)&client_addr_com,&client_len_com))<0)
			{
				perror("accept error comunicatii");
				close(listen_socket);
				close(server_socket);
				close(listen_socket_com);
				exit(4);
			}
			while(1)
			{
				memset((char *)&buff,0,sizeof(buff));
				memset((char *)&argument,0,sizeof(argument));
				n=recv(server_socket,buff,SIZE,0);
				if(strcmp(buff,"exit")==0) 
				{
					send(server_socket,"exit",4,0);
					send(server_socket_com,"exit",4,0);
					close(server_socket_com);
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
					send(server_socket,buff,strlen(buff),0);
					memset((char *)&buff,0,sizeof(buff));
					recv(server_socket_com,buff,SIZE,0);
				}
 				send(server_socket_com,"END",3,0);
				pclose(fpipe);
			}
		}
		if((client=waitpid(client,&status,0))<0)
		{
			perror("error waitpid client");
			close(listen_socket);
			close(listen_socket_com);
			exit(7);
		}
	}
}