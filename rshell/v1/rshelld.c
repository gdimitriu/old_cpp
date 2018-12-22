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
#define SIZE 2048
#define PORT 12345

static char buff[SIZE];			//bufferul de mesaj
static char mesaj[9]=">/tmp/out";
FILE *fisier;						//fisierul partajat
char argument[SIZE+10];			//argumentul pentru functia de serviciu
pid_t pid,client;					//pid pentru procese
int status;
int main()
{
int listen_socket,	//socket pentru ascultare
	server_socket,		//socket pentru server
	client_len;			//lungimea adresei client
struct sockaddr_in
	server_addr,		//adresa serverului
	client_addr;		//adresa clientului
int i,n,j;
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
				n=recv(server_socket,buff,SIZE,0);
				if(strcmp(buff,"exit")==0) 
				{
					send(server_socket,"exit",4,0);
					exit(6);
				}
				memset((char *)&argument,0,sizeof(argument));
				/*	Realizez argumentul pentru functia de execlp	*/
				for(i=0;i<n;i++) argument[i]=buff[i];
				for(j=0;j<9;j++) argument[i+j]=mesaj[j];
				if((pid=fork())<0) //creez poces pentru servirea clientului
				{
					perror("fork error exec");
					send(server_socket,"exit",4,0);
					exit(7);
				}
				if(pid==0)	//proces fiu
				{
					execlp("bash","bash","-c",argument,(char *)0);
					exit(8);
				}
				if((pid=waitpid(pid,&status,0))<0)
				{
					perror("error waitpid exec");
					exit(6);
				}
				if((fisier=(FILE *)fopen("/tmp/out","r"))==(FILE *)NULL)
				{
					perror("error open file");
					exit(7);
				}
				while(!feof(fisier))
				{
					fread(buff,sizeof(char),2048,fisier);
					send(server_socket,buff,strlen(buff),0);
				}
				send(server_socket,"END",3,0);
				fclose(fisier);
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