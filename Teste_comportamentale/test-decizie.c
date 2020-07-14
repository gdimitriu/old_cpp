/* 	test pentru decizie 	*/
#include <stdio.h>
#include <curses.h>
int rezultat,tmp;

/* functie de calcul*/
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
			printf("\n Otiune incorecta !\n");
			return(1);
	}
}
void main(void)
{	
	initscr();cbreak();echo();
	clear();
	refresh();
	rezultat=0;
	/* introducere */
	printf("\nPare ceva simplu sa stii sa alegi intre diverse alternative si sa stabilesti");
	printf("\ncel ami bun lucru pe care trebuie sa-l faci.Insa,procesul decizional este unul");
	printf("\ndintre cele mai complexe activitati ale psihicului nostru.Cind sint mai multe");
	printf("\nvariante ale jocului,sa alegi una buna repede nu este joaca de copil.Stii");
	printf("\n sa decizi repede si corect ? Ori ai mereu dubii si incertitudini ? Raspunde");
	printf("\nla intrebari si vei avea o imagine a spiritului tau de decizie.");
	printf("\n Raspunde la urmatoarele intrebari alegind,in functie de gradul preferintelor");
	printf("\nde la 1 la 5: 1=niciodata; 2=putin; 3=citeodata; 4=adesea; 5=mereu.");
	printf("\n Apasati o tasta pentru continuare.");
	refresh();
	getch();
	clear();refresh();
	/* intrebarile propriu-zise */
	printf("\n INTREBAREA 1:");
	printf("\nTi se ofrera o slujba provizorie dar bine platita. Daca accepti pierzi locul");
	printf("\nsigur pe care il ai. Iti e dificil sa alegi ? \n");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 2:");
	printf("\n Te lasi pe mina sortii cind decizi ce ai de facut ? \n");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 3:");
	printf("\n Esti invitat la o petrecere eleganta. Risti sa intirzii pentru ca nu ai");
	printf("\n stiut cu ce haine sa te imbraci ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 4:");
	printf("\n Doresti ca altii sa decida pentru tine ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 5:");
	printf("\n Ti se intimpla (sau ti s-ar putea intimpla) sa traiesti doua povesti  de");
	printf("\n iubire in acelasi timp ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 6:");
	printf("\n Intri intr-un magazin ca sa-ti cumperi o pereche de pantofi. Dupa ce ai");
	printf("\n probat vreo doua duzini tot nehotarit esti ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 7:");
	printf("\n Dupa ce faci o alegere, ai regrete ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 8:");
	printf("\n Este dificil, pentru tine, sa te decizi unde pleci in vacanta ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	/* interpretare rezultate */
	
	if ((rezultat>=8)&&(rezultat<=18))
	{
		printf("\n Esti un tip decis. Sti intotdeuna ce vrei, si sti cum sa ajungi pe strada ta");
		printf("\n chiar daca te asalteaza dubiile.");
	}
	if ((rezultat>=19)&&(rezultat<=31))
	{
		printf("\n Uneori, inainte, de a face o alegere gindesti prea mult si asta iti intirzie");
		printf("\n operatiunile.");
	}
	if ((rezultat>=32)&&(rezultat<=40))
	{
		printf("\n Sa decizi pentru tine este un adevarat cosmar. Ti-e teama sa risti,");
		printf("\n nesiguranta ta de fond te paralizeaza. Relaxeaza-te si nu mai lua totul in");
		printf("\n serios. \n");
	}
	refresh();
	getch();
}