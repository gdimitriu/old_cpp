#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include"mat.h"
int gdriver=DETECT,gmode,errorcode;
int graphx[639],graphy[639];
float a,b,arg,val1,val2;
int i,t1,t2,flag,h;
void init(void)
{
 /* introducere drriver grafic in executabil */
 errorcode=registerfarbgidriver(EGAVGA_driver_far);
 initgraph(&gdriver,&gmode,"");
 setviewport(320,175,500,200,0);
 setbkcolor(1);setcolor(14);
 rectangle(-150,-150,150,150);
 setviewport(170,25,470,325,1);
}
void stop(void)
{
 getch();
 closegraph();
}
void axe()
{
 moveto(120,150);lineto(180,150);
 moveto(150,120);lineto(150,180);
}
void graph1(int t1,int t2)
{
 moveto(graphx[t1+319],graphy[t1+319]);	//fara trasare
 for(i=t1+1;i<=t2;i++) lineto(graphx[i+319],graphy[i+319]);
}
void main(void)
{
 h=1;
 do
 {
  t1=0;val1=0.0;t2=0;val2=0.0;a=0.0;b=0.0;
  clrscr();
  printf("		CURBE PLANE REMARCABILE \n");
  printf("\n");
  printf("1=lemniscata BERNOULLI           2=concoida NICOMEDE \n");
  printf("3=melcul lui PASCAL              4=cisoida lui DIONCLES \n");
  printf("5=trisectoarea lui MAC-LAURIN    6=strofoida \n");
  printf("7=spirala logaritmica            8=spirala hiperbolica \n");
  printf("9=spirala lui ARHIMEDE           0=iesire \n");
  printf("\n");
  printf("Centrul ecranului este originea ssistemului cartezian\n");
  printf("Precizati numarul de ordie pentru curba dorita:");
  scanf("%d",&flag);
  fflush(stdin);
  switch(flag)
  {
   case 0:
	h=0;
   break;
   case 1:
	clrscr();
	printf(" LEMNISCATA BERNOULLI\n");
	printf(" Dati parametrul a:");
	scanf("%f",&a);
	fflush(stdin);
	t1=round((-M_PI/4.0)*50);t2=round((M_PI/4.0)*50);
	for(i=t1;i<=t2;i++)
	{
	 arg=i/50.0;
	 val1=cos(arg)*a*sqrt(2.0*cos(2.0*arg));
	 val2=sin(arg)*a*sqrt(2.0*cos(2.0*arg));
	 graphx[i+319]=round(val1*50)+150;
	 graphy[i+319]=round(val2*50)+150;
	}
	init();
	axe();
	graph1(t1,t2);
	t1=round((3.0*M_PI/4.0)*50);t2=round((5.0*M_PI/4.0)*50);
	for(i=t1;i<=t2;i++)
	{
	 arg=i/50.0;
	 val1=cos(arg)*a*sqrt(2.0*cos(2.0*arg));
	 val2=sin(arg)*a*sqrt(2.0*cos(2.0*arg));
	 graphx[i+319]=round(val1*50)+150;
	 graphy[i+319]=round(val2*50)+150;
	}
	graph1(t1,t2);
	stop();
   break;
   case 2:
	clrscr();
	printf("		CONCOIDA LUI NICOMEDE\n");
	printf(" Dati parametrii a,b:\n");
	scanf("%f",&a);
	fflush(stdin);
	scanf("%f",&b);
	fflush(stdin);
	t1=round((-M_PI/2.0)*65);t2=-t1;
	for(i=t1;i<=t2;i++)
	{
	 arg=i/65.00;
	 val1=cos(arg)*(a/cos(arg)+b);
	 val2=sin(arg)*(a/cos(arg)+b);
	 graphx[i+319]=round(val1*65)+150;
	 graphy[i+319]=round(val2*65)+150;
	}
	init();
	axe();
	graph1(t1,t2);
	for(i=t1;i<=t2;i++)
	{
	 arg=i/65.00;
	 val1=cos(arg)*(a/cos(arg)-b);
	 val2=sin(arg)*(a/cos(arg)-b);
	 graphx[i+319]=round(val1*65)+150;
	 graphy[i+319]=round(val2*65)+150;
	}
	graph1(t1,t2);
	stop();
   break;
   case 3:
	clrscr();
	printf("		MELCUL LUI PASCAL\n");
	printf(" Dati parametrii a,b:\n");
	scanf("%f",&a);
	fflush(stdin);
	scanf("%f",&b);
	fflush(stdin);
	t1=round((-M_PI/2.0)*65);t2=-t1;
	for(i=t1;i<=t2;i++)
	{
	 arg=i/65.00;
	 val1=cos(arg)*(2*a*cos(arg)+2*b);
	 val2=sin(arg)*(2*a*cos(arg)+2*b);
	 graphx[i+319]=round(val1*65)+150;
	 graphy[i+319]=round(val2*65)+150;
	}
	init();
	axe();
	graph1(t1,t2);
	for(i=t1;i<=t2;i++)
	{
	 arg=i/65.00;
	 val1=cos(arg)*(2*a*cos(arg)-2*b);
	 val2=sin(arg)*(2*a*cos(arg)-2*b);
	 graphx[i+319]=round(val1*65)+150;
	 graphy[i+319]=round(val2*65)+150;
	}
	graph1(t1,t2);
	stop();
   break;
   case 4:
	clrscr();
	printf("		CISOIDA LUI DIONCLES\n");
	printf(" Dati parametrul a:");
	scanf("%f",&a);
	fflush(stdin);
	t1=round((-M_PI/2)*65);t2=-t1;
	for(i=t1;i<=t2;i++)
	{
	 arg=i/65.00;
	 val1=cos(arg)*(2*a*sin(arg)*sin(arg)/cos(arg));
	 val2=sin(arg)*(2*a*sin(arg)*sin(arg)/cos(arg));
	 graphx[i+319]=round(val1*65)+150;
	 graphy[i+319]=round(val2*65)+150;
	}
	init();
	axe();
	graph1(t1,t2);
	stop();
   break;
   case 5:
	clrscr();
	printf("		TRISECTOAREA MACLAURIN\n");
	printf(" Dati parametrul a:");
	scanf("%f",&a);
	fflush(stdin);
	t1=round((-M_PI/2)*65);t2=-t1;
	for(i=t1;i<=t2;i++)
	{
	 arg=i/65.00;
	 val1=cos(arg)*(a*(4*cos(arg)-1/cos(arg)));
	 val2=sin(arg)*(a*(4*cos(arg)-1/cos(arg)));
	 graphx[i+319]=round(val1*65)+150;
	 graphy[i+319]=round(val2*65)+150;
	}
	init();
	axe();
	graph1(t1,t2);
	stop();
   break;
   case 6:
	clrscr();
	printf("		STROFOIDA\n");
	printf(" Dati parametrul a:");
	scanf("%f",&a);
	fflush(stdin);
	t1=round((-M_PI/2)*65);t2=-t1;
	for(i=t1;i<=t2;i++)
	{
	 arg=i/65.00;
	 val1=cos(arg)*(a/cos(arg)+a*sin(arg)/cos(arg));
	 val2=sin(arg)*(a/cos(arg)+a*sin(arg)/cos(arg));
	 graphx[i+319]=round(val1*65)+150;
	 graphy[i+319]=round(val2*65)+150;
	}
	init();
	axe();
	graph1(t1,t2);
	for(i=t1;i<=t2;i++)
	{
	 arg=i/65.00;
	 val1=cos(arg)*(a/cos(arg)-a*sin(arg)/cos(arg));
	 val2=sin(arg)*(a/cos(arg)-a*sin(arg)/cos(arg));
	 graphx[i+319]=round(val1*65)+150;
	 graphy[i+319]=round(val2*65)+150;
	}
	graph1(t1,t2);
	stop();
   break;
   case 7:
	clrscr();
	printf("		SPIRALA LOGARITMICA\n");
	printf(" Dati parametrul a:");
	scanf("%f",&a);
	fflush(stdin);
	t1=1;t2=15*10;
	for(i=t1;i<=t2;i++)
	{
	 arg=i/10.00;
	 val1=cos(arg)*a*exp(1.00+arg);
	 val2=sin(arg)*a*exp(1.00+arg);
	 graphx[i+319]=round(val1*10)+150;
	 graphy[i+319]=round(val2*10)+150;
	}
	init();
	axe();
	graph1(t1,t2);
	stop();
   break;
   case 8:
	clrscr();
	printf("		SPIRALA HIPERBOLICA\n");
	printf(" Dati parametrul a:");
	scanf("%f",&a);
	fflush(stdin);
	t1=1;t2=15*10;
	for(i=t1;i<=t2;i++)
	{
	 arg=i/10.00;
	 val1=cos(arg)*a/arg;
	 val2=sin(arg)*a/arg;
	 graphx[i+319]=round(val1*10)+150;
	 graphy[i+319]=round(val2*10)+150;
	}
	init();
	axe();
	graph1(t1,t2);
	stop();
   break;
   case 9:
	clrscr();
	printf("		SPIRALA LUI ARHIMEDE\n");
	printf(" Dati parametrul a:");
	scanf("%f",&a);
	fflush(stdin);
	t1=1;t2=25*10;
	for(i=t1;i<=t2;i++)
	{
	 arg=i/10.00;
	 val1=cos(arg)*a*arg;
	 val2=sin(arg)*a*arg;
	 graphx[i+319]=round(val1*10)+150;
	 graphy[i+319]=round(val2*10)+150;
	}
	init();
	axe();
	graph1(t1,t2);
	stop();
   break;
  }
 } while(h!=0);
}