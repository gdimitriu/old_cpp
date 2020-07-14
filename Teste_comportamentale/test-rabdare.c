/* test pentru rabadare */
#include<stdio.h>
#include<curses.h>
int tmp,rezultat;

/* functie de calcul */
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
			printf("\n Greasala ! Apasa 1,2,3,4,5");
			return(1);
			break;
	}
}

void main()
{
	rezultat=0;
	initscr();cbreak();echo();
	clear();refresh();
	printf("\n rabdarea este,cum spune proverbul,virturtea celor puternici. Ori de cite");
	printf("\nori dorim sa atingem un obiectiv important al vietii noastre se pune problema");
	printf("\nde a sti sa asteptam momentul cel mai prielnic. Cei rabdatori reusesc acest ");
	printf("\nlucru,altii insa,dintr-o pripeala prost inteleasa,reusesc sa-l rateze.Asta");
	printf("\nconsta in a sti sa ai rabdare.Sigur,nici prea multa rabdare nu este buna,");
	printf("\ncaci in aceasta situatie riscam sa devenim persoane inerte care nu reusesc sa");
	printf("\n realizeze nimic in viata.");
	printf("\n Raspunde la urmatoarele intrebari alegind,in functie de gradul preferintelor,");
	printf("\n de la 1 la 5: 1=niciodata; 2=putin; 3=citeodata; 4=adesea; 5=mereu.");
	printf("\n Apasa orice tasta pentru a continua.");
	refresh();
	getch();
	clear();refresh();
	printf("\n INTREBAREA 1:");
	printf("\nUnui prieten ii place sa povesteasca vechi snoave din tinerete.Il asculti");
	printf("\nchiar daca te plictiseste ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 2:");
	printf("\n Te atrage o persoana care stie sa astepte,rabdatoare ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 3:");
	printf("\n Lumea are incredere in tine pentru stzapinirea de sine ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 4:");
	printf("\n Iti place activitatile solitare ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 5:");
	printf("\nLa oficiul postal e coada.Lasi pe a doua zi sau te asezi la coada si astepti");
	printf("\n sa-ti vina rindul.");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 6:");
	printf("\n I-ai explicat colegului tau de 3 ori in ce consta proiectul comun.Cu calm");
	printf("\n ii explici si a patra oara.");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 7:");
	printf("\n Trebuie sa dam o alta sansa celui care ne-a inselat asteptarile si increderea");
	printf("\nEsti de acord cu acesta idee ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	printf("\n INTREBAREA 8:");
	printf("\n Iti plac copiii chiar si atunci cind sint vioi si capriciosi ?");
	refresh();
	do
	tmp=getch();
	while(calcul(tmp)==1);
	clear();refresh();
	/* interpretarea rezultatelor */
	if ((rezultat>=8)&&(rezultat<=18))
	{
		printf("\n Nu se poate spune ca esti un campion al rabdarii. Iti pierzi cu usurinta");
		printf("\n rabdarea,detesti asteptarea si numai gindul ca iti pierzi timpul te face");
		printf("\n sa-ti iesi din minti.");
	}
	if ((rezultat>=19)&&(rezultat<=31))
	{
		printf("\n Rabdarea ta (care nu este putina) are o limita.De aceea uneori unele lucruri");
		printf("\n te scot din sarite.");
	}
	if ((rezultat>=32)&&(rezultat<=40))
	{
		printf("\nEsti calm intelept tolerant.Asa te percepe toata lumea,ai o mare capacitate");
		printf("\n de a intelege ceea ce se intimpla in jurul tau.Ai grija sa nu cazi in ");
		printf("\n INDIFERENTA.");
	}
	printf("\n");
	refresh();
	getch();
	clear();refresh();
}