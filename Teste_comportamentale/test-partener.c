#include<stdio.h>
#include<curses.h>
int rezultat; 
char a;
int  rezultat;

/* functie pentru prelucrare ( punctaj) */
int prelucrare(char b)
{
	switch(b)
	{
		case 'A':
		case 'a':
			rezultat=rezultat+6;
			return(0);
			break;
		case 'B':
		case 'b':
			rezultat=rezultat+3;
			return(0);
			break;
		case 'C':
		case 'c':
			return(0);
			break;
		default:
			printf("optiune incorecta");
			return(1);
			break;
	}
}
	
void main()
{	
	/* setari pentru curses */
	rezultat=0;
	initscr();
	cbreak();
	echo();
	clear();
	refresh();
/* acestea se pun numai in cazul functionarii singulare a programului */
/*
	printf("\n TEST ");
	printf("\n Determina daca actualul partener este");
	printf("\n cel care vi se potriveste cu adevarat");
	printf("\n Apasati orice tasta pentru continuare \n");
	refresh();
	getch();
	clear(); 
	refresh();
*/
	printf("\n INTREBAREA 1");
	printf("\n Astepti de citeva ore bune sa te sune iubitul. Cind in ");
	printf("\n sfirsit telefonul suna, cum reactionezi:");
	printf("\na) Astepti linistita sa-ti dea o explicatie");
	printf("\nb) Tipi la el, dupa care inchizi telefonul");
	printf("\nc) Ti-e indiferent: la urma urmei, nu e centrul universului!");
	printf("\n Introduceti a,b,c \n");
	refresh();
	do
	{
		a=getch();
	}
	while(prelucrare(a)==1);
	clear();
	refresh();
	printf("\n INTREBAREA 2");
	printf("\n Ultima ta cucerire e un tip ""trasnet"".Ce faci mai intii:");
	printf("\na) Il prezinti la toata lumea, mindra de achizitia ta.");
	printf("\nb) Mai lasi ceva timp pina sa te afisezi");
	printf("\nc) Te consulti mai intii cu prietena ta cea mai buna");
	printf("\n Introduceti a,b,c \n");
	refresh();
	do
	{
		a=getch();
	}
	while(prelucrare(a)==1);
	clear();
	refresh();
	printf("\n INTREBAREA 3");
	printf("\n Vorbestideschis cu partenerul tau despre sex ?");
	printf("\na) Discuti deschis orice problema");
	printf("\nb) Citeodata, dar nu esti sigura ca te intelege");
	printf("\nc) Niciodata");
	printf("\n Introduceti a,b,c \n");
	refresh();
		do
	{
		a=getch();
	}
	while(prelucrare(a)==1);
	clear();
	refresh();
	printf("\n INTREBAREA 4");
	printf("\n Ce parere ai despre caracterul partenerului tau ?");
	printf("\na) Il  iei asa cum e, chiar daca are mici greseli.");
	printf("\nb) Incerci sa-i corectezi greselile");
	printf("\nc) Crezi ca e foarte incapatinat, pentru ca nu vrea sa-ti urmeze sfaturile");
	refresh();
		do
	{
		a=getch();
	}
	while(prelucrare(a)==1);
	clear();
	refresh();
	printf("\nREZULTATELE TESTULUI SINT:\n");
	if (rezultat<10) 
		{
		printf("\n Ori nu esti capabila de o legatura stabila, ori el nu este partenerul ideal.");
		printf("\n In acest caz, amindoi trebuie sa va schimbati.");
		printf("\n Incercati sa vorbiti deschis despre problemele si grijile care va framinta, poate rezolvati ceva.\n");
		}
		else
		if (rezultat<20)
			{
			printf("\n Nu consideri ca ""dragostea e oarba"", dar nici nu esti o persoana rece, indiferenta");
			printf("\n Cu putina incredere si mai mult noroc, relatia ar putea deveni excelenta.");
			printf("\n Totusi daca partenerul nu se ridica la cerintele tale, renunta la el si cauta-ti ""jumatatea""!\n");
			}
		else
			{
			printf("\n Sincere felicitari ! poti fi mindra de partenerul tau.");
			printf("\n Faptul ca discutati deschis orice problema exclude neintelegerile si ");
			printf("\n suspiciunile.");
			printf("\n Chiar daca nu e perfect, el e ""alesul"" vietii tale!\n");
			}
	refresh();
	getch();
}