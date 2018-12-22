/* programul ex06 din grafica pe calculator in C si Pascal */
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int i,j,k,t1,t2;
float s,x,y,xc,yc,r;
int gdriver=DETECT,gmode,errorc;
void imagini(void)
{
 r=s/200;
 for(i=1;i<=t1;i++)
 {
  x=xc+i*r;
  for(j=1;j<=t2;j++)
  {
   y=yc+j*r;
   k=floor(x*y+x*y*y);
   if((k%2)==0.0) putpixel(i,j,1);
  }
 }
}
void main(void)
{
 clrscr();
 printf("\n Introduceti datele xc,yc,s:\n");
 scanf("%f%f%f",&xc,&yc,&s);
 fflush(stdin);
 printf("\n Introduceti marimea ecranului \n");
 scanf("%d%d",&t1,&t2);
 fflush(stdin);
 initgraph(&gdriver,&gmode,"");
 imagini();
 getch();
 closegraph();
}
