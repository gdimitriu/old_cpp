/* 	Genereaza siruri de triunghiuri echilaterale.
	Se vor citi de la tastatura:
	r=raza cercului circumscris;
	p=pasul unghiului de rotatie;
	n=numarul de rotatii.*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include"mat.h"
int gdriver=DETECT,gmode,errorcode,n,i;
float r,p,x0,y0,x1,y1,x2,y2,x3,y3,f,fi,x1r,y1r,x2r,y2r,x3r,y3r;
char text[20];
void main(void)
{
 clrscr();
 printf("\n ROTATIA UNUI TRIUNGHI ECHILATERAL\n");
 printf("Raza cercului circumscris r=");
 scanf("%f",&r);fflush(stdin);
 printf("\n Pasul unghiului de rotatie p=");
 scanf("%f",&p);fflush(stdin);
 printf("\n Numarul de rotatii n=");
 scanf("%d",&n);fflush(stdin);
 initgraph(&gdriver,&gmode,"");
 setbkcolor(1);//albastru
 setcolor(4);  //rosu
 /* Coordonatele cercului fata de originea (0,0) */
 x0=300;y0=150;
 f=M_PI/180.0; //factor de transformare in radiani
 /* coordonatele virfului triunghiului echilateral */
 x1=x0+r;y1=y0;
 x2=x0-r/2.0;y2=y0+sqrt(3.0)*r/2.0;
 x3=x2;y3=y0-sqrt(3.0)*r/2.0;
 // generarea sirului de triunghiuri echilaterale
 for(i=0;i<=(n-1);i++)
 {
  fi=f*p*i;
  // Coordonatele virfului triunghiului echilateral
  x1r=x0+(x1-x0)*cos(fi)-(y1-y0)*sin(fi);
  y1r=y0+(x1-x0)*sin(fi)+(y1-y0)*cos(fi);
  x2r=x0+(x2-x0)*cos(fi)-(y2-y0)*sin(fi);
  y2r=y0+(x2-x0)*sin(fi)+(y2-y0)*cos(fi);
  x3r=x0+(x3-x0)*cos(fi)-(y3-y0)*sin(fi);
  y3r=y0+(x3-x0)*sin(fi)+(y3-y0)*cos(fi);
  //desenarea laturilor triunghiului curent
  moveto(round(x1r),round(y1r));
  lineto(round(x2r),round(y2r));
  lineto(round(x3r),round(y3r));
  lineto(round(x1r),round(y1r));
 }
 sprintf(text,"r=%f,p%f,n=%d",r,p,n);
 outtextxy(100,470,text);
 getch();
 closegraph();
}
