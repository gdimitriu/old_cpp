#include<stdio.h>
#include<curses.h>
int rezultat=0;
void afisare(void)
{
	if (rezultat>70)
	printf("\n FOARTE BUN\n");
	if ((rezultat>66) && (rezultat<71))
	printf("\n BUN\n");
	if ((rezultat<67) && (rezultat>61))
	printf("\n SUPERIOR MEDIEI\n");
	if ((rezultat<62) && (rezultat>57))
	printf("\n MEDIU");
	if ((rezultat<58) && (rezultat>52))
	printf("\n INFERIOR MEDIEI\n");
	if ((rezultat<53) && (rezultat>48))
	printf("\n SLAB\n");
	if (rezultat<49)
	printf("\n FOARTE SLAB\n");
}
int prelucrare(char a,int numar)
{	
	if (numar>18) 
	{
		switch(a)
		{
			case '1':rezultat=rezultat+1;
				return(1);
				break;
			case '2':rezultat=rezultat+2;
				return(1);
				break;
			case '3':rezultat=rezultat+3;
				return(1);
				break;
			case '4':rezultat=rezultat+4;
				return(1);
				break;
			case '5':rezultat=rezultat+5;
				return(1);
				break;
			default:return(0);
				break;
		}
	}
	else
	{
		switch(a)
		{
			case '1':rezultat=rezultat+1;
				return(1);
				break;
			case '2':rezultat=rezultat+2;
				return(1);
				break;
			case '3':rezultat=rezultat+3;
				return(1);
				break;
			case '4':rezultat=rezultat+4;
				return(1);
				break;
			case '5':rezultat=rezultat+5;
				return(1);
				break;
			default:return(0);
				break;
		}
	}
	}
void main(void)
{
	initscr();cbreak();echo();
/* acestea se pun numai cind programul ruleaza singur */
/*
	clear();refresh();
	printf("\nChestionarul situational de simt al umorului");
	printf("\n Apasati orice tasta pentru continuare.");
	refresh();
	getch();
*/
	clear();refresh();
	printf("\nINTREBAREA 1:");
	printf("\nDaca, vizitind un oras ati zari o persoana care va este cunoscuta ( un coleg");
	printf("\nde serviciu, de exemplu),cum ati reactiona ?");
	printf("\n1) nu as face efortul sa intru in vorba");
	printf("\n2) i-as vorbi, dar nu cu prea mult umor");
	printf("\n3) as spune ceva care sa-i provoace zimbetul");
	printf("\n4) as gasi ceva de spus care sa-i stirneasca risul");
	printf("\n5) am ride impreuna");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do 
	{
	}while(prelucrare(getch(),1)==0);
	clear();refresh();
	printf("\nINTREBAREA 2:");
	printf("\nCum ati reactiona daca,in toiul noptii, v-ar trezi, dintr-un somn adinc,");
	printf("\nsoneria telefonului si, raspunzind, ati afla ca este un vechi prieten care,in");
	printf("\ntrecere prin oras, s-a hotarit sa va sune doar pentru a va auzi ?");
	printf("\n1) nu mar amuza in mod deosebit");
	printf("\n2) m-as simti intrucitva amuzat, dar nu mi-ar stirni risul");
	printf("\n3) as fi in stare s rid la glumele pe care mi le-ar spune");
	printf("\n4) as fi in stare sa rid si sa glumens la rindul meu");
	printf("\n5) am ride mult impreuna");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),2)==0);
	clear();refresh();
	printf("\nINTREBAREA 3:");
	printf("\nDaca in urma unui accident ati fi obligat sa petreceti citeva zile in pat,");
	printf("\nce ati face in timpul acestei perioade de imabilizare?");
	printf("\n1)nu mi sa-ar parea prea amuzant");
	printf("\n2)as zimbi uneori");
	printf("\n3)as zimbi deseori si, uneori as ride");
	printf("\n4)as gasi o multime de motive sa rid");
	printf("\n5)as ride cu pofta majorittea timpului");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),3)==0);
	clear();refresh();
	printf("\nINTREBAREA 4:");
	printf("\n Cum ati proceda daca, dupa o activitate fizica indelungata ( inot, excursie");
	printf("\n, schi, fotbal etc.), v-ati regasi impreuna cu prietenii dumneavoastra, ");
	printf("\ncu toti complet epuizati ?");
	printf("\n1)nu as gasi situati amuzanta");
	printf("\n2)as fi amuzat, dar nu in masura de a ma exterioriza");
	printf("\n3)as zimbi");
	printf("\n4)as ride");
	printf("\n5)as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),4)==0);
	clear();refresh();
	printf("\nINTREBAREA 5:");
	printf("\n Ce ati zice daca,sosind la o petrecere, ati descoperi ca cineva poarta o piesa");
	printf("\n de imbracaminte identica cu a dumneavoastra ?");
	printf("\n1)n-as gasi acest fapt amuzant");
	printf("\n2)as fi amuzat,fara a ma exterioriza");
	printf("\n3)as zimbi");
	printf("\n4)as ride");
	printf("\n5) as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),5)==0);
	clear();refresh();
	printf("\nINTREBAREA 6:");
	printf("\nCum ati reactiona daca un prieten v-ar da spre rezolvare un joc de gindire si ");
	printf("\nati descoperi, spre surpriza prietenului, ca sinteti capabil sa dati foarte");
	printf("\nprompt raspunsul corect ?");
	printf("\n1)n-as gasi acest fapt amuzant");
	printf("\n2)as fi amuzat,fara a ma exterioriza");
	printf("\n3)as zimbi");
	printf("\n4)as ride");
	printf("\n5) as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),6)==0);
	clear();refresh();
	printf("\nINTREBAREA 7:");
	printf("\nIn ce masura sinteti inclinat catre umor in zilele libere pe care va hotariti");
	printf("\n sa le petreceti intr-un mod placut in compania prietenilor ?");
	printf("\n1)activitatea in care ne-am angajat nu ar presupune prea mult zimbet si ris");
	printf("\n2)as zimbi din cind in cind, dar nu as avea ocazia sa rid");
	printf("\n3)as zimbi frecvent si as ride din cind in cind");
	printf("\n4)as ride tare, relativ frecvent");
	printf("\n5)as ride din toata inima majoritatea timpului");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),7)==0);
	clear();refresh();
	printf("\nINTREBAREA 8:");
	printf("\nCe ati zice daca iarna, calatorind cu o masina care, din cauza poleiului, ar");
	printf("\n derapa si s-ar rasuci orientindu-se cu spatele in directia de mers, ati ");
	printf("\nconstata apoi ca atit masina, cit si ocupantii ei sint neatinsi ?");
	printf("\n1)nu as gasi amuzanta aceasta intimplare");
	printf("\n2)as fi amuzat, fara a exterioriza");
	printf("\n3)as zimbi");
	printf("\n4)as ride");
	printf("\n5)as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),8)==0);
	clear();refresh();
	printf("\nINTREBAREA 9:");
	printf("\nDaca urmarind un program la televizor, impreuna cu citiva prieteni,ati gasi ca o");
	printf("\n anumita secventa este distractiva, fara ca vreunul dintre cei prezenti sa dea ");
	printf("\nsemne ca ar fi amuzat de scena respectiva, cum ati reactiona in mod obisnuit ?");
	printf("\n1)as trage concluzia ca m-am inselat, ca scena nu avea nimic vesel in ea");
	printf("\n2)as zimbi in sinea mea, fara a-mi exterioriza amuzamentul");
	printf("\n3)as zimbi in mod vizibil");
	printf("\n4)as ride tare");
	printf("\n5)as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),9)==0);
	clear();refresh();
	printf("\nINTREBAREA 10:");
	printf("\nCum ar fi daca ati petrece o seara romantica in compania persoanei la care");
	printf("\ntineti cu adevarat (iubita/iubit, sotie/sot)?");
	printf("\n1)as fi mai degraba serios (serioasa) in conversatie");
	printf("\n2)as zimbi uneori, dar probabil nu as ride prea mult");
	printf("\n3)as zimbi frecvent si as ride tare din cind in cind");
	printf("\n4) as ride frecvent");
	printf("\n5) as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),10)==0);
	clear();refresh();
	printf("\nINTREBAREA 11:");
	printf("\nCum ati fi reactionat daca ati fi primit, in mod cu totul surprinzator, o nota");
	printf("\nfoarte proasta la un examen si ati fi povestit ulterioracest lucru unui prieten ?");
	printf("\n1)nu as fi fost amuzat");
	printf("\n2)as fi fost amuzat, fara a exterioriza acest fapt");
	printf("\n3)as fi fost capabil sa zimbesc");
	printf("\n4)as fi fost capabil sa rid");
	printf("\n5)as fi ris din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),11)==0);
	clear();refresh();
	printf("\nINTREBAREA 12:");
	printf("\n Ati crezut ca ati recunoscut un prietenm  intr-o incapere aglomerata; ati atras");
	printf("\natentia persoanei si v-ati indreptat spre ea, dar, apropiindu-va, descoperiti ca");
	printf("\nvati inselat, ca este, de fapt o persoana cu totul necunoscuta. Ce ati face ");
	printf("\nin situatia descrisa ?");
	printf("\n1)nu as fi amuzat de situatie");
	printf("\n2)as fi amuzat, fara a exteriza acest fapt");
	printf("\n3)as zimbi");
	printf("\n4)as ride");
	printf("\n5)as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),12)==0);
	clear();refresh();
	printf("\nINTREBAREA 13:");
	printf("\nCe ati face daca, ffiind asezat la o masa, intr-un restaurant, impreuna cu");
	printf("\ncitiva prieteni, ospatarul ar varsa, din greseala, continutul unui pahar pe ");
	printf("\nhaina dumneavoastra");
	printf("\n1)nu as fi amuzat de situatie");
	printf("\n2)as fi amuzat, fara a ma exterioriza");
	printf("\n3)as zimbi");
	printf("\n4)as ride");
	printf("\n5)as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),13)==0);
	clear();refresh();
	printf("\nINTREABAREA 14:");
	printf("\n Ce ati zice daca,in timp ce ati traversa o strada printr-un loc marcat pentru ");
	printf("\ntrecerea pietonilor, un sofer nerabdator, care a trebuiut sa opreasca pentru a ");
	printf("\nva acorda prioritate,v-ar claxona ?");
	printf("\n1)nu as fi amuzat dee situatie");
	printf("\n2)as fi amuzat, fara a exterioriza acest fapt");
	printf("\n3)as zimbi");
	printf("\n4)as ride");
	printf("\n5)as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),14)==0);
	clear();refresh();
	printf("\nINTREBAREA 15:");
	printf("\nCe ati zice daca in urma unei zile de munca ati descoperi ca instrumentul cu");
	printf("\ncare ati lucrat ( de exemplu, un calculator electronic ) a functionat gresit ?");
	printf("\n1)nu as fi amuzat ed situatie");
	printf("\n2)as fi amuzat, fara a exterioriza acest fapt");
	printf("\n3)as zimbi mult");
	printf("\n4)as ride mult");
	printf("\n5)as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),15)==0);
	clear();refresh();
	printf("\nINTREBAREA 16:");
	printf("\nCum ati reactiona daca, profesorul, anuntind ca va comunica rezultatele la un");
	printf("\nexamen si ca va incepe cu notele cele mai bune, ar citi printre primele numele");
	printf("\ndumneavoastra ?");
	printf("\n1)nu as fi amuzat de situatie");
	printf("\n2)as fi amuzat, fara a exterioriza acest fapt");
	printf("\n3)as zimbi");
	printf("\n4)as ride");
	printf("\n5)as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),16)==0);
	clear();refresh();
	printf("\nINTREBAREA 17:");
	printf("\nCe ati fi zis, daca, mai mult, iubita (iubitul) dumneavoastra s-ar fi hotarit sa");
	printf("\nrupa relatia pentru ca s-a atasat de altcineva, iar dupa citeva zile ati fi");
	printf("\npovestit acest lucru unui prieten apropiat ?");
	printf("\n1)n-ar fi gasit nici un strop de umor in aceasta situatie");
	printf("\n2)as fi fost capabil sa ma simt intrucitva amuzat, fara a exterioriza acest fapt");
	printf("\n3)as fi fost capabil sa zimbesc");
	printf("\n4)as fi fost capabil sa rid");
	printf("\n5)as fi ris destul de mult");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),17)==0);
	clear();refresh();
	printf("\nINTREBAREA 18:");
	printf("\nDaca, fiind asezat la o masa, intr-un restaurant, impreuna ca citiva prieteni,");
	printf("\nospatarul ar varsa,din greseala, continutul unui pahar pe haina unuia dintre");
	printf("\nprietenii dumneavoastra.");
	printf("\n1)nu as fi amuzat de situatie");
	printf("\n2)as fi amuzat, fara a arata acest fapt");
	printf("\n3)as zimbi");
	printf("\n4)as ride");
	printf("\n5)as ride din toata inima");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),18)==0);
	clear();refresh();
	printf("\nINTREBAREA 19:");
	printf("\nIn alegerea prietenilor dumneavoastra cit de important considerati ca este ca");
	printf("\nacestia sa aiba dispozitie catre amuzament si ris intr-o mare varietate de ");
	printf("\nsituatii ?");
	printf("\n1)este trasatura pe care o pretuiesc cel mai mult la un prieten");
	printf("\n2)este o trasatura pe care o apreciez mult, fara a o considera cea mai ");
	printf("\nimportanta");
	printf("\n3)este o trasatura pozitiva");
	printf("\n4)este o trasatura care nu-mi spune nimic, nici de bine, nici de rau, despre ");
	printf("\n  un prieten");
	printf("\n5)este o trasatura care ma deranjeaza");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),19)==0);
	clear();refresh();
	printf("\nINTREBAREA 20:");
	printf("\n Cum apreciati ca sinteti din punctul de vedere al dispozitiei catre amuzament");
	printf("\n si ris intr-o mare varietate de situatii ?");
	printf("\n1)este principala mea caracteristica");
	printf("\n2)ma situez deasupra mediei");
	printf("\n3)ma situez la nivelul mediu");
	printf("\n4)ma situez sub nivelul mediu");
	printf("\n5)aceasta trasatura este putin dezvoltata la mine");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),20)==0);
	clear();refresh();
	printf("\nINTREBAREA 21:");
	printf("\nIn ca masura dispozitia dumneavoastra de araspunde cu umor ( prin ris, zimbet");
	printf("\n etc.) depinde de situatia particulara in  care va gasiti ( in ce masura ");
	printf("\n depinde de persoanele care sint de fata, de locul in care va aflati, de felul");
	printf("\n in care va simtiti din punct de vedere fizic etc.) ?");
	printf("\n1)deloc");
	printf("\n2)nu prea mult");
	printf("\n3)intr-o oarecare masura");
	printf("\n4)destul de mult");
	printf("\n5)foarte mult");
	printf("\n Introduceti 1,2,3,4 sau 5");
	refresh();
	do
	{
	}while(prelucrare(getch(),20)==0);
	clear();refresh();
	afisare();
	refresh();
	getch();
	} 	