#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<curses.h>
char a;
int b;
pid_t pid;
void compatibilitate(void)
{
	do
	{
	clear();refresh();
	printf("\nCe test doriti?");
	printf("\n1: Daca actualul partener ti se potriveste.");
	printf("\n2: Care barbat ti-l doresti.");
	printf("\n3: IESIRE");
	printf("\n Apasati 1,2,3");
	refresh();
	a=getch();
	switch(a)
	{
		case '1':
			if((pid=fork())==0)
			{
			execlp("test-partener","test-partener",NULL);
			exit(127);
			}
			else
				if (waitpid(pid,NULL,0)<0);
			break;
		case '2':
			if((pid=fork())==0)
			{
			execlp("test-b","test-b",NULL);
			exit(127);
			}
			else
				if (waitpid(pid,NULL,0)<0);
			break;
		default:
	}
	}while(a!='3');

}
void social(void)
{
	do
	{
	clear();refresh();
	printf("\nCe test doriti?");
	printf("\n1: Test de incredere.");
	printf("\n2: ");
	printf("\n3: IESIRE");
	printf("\n Apasati 1,2,3");
	refresh();
	a=getch();
	switch(a)
	{
		case '1':
			if((pid=fork())==0)
			{
			execlp("test-incredere","test-incredere",NULL);
			exit(127);
			}
			else
				if (waitpid(pid,NULL,0)<0);
			break;
		case '2':
			if((pid=fork())==0)
			{
			execlp("","",NULL);
			exit(127);
			}
			else
				if (waitpid(pid,NULL,0)<0);
			break;
		default:
	}
	}while(a!='3');

}
void psihologic(void)
{
	do
	{
	clear();refresh();
	printf("\nCe test doriti?");
	printf("\n1: Test pentru starea emotionala.");
	printf("\n2: Test pentru umor.");
	printf("\n3: Test pentru starea decizionala.");
	printf("\n4: test de rabdare.");
	printf("\n5: IESIRE");
	printf("\n Apasati 1,2,3,5");
	refresh();
	a=getch();
	switch(a)
	{
		case '1':
			if((pid=fork())==0)
			{
			execlp("test-emotional","test-emotional",NULL);
			exit(127);
			}
			else
				if (waitpid(pid,NULL,0)<0);
			break;
		case '2':
			if((pid=fork())==0)
			{
			execlp("test-umor","test-umor",NULL);
			exit(127);
			}
			else
				if (waitpid(pid,NULL,0)<0);
			break;
		case '3':
			if((pid=fork())==0)
			{
			execlp("test-decizie","test-decizie",NULL);
			exit(127);
			}
			else
				if (waitpid(pid,NULL,0)<0);
			break;
		case '4':
			if((pid=fork())==0)
			{
			execlp("test-rabdare","test-rabdare",NULL);
			exit(127);
			}
			else
				if (waitpid(pid,NULL,0)<0);
			break;

		default:
	}
	}while(a!='5');
}
void main(void)
{
	initscr();cbreak();echo();
	clear();refresh();
	printf("\nAcesta este un program de verificare a comportamentului");
	printf("\nApasati orice tasta pentru continuare");
	refresh();
	getch();
	b=0;
	do
	{
		clear();
		refresh();
		printf("\nCe fel de test doriti:");
		printf("\n1: Test pshihologic.");
		printf("\n2: Test de compatibilitate.");
		printf("\n3: Test social.");
		printf("\n4: OUT");
		printf("\nPush 1,2,3,4\n");
		refresh();
		a=getch();
		switch(a)
		{
			case '1': 
				psihologic();
				b=0;
				break;
			case '2':
				compatibilitate();
				b=0;
				break;
			case '3':
				social();
				b=0;
				break;
			case '4':				
				b=1;
				break;
			default:
				b=0;
		}
	}while(b==0);
	clear();
	refresh();
	printf("\n");
}