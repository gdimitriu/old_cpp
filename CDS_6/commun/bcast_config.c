#include"commun.h"

void *bcast_srv(void *arg)
{
int listen_socket,client_len;
struct sockaddr_in server_addr,client_addr;
int i;
	if((listen_socket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("error de server socket");
		bcast_str.rcv=-1;
		pthread_exit(NULL);
	}
	memset((char *)&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(bcast_str.port);
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(listen_socket,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
	{
		perror("error server bind bcast_srv");
		close(listen_socket);
		bcast_str.rcv=-2;
		pthread_exit(NULL);
	}
	if(listen(listen_socket,5)<0)
	{
		perror("error de listen socket bcast_srv");
		close(listen_socket);
		bcast_str.rcv=-3;
		pthread_exit(NULL);
	}
	client_len=sizeof(client_addr);
	if((bcast_str.rcv=accept(listen_socket,(struct sockaddr *)&client_addr,&client_len))<0)
	{
		perror("error de accept socket bcast_srv");
		close(listen_socket);
		bcast_str.rcv=-4;
		pthread_exit(NULL);
	}
}

int bcast_snd(struct adresse_client *adresse,int nr)
{
	struct adresse_client *ptemp;
	int i,j,flag;
	int client_socket;
	struct sockaddr_in server_addr;
	//cree la liassion de client a server
	memset((char *)&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(adresse->port+1);
	server_addr.sin_addr.s_addr=inet_addr(adresse->IP);
	if((bcast_str.snd[nr]=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("l'erreur de socket bcast_snd");
		close(client_socket);
		return -1;
	}
	flag=0;
	i=0;
	while(flag==0&&i<3)
	{
		if(connect(bcast_str.snd[nr],(struct sockaddr *)&server_addr,sizeof(server_addr))<0) i++;
		else flag=1;
	}
	if(flag==0)
	{
		perror("l'erreur de connect bcast_snd");
		printf("%s:%ld\n",adresse->IP,adresse->port+1);fflush(stdout);
		close(bcast_str.snd[nr]);
		return -2;
	}
	return 0;
}