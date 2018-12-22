/* program pentru trasarea graficului 2 */
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include"mat.h"
int gdriver=DETECT,gmode,errorcode;
int i,t1,t2,scalx,scaly;
float a,b,val1,nou;
float f(float x)
{
 if(!x) nou=1.0;
 else
   nou=abs(round(x)-x)/x;
 return (nou);
}
void axe(int t1,int t2)
/* trasaarea axelor de coordonate */
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
 printf("PROGRAM PENTRU TRASAREA GRAFICULUI2\n");
 printf("pentru continuare apasati orice tasta");
 getch();
 initgraph(&gdriver,&gmode,"");
 setviewport(20,150,500,300,0);
 setbkcolor(1);setcolor(14);
 a=0.0;b=15.0;
 /* se traseaza graficul */
 scalx=30;scaly=140;
 t1=round(a)*scalx;t2=round(b)*scalx;
 moveto(t1,round(f(a)*scaly));
 for(i=t1+1;i<=t2;i++)
 {
  val1=i/30.0;
  lineto(round(val1*scalx),round(f(val1)*scaly));
 }
 axe(t2+20,150);
 getch();
 closegraph();
}
