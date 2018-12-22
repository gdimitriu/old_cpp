/* program care deseneaza arborele lui PERRON */
#include<conio.h>
#include<stdio.h>
#include"turtle.h"
float dim,fdiv,x0,y0;
char mesaj[50];
int niv,u;
/* dim=lungime initiala a ramurei
   fdiv=factor diviziune pentru ramura
   niv=nivelul de recursie
   u=unghiul ramificatiei
   x0,y0=coordonate pentru origine  */
void perron(float dim,float fdiv,int niv,int u)
{
 if (niv)
	{
	 left(u);
	 forward(dim);
	 perron(dim*fdiv,fdiv,niv-1,u);
	 back(dim);
	 right(2*u);
	 forward(dim);
	 right(u);
	 forward(dim);
	 perron(dim*fdiv,fdiv,niv-1,u);
	 back(dim);
	 left(2*u);
	 forward(dim);
	 left(u);
	 forward(dim);
	 perron(dim*fdiv,fdiv,niv-1,u);
	 back(dim);
	 right(2*u);
	 forward(dim);
	 perron(dim*fdiv,fdiv,niv-1,u);
	 back(dim);
	 left(u);
	 back(dim);
	 right(u);
	 back(dim);
	 left(u);
	}
}
void main(void)
{
 clrscr();
 printf("  ARBORELE LUI PERRON ");
 printf("\n originea reperului (x0,y0) :\n");
 scanf("%f",&x0);
 scanf("%f",&y0);
 printf("\n dim :");
 scanf("%f",&dim);
 printf("\n fdiv :");
 scanf("%f",&fdiv);
 printf("\n u :");
 scanf("%d",&u);
 printf("\n niv :");
 scanf("%d",&niv);
 turtle_start();
 /* afisare date introduse in mod grafic */
 sprintf(mesaj," lungime :%f",dim);
 outtextxy(0,10,mesaj);
 sprintf(mesaj," factor diviziune:%f",fdiv);
 outtextxy(0,20,mesaj);
 sprintf(mesaj," unghiul dintre ramuri:%d",u);
 outtextxy(0,30,mesaj);
 sprintf(mesaj," nivel de recursie:%d",niv);
 outtextxy(0,40,mesaj);
 set_reper(x0,y0);
 forward(dim);
 perron(dim,fdiv,niv,u);
 turtle_stop();
}
