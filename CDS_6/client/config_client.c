#include"../commun/commun.h"
#include"client.h"

struct adresse_client *config_client(void)
{
	char *file_name;
	FILE *fp;
	struct adresse_client *padresse,*base,*tempadr;
	char *temp;
	char temp1[20];
	int i,j;
	int flag=0;
	
	base=NULL;
	server_nr=0;
	//pour le teste
	file_name=(char *)calloc(11,sizeof(char));
	file_name="config.dat";
	temp=(char *)calloc(50,sizeof(char));
	if((fp=(FILE *)fopen(file_name,"r"))==NULL)
	{
		perror("config file");
		exit(-1);
	}
	while(!feof(fp))
	{
		if((temp=fgets(temp,50,fp))==NULL)
		{
			return base;
		}
		if((padresse=(struct adresse_client *)calloc(1,sizeof(struct adresse_client)))==NULL)
		{
			perror("erreur de alocation");
			exit(-1);
		}
		padresse->IP=(char *)calloc(16,sizeof(char));
		padresse->suivant=NULL;
		flag=0;j=0;
		for(i=0;i<strlen(temp);i++)
		{
			if((temp[i]!=':')&&(flag==0)) padresse->IP[i]=temp[i];
			else
			{
			 	if(temp[i]==':')
			 	{
			 		flag=1;
			 		padresse->IP[i]='\0';
			 	}
				else
				{
					temp1[j]=temp[i];
					j++;
				}
			}
		}
		temp1[j]='\0';
		padresse->port=atol(temp1);
		server_nr++;
		if(base==NULL) base=tempadr=padresse;
		else
		{
			tempadr->suivant=padresse;
			tempadr=padresse;
		}
	}
	fclose(fp);
	free(temp);
	return base;
}