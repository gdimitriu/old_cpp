/* program care deseneaza graficul 3 */
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include"mat.h"
int gdriver=DETECT,gmode,errorcode;
int i,t1,t2,scalx,scaly;
float a,b,val1;
float func(float x)
/* functia absorbtie-eliminare */
{
 float nou;
 nou=5.0*exp(-0.3*x)+15.0*exp(-0.1*x)-20.0*exp(-0.2*x);
 return(nou);
}
void axe(int t1,int t2)
{
 moveto(0,-10);lineto(0,t2);
 moveto(-5,t2-5);lineto(0,t2);
 lineto(+5,t2-5);moveto(-10,0);
 lineto(t1,0);lineto(t1-5,5);
 moveto(t1-5,-5);lineto(t1,0);
}
void main(void)
{
 clrscr();
 printf("PROGRAM PENTRU TRASAREA RAFICULUI FUNCTIEI 3\n");
 printf("pentru continuare apasati orice tasta");
 getch();
 initgraph(&gdriver,&gmode,"");
 setviewport(50,100,500,300,0);
 setbkcolor(1);setcolor(14);
 a=0.0;b=40.0;
 scalx=10;scaly=45;
 t1=round(a)*scalx;t2=round(b)*scalx;
 moveto(t1,round(func(a)*scaly));
 for(i=t1+1;i<=t2;i++)
 {
  val1=i/10.0;
  lineto(round(val1*scalx),round(func(val1)*scaly));
 }
 axe(t2+20,150);
 getch();
 closegraph();
}
