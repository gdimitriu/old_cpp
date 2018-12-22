/* program pentru trassarea fgraficului unei functii */
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define true 1
#define false 0
int scalx,scaly,t1,t2;
float a,b,val1;
int graphdriver=DETECT,gmode,errorcode;
int i;
float f(float x)
{
 float f;
 f=abs(sin(x)*exp(-sin(x)));
 return(f);
}
void axe(int t1,int t2)
/* trasare axe de coordonate */
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
 printf("PROGRAM PENTRU TRASAREA UNUI GRAFIC \n");
 printf("pentru a incepe apasati orice tasta");
 getch();
 initgraph(&graphdriver,&gmode,"");
 setviewport(20,150,500,300,false);
 setbkcolor(1);setcolor(14);
 a=0.0;
 b=8.0*M_PI;
 /* se traseaza graficul */
 scalx=20;scaly=20;	// sacalare pe x,y
 t1=floor(a)*scalx;
 t2=floor(b)*scalx;
 moveto(floor(a)*scalx,floor(f(a)*scaly));
 for(i=t1+1;i<=t2;i++)
 {
  val1=i/20.0;
  lineto(floor(val1*scalx),floor(f(val1)*scaly));
 }
 /* se traseaza axele de coordonate */
 axe(t2+20,100);
 getch();
 closegraph();
}
