/* Programul genereaza triunghiuri si citeste datele de la tastatura:
	-r=raza cercului circumscris polinomului;
	-n=numarul de laturi ale poligonului regulat;
	-p=pasul de constructie a unui sir de triunghiuri;
	-lmin=lungimea laturii triunghiului final. */
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include"mat.h"
int gdriver=DETECT,gmode,errorcode,n,i,j;
float p,r,f,xa,ya,xb,yb,xc,yc,lmin,x[3],y[3];
void lat(float p,float xa,float ya,float xb,float yb,int j)
/* calculeaza coordonatele unui virf pentru triunghiul curent */
{
 float eps,fi,rap;
 eps=1.0E-4;
 if((fabs(xa-xb)<=eps)&&(yb<ya)) fi=3.0*M_PI/2.0;
 if((fabs(xa-xb)<=eps)&&(yb>ya)) fi=M_PI/2.0;
 if((fabs(xa-xb)>eps)&&(yb>=ya))
 {
  rap=(yb-ya)/(xb-xa);
  fi=atan(rap);
  if((fabs(fi)<=eps)&&(xb>xa)) fi=0.0;
  if (fi<0.0) fi=fi+M_PI;
 }
 if((fabs(xa-xb)>eps)&&(yb<ya))
 {
  rap=(yb-ya)/(xb-xa);
  fi=atan(rap);
  if(fi>0.0) fi=fi+M_PI;
  else fi=fi+2*M_PI;
 }
 x[j]=xa+p*cos(fi);
 y[j]=ya+p*sin(fi);
}
void fig(float p,float xa,float ya,float xb,float yb,float xc,float yc,float lmin)
/* genereaza si traseaza un sir de triunghiuri */
{
 float dist;
 do
 {
  lat(p,xa,ya,xb,yb,1);
  moveto(round(x[1]),round(y[1]));
  lat(p,xb,yb,xc,yc,2);
  lineto(round(x[2]),round(y[2]));
  lat(p,xc,yc,xa,ya,3);
  lineto(round(x[3]),round(y[3]));
  lineto(round(x[1]),round(y[1]));
  /* initializare pentru reluarea procesului */
  xa=x[1];ya=y[1];xb=x[2];yb=y[2];xc=x[3];yc=y[3];
  dist=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
  dist=sqrt(dist);
 }while(abs(dist)>lmin);
}
void main(void)
{
 clrscr();
 printf("Emblema poligon \n");
 printf("Raza cercului circumscris poligonului r=");
 scanf("%f",&r);fflush(stdin);
 printf("\n Numarul de laturi ale poligonului n=");
 scanf("%d",&n);fflush(stdin);
 printf("\n Pasul de constructie p=");
 scanf("%f",&p);fflush(stdin);
 printf("\n Lungimea laturii triunghiului final lmin=");
 scanf("%f",&lmin);fflush(stdin);
 f=M_PI/180.0;f=f*360.0/n;
 initgraph(&gdriver,&gmode,"");
 setviewport(320,170,500,200,0);
 setbkcolor(1);setcolor(4);
 /* constructia celor n siruri de triunghiuri */
 for(i=1;i<=n;i++)
 {
  /* coordonatele triunhiului initial */
  xa=0.0;ya=0.0;
  xb=r*cos((i-1)*f);yb=r*sin((i-1)*f);
  xc=r*cos(i*f);yc=r*sin(i*f);
  moveto(round(xa),round(ya));
  lineto(round(xb),round(yb));
  lineto(round(xc),round(yc));
  lineto(round(xa),round(ya));
  /* Generarea sirului de triunghiuri */
  fig(p,xa,ya,xb,yb,xc,yc,lmin);
 }
 getch();
 closegraph();
}
