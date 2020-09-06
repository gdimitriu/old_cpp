/*
	le logiciel pour la probleme 6 de calcul distribuite avec socket
*/
#include"../commun/commun.h"
#include"client.h"
char fin;
int dim;
int main(int argc,char **argv)
{
	struct adresse_client *ptemp;
	int i,j;
	padresse=config_client();
	client_socket=(int *)calloc(server_nr,sizeof(int));
	server_addr=(struct sockaddr_in *)calloc(server_nr,sizeof(struct sockaddr_in));
	ptemp=padresse;
	//cree la liassion de client a servers
	for(i=0;i<server_nr,ptemp!=NULL;i++,ptemp=ptemp->suivant)
	{
		server_addr[i].sin_family=AF_INET;
		server_addr[i].sin_port=htons(ptemp->port);
		server_addr[i].sin_addr.s_addr=inet_addr(ptemp->IP);
		if((client_socket[i]=socket(AF_INET,SOCK_STREAM,0))<0)
		{
			perror("l'erreur de socket");
			for(j=0;j<i;j++) close(client_socket[j]);
			exit(-1);
		}
		if(connect(client_socket[i],(struct sockaddr *)&server_addr[i],sizeof(server_addr[i]))<0)
		{
			perror("l'erreur de connect");
			for(j=0;j<i+1;j++) close(client_socket[j]);
			exit(-2);
		}
	}
	ptemp=padresse->suivant->suivant;
	i=0;
	j=0;
	while(ptemp!=NULL)
	{
		if(i==NR_TREE)
		{
			i=0;;
			j++;
		}
		dim=strlen(ptemp->IP)+1;
		send(client_socket[j],&dim,sizeof(int),0);
		send(client_socket[j],ptemp->IP,dim,0);
		send(client_socket[j],&ptemp->port,sizeof(ptemp->port),0);
		i++;
		ptemp=ptemp->suivant;
	}
	//fini la transmetre de l'adresse
	dim=0;
	for(i=0;i<server_nr;i++)
		send(client_socket[i],&dim,sizeof(int),0);
	for(i=0;i<server_nr;i++)
		recv(client_socket[i],&dim,sizeof(int),1);
	ptemp=padresse;
	for(i=0;i<NR_TREE&&i<server_nr;i++,ptemp=ptemp->suivant) bcast_snd(ptemp,i);
	//elibere la memoire pour l'adresse qui sont transmise
	while(padresse!=NULL)
	{
		ptemp=padresse;
		padresse=padresse->suivant;
		free(ptemp->IP);
		free(ptemp);
	}
	//fait des testes
	for(i=0;i<NR_TREE&&i<server_nr;i++)
		send(bcast_str.snd[i],&"test",strlen("test")+1,0);
	scanf("%c",&fin);
	dim=0;
	for(i=0;i<server_nr;i++) send(client_socket[i],&dim,sizeof(int),0);
	//ferme tout
	for(i=0;i<server_nr;i++) close(client_socket[i]);
	for(i<0;i<NR_TREE&&i<server_nr;i++) close(bcast_str.snd[i]);
}