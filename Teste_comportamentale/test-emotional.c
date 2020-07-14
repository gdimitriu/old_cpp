/*
		 program care testeaza starea emotionala
		 se cumpileaza cu libraria ncurses
*/

#include<stdio.h>
#include<curses.h>
char a;
int rezultat;

/* functie de calcul al rezultatelor */
int calcul(char b)
{
	switch(b)
	{
		case 'd':
		case 'D':
			rezultat=rezultat+5;
			return(0);
			break;
		case 'n':
		case 'N':
			return(0);
			break;
		default:
			printf("\n Optiune incorecta\n");
			return(1);
	}
}

void main(void)
{
	initscr();cbreak();echo();
	clear();
	refresh();
	rezultat=0;
/* se pun numai in cazul functionarii independente */
/*
	printf("\n CONTROLAREA STARII EMOTIONALE\n");
	printf("\n Apasati o tasta pentru continuare");
	refresh();
	getch();
	clear();
	refresh();
*/
	printf("\n INTRABAREA 1:");
	printf("\n Iti pierzi repeda rabdarea?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 2:");
	printf("\n Esti convins(a) de suprematia fortei asupra argumentelor logice?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 3:");
	printf("\n Iti este greu sa te abtii de la certuri atunci cind cineva ");	printf("\n nu este de acord cu tine");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 4:");
	printf("\n Consideri ca oamenii te invidiaza ?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 5:");
	printf("\n Iti place uneori sa-i superi pe altii ?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 6:");
	printf("\n Esti brutal(a) in anumite imprejurari?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 7:");
	printf("\n Iti plac romanele politiste si vizionarea filmelor de groaza ?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 8:");
	printf("\n Iti place sa rizi cu altii, sa fi sarcastic si critic ?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 9:");
	printf("\n In viata ta este cineva pe care il urasti ?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 10:");
	printf("\n Esti deseori recalcitrant ?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 11:");
	printf("\n Va bateti deseori copii cind merita acest lucru ?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 12:");
	printf("\n Considerati ca pedeapsa cu moartea este justificata in anumite cazuri ?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	printf("\n INTRABAREA 13:");
	printf("\n Ati fost vreodata atit de furios incit ati distrus un obiect ?");
	printf("\n da(d) sau nu(n)\n");
	refresh();
	do
	a=getch();
	while(calcul(a)==1);
	clear();
	refresh();
	if (rezultat<20)
		{
			printf("\n Faceti parte dintre persoanele care sint blinde fata de altii,");
			printf("\n considerind ca blindetea e o procedura mai buna decit brutalitatea.");
			printf("\n Sinteti inclinat sa credeti in valorile interne ale omului,deci in");
			printf("\n bunatate,care,intr-adevar, fac parte din civilizatia umana.");
			printf("\n Nu sinteti inclinat ca fara dificultate sa-i convingeti pe altii sa");
			printf("\n realizeze propriile scopuri.");
			printf("\n Dar stapinirea dumneavoastra emotionala este nu o data legata de lipsa");
			printf("\n singurantei de sine si de subordonarea fata de altii.");
			printf("\n Cu siguranta ca puteti constitui obiectul unor agresiuni venite din partea");
			printf("\n altor persoane.");
			printf("\n");
			printf("\n");
			printf("\n Nu confundati hotarirea cu agresiunea.");
			printf("\n Nu permiteti sa vi se urce altii in cap.\n");
			refresh();
		}
	else
		{
			printf("\n Nu se poate ascunde faptul ca sinteti inclinat a vea impulsuri agresive");
			printf("\n si va puteti pierde autocontrolul.");
			printf("\n Continutul afirmatiilor dumneavoastra ca forma si elemente insotitoare lor,");
			printf("\n ca mimica, gesturile, nu o data tind a face rau altora si a-i rani.");
			printf("\n Puteti chiar sa nu stiti ca asa-zisa ""exprimare a adevarului on fata");
			printf("\n este pentru dumneavoastra numai o manifestare a enervarii");
			printf("\n De asemenea, exprimarea clara a unor opinii nefavorabile asupra unor");
			printf("\n cunoscuti si apropiati, ridicarea tonului s argumentarea dura impotriva");
			printf("\n altor puncte de vedere nu reprezinta altceva decit manifestari ale agresiunii.");
			printf("\n Oare acest lucru este realmente constructiv ?");
			printf("\n Ginditi-va la asta. Poate o sa reusiti sa inlocuiti sarcasmul cu umorul.\n");
		}
	refresh();
	getch();
}