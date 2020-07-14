/* 	test pentru verificarea increderii 	*/
#include <stdio.h>
#include <curses.h>
int rezultat,tmp;

/* functie de calcul a punctajului */
int calcul(int a)
{
	switch(a)
	{
		case '1':
			rezultat=rezultat+1;
			return(0);
			break;
		case '2':
			rezultat=rezultat+2;
			return(0);
			break;
		case '3':
			rezultat=rezultat+3;
			return(0);
			break;
		case '4':
			rezultat=rezultat+4;
			return(0);
			break;
		case '5':
			rezultat=rezultat+5;
			return(0);
			break;
		default:
			printf("\n Mistake! Push 1,2,3,4,5. ");
			return(1);
	}
}

void main(void)
{
	initscr();cbreak();echo();
	clear();refresh();
	rezultat=0;
	/* introducere */
	printf("\n Sensul responsabilitatii merge mina in mina cu virsta si experienta personala");
	printf("\n Dar sint unele persoane care, desi anii au trecut peste ele, ramin in ");
	printf("\n continuare imature si neserioase, uneori prea egoiste si superficiale. Ca sa ");
	printf("\n vezi daca esti un tip in care ceilalti au incredere,raspunde la acest test.");
	printf("\n Raspunde la urmatoarele intrebari alegind,in functie de gradul preferintelor");
	printf("\n de la 1 la 5: 1=niciodata; 2=putin; 3citeodataa; 4=adesea; 5 mereu.");
	printf("\n Apasa orice tasta pentru continuare.");
	refresh();
	getch();
	clear();refresh();
	printf("\n INTREBAREA 1:");
	printf("\n Parintii si prietenii pot conta pe tine ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 2:");
	printf("\n Reusesti sa infrunti dificultatile cu simtul echilibrului ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INREBAREA 3:");
	printf("\n Asculti un mesaj pe robotul telefonic. Un prieten are nevoie de tine urgent.");
	printf("\n Il suni imediat ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 4:");
	printf("\n Ti se incredinteaza sarcini care presupun responsabilitate ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 5:");
	printf("\n Esti punctual la intilniri ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 6:");
	printf("\n Copil fiind,la scoala si in familie,erai laudat pentru seriozitatea ta ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 7:");
	printf("\n La serviciu,esti un timp precis si scrupulos ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 8:");
	printf("\n In probleme economice, esti atent sa nu te intinzi mai mult decit ti-e");
	printf("\n plapuma ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	/* interpretare rezultate */
	if((rezultat>=8)&&(rezultat<=18))
	{
		printf("\n Nu esti absolut deloc iun tip de incredere. Traversezi un moment de criza");
		printf("\n sau asa esti mereu flusturatic");
	}
	if((rezultat>=19)&&(rezultat<=31))
	{
		printf("\n Esti un tip cu capul pe umeri, dar de multe ori nu reusesti sa dai friu liber");
		printf("\n micilor nebunii");
	}
	if ((rezultat>=32)&&(rezultat<=40))
	{
		printf("\n Onestitate,responsabilitate,om de incredere. Ai atitea calitati indiscutabile");
		printf("\nO singura grija trebuie sa ai: sa nu devii plicticos si obsesiv.");
	}
	refresh();
	getch();
	clear();refresh();
}