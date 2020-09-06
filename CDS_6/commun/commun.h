#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define NR_TREE 2
struct adresse_client
{
	char *IP;
	long port;
	struct adresse_client *suivant;
};
struct adresse_client *padresse;	//vector d'adresse
int server_nr;
struct thread_bcast_str
{
	long port;
	int rcv;
	int snd[NR_TREE];
};
struct thread_bcast_str bcast_str;
//functions
void *bcast_srv(void *arg);
int bcast_snd(struct adresse_client *padresse,int nr);