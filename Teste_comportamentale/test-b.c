/*			Care este barbatul la care visati ?
*/
#include<stdio.h>
#include<curses.h>
int romb,triunghi,inima,cerc,b;
char a;
void main(void)
{
	initscr();cbreak();echo();
	romb=triunghi=inima=cerc=0;
	clear();
	refresh();
/* acestea se pun numai in cazul functionarii singulare a programului */
/*
	printf("\n Care este barbatul la care visati ?");
	printf("\n Apasati orice tasta");
	refresh();
	getch();	
	clear();
	refresh();
*/
	printf("\n INTREBAREA 1:");
	printf("\nTrebuie sa oferiti o jucarie din pus unui copil. Ce anume veti alege");
	printf("\n1:Un sarpe cu cascheta.");
	printf("\n2:Un elefant cu ochelari.");
	printf("\n3:Un clovn cu bascheti.");
	printf("\n4:Un ursulet in salopeta.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		switch(getch())
		{
			case '1':inima=inima+1;
				b=0;
				break;
			case '2':cerc=cerc+1;
				b=0;
				break;
			case '3':romb=romb+1;
				b=0;
				break;
			case '4':triunghi=triunghi+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 2:");
	printf("\n Nu stati prea bine cu moralul, dar el s-ar putea sa va remonteze:");
	printf("\n1:Spunindu-va cuvinte lingusitoare.");
	printf("\n2:Sarutindu-va cu pasiune.");
	printf("\n3:Mingiindu-va.");
	printf("\n4:Ducindu-va la restaurant.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':cerc=cerc+1;
				b=0;
				break;
			case '2':inima=inima+1;
				b=0;
				break;
			case '3':triunghi=triunghi+1;
				b=0;
				break;
			case '4':romb=romb+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 3:");
	printf("\n El va propune sa plecati numai voi doi pe o alta planeta. Ce veti alege ?");
	printf("\n1:Luna.");
	printf("\n2:Venus.");
	printf("\n3:Marte.");
	printf("\n4:Jupiter.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':triunghi=triunghi+1;
				b=0;
				break;
			case '2':inima=inima+1;
				b=0;
				break;
			case '3':romb=romb+1;
				b=0;
				break;
			case '4':cerc=cerc+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 4:");
	printf("\n V-ati pierdut catelul. Ati hotarit sa va luati:");
	printf("\n1:Un sarpe boa.");
	printf("\n2:Un paianjen urias.");
	printf("\n3:Un leu.");
	printf("\n4:Un hamster.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':inima=inima+1;
				b=0;
				break;
			case '2':romb=romb+1;
				b=0;
				break;
			case '3':triunghi=triunghi+1;
				b=0;
				break;
			case '4':cerc=cerc+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 5:");
	printf("\n Sa presupunem ca scrieti un roman politist. Unde s-ar petrece actiune ?");
	printf("\n1:La Mosi.");
	printf("\n2:Intr-un orasel de provioncie.");
	printf("\n3:La Gradina Zoologica.");
	printf("\n4:La Moulin-Rouge.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':romb=romb+1;
				b=0;
				break;
			case '2':cerc=cerc+1;
				b=0;
				break;
			case '3':triunghi=triunghi+1;
				b=0;
				break;
			case '4':inima=inima+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();	
	printf("\n INTREBAREA 6:");
	printf("\n Ati terminat de scris romanul. Nu mai aveti de rezolvat decit problema");
	printf("\npseudonimului. Semnati:");
	printf("\n1:Sofia Rosu.");
	printf("\n2:Sfinta Antonia.");
	printf("\n3:Gina Popescu.");
	printf("\n4:Camille Despaces.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':triunghi=triunghi+1;
				b=0;
				break;
			case '2':inima=inima+1;
				b=0;
				break;
			case '3':romb=romb+1;
				b=0;
				break;
			case '4':cerc=cerc+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 7:");
	printf("\n Atunci cind erati mica v-ar fi placut ca tatal dv. sa fie:");
	printf("\n1:Politist.");
	printf("\n2:Invatator.");
	printf("\n3:Cintaret.");
	printf("\n4:Pompier.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':inima=inima+1;
				b=0;
				break;
			case '2':cerc=cerc+1;
				b=0;
				break;
			case '3':romb=romb+1;
				b=0;
				break;
			case '4':triunghi=triunghi+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 8:");
	printf("\nEste ziua dv. de nastere. V-ar face mare placere daca el v-ar oferi:");
	printf("\n1:51 de trandafiri rosii.");
	printf("\n2:O planta carnivora.");
	printf("\n3:O lalea neagra.");
	printf("\n4:Un buchet de flori de cimp culese chiar de el.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':inima=inima+1;
				b=0;
				break;
			case '2':romb=romb+1;
				b=0;
				break;
			case '3':cerc=cerc+1;
				b=0;
				break;
			case '4':
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 9:");
	printf("\nTocmai ati creat un nou parfum pentru barbati. Cum l-ati numi?");
	printf("\n1:Torero.");
	printf("\n2:Eau caline.");
	printf("\n3:Evrika.");
	printf("\n4:Peter Pan.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':inima=inima+1;
				b=0;
				break;
			case '2':triunghi=triunghi+1;
				b=0;
				break;
			case '3':cerc=cerc+1;
				b=0;
				break;
			case '4':romb=romb+1;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 10:");
	printf("\nIn viata de toate zilele, sinteti mai degraba:");
	printf("\n1:Vesela ca un cintezoi.");
	printf("\n2:Curioasa ca o pisica.");
	printf("\n3:Incapatinata ca un catir.");
	printf("\n4:Vorbareata ca o cotofana.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':romb=romb+1;
				b=0;
				break;
			case '2':cerc=cerc+1;
				b=0;
				break;
			case '3':inima=inima+1;
				b=0;
				break;
			case '4':triunghi=triunghi+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 11:");
	printf("\n V-ar fi placut sa fi fost sora mai mica a lui:");
	printf("\n1:Tintin.");
	printf("\n2:Mickey Mouse.");
	printf("\n3:Lucky Luke.");
	printf("\n4:Astrix.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':cerc=cerc+1;
				b=0;
				break;
			case '2':triunghi=triunghi+1;
				b=0;
				break;
			case '3':inima=inima+1;
				b=0;
				break;
			case '4':romb=romb+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 12:");
	printf("\n La circ, aplaudati mai ales:");
	printf("\n1:Clovnii.");
	printf("\n2:Prestidigitatorul.");
	printf("\n3:Imblinzitorul de lei.");
	printf("\n4:Trapezistii.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':romb=romb+1;
				b=0;
				break;
			case '2':cerc=cerc+1;
				b=0;
				break;
			case '3':inima=inima+1;
				b=0;
				break;
			case '4':triunghi=triunghi+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 13:");
	printf("\n Sa presupunem ca sinteti directoarea unei agentii matrimoniale. Cui i-ati");
	printf("\n prezenta-o pe Isabelle Adjani?");
	printf("\n1:Lui Roch Voisine.");
	printf("\n2:Lui thierry Lhermitte.");
	printf("\n3:Lui Woody Allen.");
	printf("\n4:Lui Brice Lalonde.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':inima=inima+1;
				b=0;
				break;
			case '2':triunghi=triunghi+1;
				b=0;
				break;
			case '3':romb=romb+1;
				b=0;
				break;
			case '4':cerc=cerc+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 14:");
	printf("\n Va aflati intr-un restaurant select. Specialitatea casei sint brinzeturile");
	printf("\n topite in vin (fondues). Va hotariti pentru:");
	printf("\n1:Fondue bourguinonne.");
	printf("\n2:Fondue savoyarde.");
	printf("\n3:Fondue macrobiotique.");
	printf("\n4:Fondue au chocolat.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':inima=inima+1;
				b=0;
				break;
			case '2':romb=romb+1;
				b=0;
				break;
			case '3':cerc=cerc+1;
				b=0;
				break;
			case '4':triunghi=triunghi+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	printf("\n INTREBAREA 15:");
	printf("\n Nu v-au placut niciodata acei barbati care:");
	printf("\n1:Spun:Ma duc la coafor.");
	printf("\n2:Poarta cravate roz.");
	printf("\n3:Prefera cinii si nu copii.");
	printf("\n4:nu vor sa ia sa niociodata nicaieri.");
	printf("\n Alegeti 1,2,3,4\n");
	refresh();
	b=0;
	do
	{
		a=getch();
		switch(a)
		{
			case '1':cerc=cerc+1;
				b=0;
				break;
			case '2':inima=inima+1;
				b=0;
				break;
			case '3':triunghi=triunghi+1;
				b=0;
				break;
			case '4':romb=romb+1;
				b=0;
				break;
			default:
				printf("\nOptiune incorecta.\n");
				b=1;
		}
	}while(b==1);
	clear();
	refresh();
	if ((cerc>inima) && (cerc>romb) && (cerc>triunghi))
	{
		printf("\nCopila fiind, va placea, desigur, sa intrebati ""de ce"" ? Mai tirziu,");
		printf("\nv-ati indragostit de invatatorul sau de profesorul dv...Aveti o mare ");
		printf("\nsete de cunoastere si intelectualii va pot potoli aceasta sete. Va atrag");
		printf("\ncu cit sint mai pasionati e carti, de cercetare. nu are nici o importanta");
		printf("\n daca barbatul visurilor dv. are bacalaureatul,daca a absolvit o facultate");
		printf("\nsau si-a luat doctoratul. Alaturi de el, nu va plictisii niciodata !\n");
	}
	if ((inima>cerc) && (inima>romb) && (inima>triunghi))
	{
		printf("\nCopila fiind, ii priveati cu admiratie pe micii duri,pe cei carora nu le");
		printf("\nera frica de nimic.Timpul atrecut,micii duri au crescut,dar va atrag tot ");
		printf("\natit de mult.Ati inteles, de altfel, ca sub carapacea lor se ascunde o inima");
		printf("\ntandra.Sint extraordinar de sensibili,la fel ca dv.!Va revolta uneori");
		printf("\npretinsa lor superioritate masculina.Incercati sa nu-i iubiti,dar...\n");
	}
	if ((romb>inima) && (romb>cerc) && (romb>triunghi))
	{
		printf("\nAtunci cind erati mica,adorati glumele,la care rideati din toata inima");
		printf("\nNu v-ati schimbat aproape deloc. Nimic nu va displace mai mult decit barbatii");
		printf("\ncare se iau in serios. Si pentru nimic in lume nu va puteti lipsi de umor;");
		printf("\neste colacul dv. de salvare. Glumetii va atrag;cu ei, viata nu este niciodata");
		printf("\ntrista. Va fac sa uitati de necazuri si va dau impresia ca sinteti din nou");
		printf("\ncopil. E asa de bine!\n");
	}	
	if((triunghi>cerc) && (triunghi>inima) && (triunghi>romb))
	{
		printf("\nMingiierile sint cele mai frumoase amintiri din copilarie. Pentru dv.,");
		printf("\ntandretea este indispensabila. Va atrag barbatii vara va rasfata. Ca un bun");
		printf("\ntata de familie, va sfatuiesc si va consoleaza. Inconvenientul: sint greu");
		printf("\nde gasit. Se casatoresc relativ repede, au de obicei copii si sint mai degraba");
		printf("\n... fideli\n");
	}
	refresh();
	getch();
}