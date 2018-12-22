/* Vom genera un sir de cercuri de raza r si avind centrele
 pe cercul de raza r si de centru (x0,y0).
 Date de introduss:
	-(x0,y0)=coordonatele centrului;
	-r=raza cercului initial;
	-p=pasul unghiului de rotatie;
	-n=numarul de rotatii. */
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include"mat.h"
int gdriver=DETECT,gmode,errorcode,n,i;
float x0,y0,xr,yr,r,p,fi,f;
char text[30];
void main(void)
{
 clrscr();
 printf("Rotatia unui cerc:\n");
 printf("Coordonatele centrului x0,y0:\n");
 scanf("%f%f",&x0,&y0);fflush(stdin);
 printf("\n Raza cercului initial r=");
 scanf("%f",&r);fflush(stdin);
 printf("\n Pasul unghiului de rotatie p=");
 scanf("%f",&p);fflush(stdin);
 printf("\n Numarul de rotatii n=");
 scanf("%d",&n);fflush(stdin);
 initgraph(&gdriver,&gmode,"");
 setbkcolor(1);
 setcolor(4);
 f=M_PI/180.0;
 moveto(round(x0),round(y0));
 //Generarea sirului de cercuri
 for(i=0;i<=(n-1);i++)
 {
  fi=f*p*i;
  xr=x0+r*cos(fi);
  yr=y0+r*sin(fi);
  circle(round(xr),round(yr),round(r));//desenare cerc curent
 }
 sprintf(text,"Avem introduse:r=%f,p=%f,n=%d",r,p,n);
 outtextxy(150,400,text);
 getch();
 closegraph();
}
