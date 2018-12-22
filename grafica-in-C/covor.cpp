/* covorul lui Sierpinski */
#include<conio.h>
#include<stdio.h>
#include"turtle1.h"
float x0,y0,l;
char mesaj[50];
int niv;
void patrat(float x,float y,float l)
{
 pen_up();
 set_reper(x,y);
 pen_down();
 forward(l);
 right(90);
 forward(l);
 right(90);
 forward(l);
 right(90);
 forward(l);
 right(90);
}
void covor(float x,float y,float l,int niv)
{
int i;
if(!niv) patrat(x+l/3,y+l/3,l/3);
 else
	{
	 patrat(x+l/3,y+l/3,l/3);
	 for(i=0;i<3;i++)
	  covor(x,y+i*l/3,l/3,niv-1);
	 covor(x+l/3,y+2*l/3,l/3,niv-1);
	 for(i=0;i<3;i++)
	  covor(x+2*l/3,y+(2-i)*l/3,l/3,niv-1);
	 covor(x+l/3,y,l/3,niv-1);
	}
}
void main(void)
{
 clrscr();
 printf("\n COVORUL LUI SIERPINSKI \n");
 printf("originea reperului (x0,y0) :\n");
 scanf("%f",&x0);
 scanf("%f",&y0);
 printf("\n lungime latura:");
 scanf("%f",&l);
 printf("\n nivel:");
 scanf("%d",&niv);
 turtle_start();
 sprintf(mesaj,"lungime:%f",l);
 outtextxy(0,10,mesaj);
 sprintf(mesaj,"nivel:%d",niv);
 outtextxy(0,20,mesaj);
 set_reper(x0,y0);
 patrat(x0,y0,l);
 covor(x0,y0,l,niv);
 turtle_stop();
}
