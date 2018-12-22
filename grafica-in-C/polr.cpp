/* Elemente de intrare:
	-r=raza cercului circumscris poligonului initial;
	-n=numararul de laturi ale unui poligon;
	-p=pasul de constructie;
	-lmin=lungimea laturii poligonului final. */
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include"mat.h"
int gdriver=DETECT,gmode,errorcode,n,i;
float p,r,f,fi,lmin;
float x[100],y[100],x1[100],y1[100];
void lat(float p,float xa,float ya,float xb,float yb,int j)
{
 float eps,fi,rap;
 eps=1.0E-4;
 if((abs(xa-xb)<=eps)&&(yb<ya)) fi=3.0*M_PI/2.0;
 if((abs(xa-xb)<=eps)&&(yb>ya)) fi=M_PI/2.0;
 if((abs(xa-xb)>eps)&&(yb>=ya))
 {
  rap=(yb-ya)/(xb-xa);
  fi=atan(rap);
  if((abs(fi)<=eps)&&(xb>xa)) fi=0.0;
  if(fi<0.0) fi=fi+M_PI;
 }
 if((abs(xa-xb)>eps)&&(yb<ya))
 {
  rap=(yb-ya)/(xb-xa);
  fi=atan(rap);
  if(fi>0.0) fi=fi+M_PI;
  else fi=fi+2*M_PI;
 }
 x1[j]=xa+p*cos(fi);
 y1[j]=ya+p*sin(fi);
}
void fig(float p,float lmin)
{
 float dist;
 do
 {
  lat(p,x[1],y[1],x[2],y[2],1);
  moveto(round(x1[1]),round(y1[1]));
  for(i=2;i<=n;i++)
  {
   lat(p,x[i],y[i],x[i+1],y[i+1],i);
   lineto(round(x1[i]),round(y1[i]));
  }
  lineto(round(x1[1]),round(y1[1]));
  x1[n+1]=x1[1];y1[n+1]=y1[1];
  /* initializarea coordonatelor */
  for(i=1;i<=n+1;i++)
  {
   x[i]=x1[i];y[i]=y1[i];
  }
  dist=(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]);
  dist=sqrt(dist);
 }while(abs(dist)>lmin);
}
void main(void)
{
 clrscr();
 printf("INFASURATOAREA poligon \n");
 printf("Raza cercului circumscris poligonului r=");
 scanf("%f",&r);fflush(stdin);
 printf("\n Numarul de laturi ale poligonului n=");
 scanf("%d",&n);fflush(stdin);
 printf("\n Pasul de constructie p=");
 scanf("%f",&p);fflush(stdin);
 printf("\n Lungimea laturii poligonului final lmin=");
 scanf("%f",&lmin);fflush(stdin);
 f=M_PI/180.0;
 f=f*360.0/n;
 initgraph(&gdriver,&gmode,"");
 setviewport(320,170,500,200,0);
 setbkcolor(1);setcolor(4);
 x[1]=r;y[1]=0.0; //initializare
 moveto(round(r),round(0.0));
 fi=0.0;
 // trasarea poligonului regulat initial
 for(i=1;i<=n;i++)
 {
  fi=fi+f;
  x[i+1]=r*cos(fi);y[i+1]=r*sin(fi);
  lineto(round(x[i+1]),round(y[i+1]));
 }
 fig(p,lmin);
 getch();
 closegraph();
}
