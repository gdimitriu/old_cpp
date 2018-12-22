/* CURBE GENERATE SUB FORMA UNEI FLORI
   Se introduc:
	-z=unghiul pentru grupul claselor de resturi;
	-n=numarul de petale;
	-d=unghiul-perioada. */
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include"mat.h"
int gdriver=DETECT,gmode,errorcode,t,teta,fi,c,z,n,d;
float x,a,ax,ay,s;
void main(void)
{
 clrscr();
 printf("Program < A rose is a rose ...> \n");
 printf("Dati unghiul z=1,2,...,360 ? z=");
 scanf("%d",&z);fflush(stdin);
 printf("\n Dati numarul de patale n=");
 scanf("%d",&n);fflush(stdin);
 printf("\n Dati unghiul-perioada d=");
 scanf("%d",&d);fflush(stdin);
 t=0;c=0;
 initgraph(&gdriver,&gmode,"");
 setviewport(300,150,500,200,0);
 setcolor(4);setbkcolor(1);
 do
 {
  teta=t;
  a=t*M_PI/180.0;
  ax=cos(a)*sin(n*a)*150;
  ay=sin(a)*sin(n*a)*150;
  moveto(round(ax),round(ay));
  do
  {
   teta=teta+d;
   teta=teta-round(teta/z)*z;
   fi=n*teta;
   fi=fi-round(fi/z)*z;
   x=2.0*M_PI*fi/z;
   s=2.0*M_PI*teta/z;
   // transformare in coordonate carteziene
   ax=sin(x)*cos(s)*150;
   ay=sin(x)*sin(s)*150;
   lineto(round(ax),round(ay));
   c=c+1;
  }while(teta!=t);
  t=t+1;
 }while(c<z);
 getch();
 closegraph();
}
