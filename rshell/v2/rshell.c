/* Programul client pentru remote shell */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#define SIZE 512
#define PORT 12345
#define PORT_COM 20000

static char buff[SIZE];			//bufferul de mesaj
int main(int argc, char **argv)
{
int client_socket;		//socketul client
struct sockaddr_in server_addr;
int client_socket_com;	//socketul client comunicatii
struct sockaddr_in server_addr_com;
int exit1;
int semid;
struct sembuf S={0,-1,0}, R={0,1,0};
FILE *fpipe;				//pipe de iesire
pid_t comunicatii;		//pid pentru procesul de comunicatii	
	if(argc!=2)
	{
		printf("rshell_client adresa");
		exit(1);
	}
	memset((char *)&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);
	memset((char *)&server_addr_com,0,sizeof(server_addr_com));
	server_addr_com.sin_family=AF_INET;
	server_addr_com.sin_port=htons(PORT_COM);
	server_addr_com.sin_addr.s_addr=inet_addr(argv[1]);
	//creare socket
	if((client_socket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("error socket");
		exit(2);
	}
	if((client_socket_com=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("error socket comunicatii");
		close(client_socket);
		exit(2);
	}
	//conectare
	if(connect(client_socket,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
	{
		perror("error connect");
		close(client_socket);
		close(client_socket_com);
		exit(3);
	}
	if(connect(client_socket_com,(struct sockaddr *)&server_addr_com,sizeof(server_addr_com))<0)
	{
		perror("error connect comunicatii");
		close(client_socket);
		close(client_socket_com);
		exit(3);
	}
	semid=semget((key_t)1,1,0666|IPC_CREAT);
	exit1=0;
	while(exit1==0)
	{
		memset((char *)&buff,0,sizeof(buff));
		gets(buff);
		if(strcmp(buff,"exit")==0)
		{
			send(client_socket,buff,strlen(buff),0);
			memset((char *)&buff,0,sizeof(buff));
			recv(client_socket,buff,SIZE,0);
			printf("%s\n",buff);
			close(client_socket);
			close(client_socket_com);
			semctl(semid,0,IPC_RMID,0);
			exit(0);
		}
		else
		{
			if((comunicatii=fork())<0)
			{
				perror("eroare fork comunicatii");
				send(client_socket,"exit",4,0);
				recv(client_socket,buff,SIZE,0);
				close(client_socket);
				close(client_socket_com);
				semctl(semid,0,IPC_RMID,0);
				exit(4);
			}
			else if(comunicatii==0)	//proces de comunicatii
			{
				printf("intrare %d",semctl(semid,0,GETVAL,0));
				semop(semid,&R,1);
				while(1)
				{
					memset((char *)&buff,0,sizeof(buff));
					recv(client_socket_com,buff,SIZE,0);
					if(strcmp(buff,"END")==0)
					{
						semop(semid,&S,1);
						printf("iesire %d",semctl(semid,0,GETVAL,0));
						exit(-2);
					}
				}
			}
			sleep(1);
			send(client_socket,buff,strlen(buff),0);
			while(semctl(semid,0,GETVAL,0)!=0)
			{
				memset((char *)&buff,0,sizeof(buff));
				recv(client_socket,buff,SIZE,0);
				printf("%s ",buff);
				send(client_socket_com,"OK",2,0);
				fflush(stdin);
			}
			printf("\n");
		}	
	}
	close(client_socket);
	close(client_socket_com);
	semctl(semid,0,IPC_RMID,0);
	exit(0);
}
