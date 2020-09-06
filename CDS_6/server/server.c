#include"../commun/commun.h"
#include"server.h"
static int buf[10];
int main(int argc,char **argv)
{
int listen_socket,client_len;
pthread_t th;
struct sockaddr_in server_addr,client_addr;
struct adresse_client *ptemp;
int i,tr;
int PORT_SERVER;
//FILE *fp;  //pour teste
char filename[20];
	if(argc!=2)
	{
		printf("usage %s port\n",argv[0]);
		exit(-1);
	}
	PORT_SERVER=atoi(argv[1]);
	if((listen_socket=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("error de server socket");
		exit(-1);
	}
	memset((char *)&server_addr,0,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT_SERVER);
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(listen_socket,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
	{
		perror("erreur server bind");
		close(listen_socket);
		exit(-2);
	}
	if(listen(listen_socket,5)<0)
	{
		perror("erreur de listen socket");
		close(listen_socket);
		exit(-3);
	}
	client_len=sizeof(client_addr);
	tr=1;
	
		bcast_str.port=PORT_SERVER+1;
		pthread_create(&th,NULL,bcast_srv,NULL);
		if((server_socket=accept(listen_socket,(struct sockaddr *)&client_addr,&client_len))<0)
		{
			perror("erreur de accept socket");
			close(listen_socket);
			exit(-4);
		}
		padresse=config_server();
	/*//pour testes
		ptemp=padresse;
		sprintf(filename,"%d.txt",PORT_SERVER);
		fp=fopen(filename,"w");
		while(ptemp!=NULL)
		{
			fprintf(fp,"%s:%ld\n",ptemp->IP,ptemp->port);
			fflush(fp);
			ptemp=ptemp->suivant;
		}
		close(fp); */
		send(server_socket,&tr,sizeof(int),1);
		//pour le parent
		pthread_join(th,NULL);
		//pour les fils
		ptemp=padresse;
		for(i=0;i<NR_TREE&&i<server_nr;i++,ptemp=ptemp->suivant) bcast_snd(ptemp,i);
		while(padresse!=NULL)
		{
			ptemp=padresse;
			padresse=padresse->suivant;
			free(ptemp->IP);
			free(ptemp);
		}
		recv(bcast_str.rcv,filename,20,0);
		printf("%s %d\n",filename,PORT_SERVER);fflush(stdout);
		for(i=0;i<NR_TREE&&i<server_nr;i++)
			send(bcast_str.snd[i],filename,strlen(filename)+1,0);
		recv(server_socket,&tr,sizeof(int),0);
		//fermer tout
		close(bcast_str.rcv);
		close(server_socket);	
		for(i=0;i<NR_TREE&&i<server_nr;i++) close(bcast_str.snd[i]);
}