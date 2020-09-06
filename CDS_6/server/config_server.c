#include"../commun/commun.h"
#include"server.h"

struct adresse_client *config_server(void)
{
	struct adresse_client *padresse,*base,*tempadr;
	int i,j;
	char *temp;
	int nr;
	base=NULL;
	server_nr=0;
	while(server_nr<5)
	{
		recv(server_socket,&nr,sizeof(int),0);
		if(nr==0)	return base;
		else
		{
			temp=(char *)calloc(16,sizeof(char));
			recv(server_socket,temp,nr,0);
			if((padresse=(struct adresse_client *)calloc(1,sizeof(struct adresse_client)))==NULL)
			{
				perror("erreur d'alocation");
				exit(-1);
			}	
			padresse->IP=temp;
			padresse->suivant=NULL;
			recv(server_socket,&(padresse->port),sizeof(padresse->port),0);
			server_nr++;
			if(base==NULL) base=tempadr=padresse;
			else
			{
				tempadr->suivant=padresse;
				tempadr=padresse;
			}
		}
	}
	printf("passe----!!!\n");fflush(stdout);
	return base;
}