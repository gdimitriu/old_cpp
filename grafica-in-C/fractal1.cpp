/* Exemplu din Grafica Interactiva pe Calculatoare Personale */
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
double a[]={0.1,0.2,-.15,0.85};
double b[]={0,-.25,.3,.05};
double c[]={0,.20,.25,-.05};
double d[]={0.15,.20,.25,.85};
double e[]={0,0,0,0};
double f[]={0,1.5,.45,1.5};
double p[]={320,2600,4900,32767};
int xscale=25,yscale=25,xoffset=0,yoffset=-160;
void desen(int);
void main(void)
{
 int d=0,m=0;
 initgraph(&d,&m,"d:\BC5\BGI");
 printf("test");fflush(stdout);
 desen(4);getchar();
 closegraph();
}
void desen(int color)
{
 int px,py,i,j,k;
 double y=0,x=0,newx;
 srand(5);
 for(i=1;i<=10000;i++)
 {
  j=rand();
  k=(j<p[0])?0:((j<p[1])?1:((j<p[2])?2:3));
  color=k+1;
  newx=a[k]*x+b[k]*y+e[k];
  y=c[k]*x+d[k]*y+f[k];
  x=newx;
  px=x*xscale+xoffset;
  py=y*yscale+yoffset;
  if((px>=-320)&&(px<320)&&(py>=-240)&&(py<240))
    putpixel(px+320,py+240,color);
  }
}