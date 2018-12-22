/* program pentru desenul curbei dragonului */
#include<conio.h>
#include<stdio.h>
#include"turtle1.h"
char mesaj[40];
float dim,x0,y0;
int nivel,v;
void dragon(float dim,int nivel,int v)
{
 if(!nivel) forward(dim);
 else
 {
  right(45*v);
  dragon(dim,nivel-1,1);
  left(90*v);
  dragon(dim,nivel-1,-1);
  right(45*v);
 }
}
void main(void)
{
 clrscr();
 printf(" CURBA DRAGONULUI \n");
 printf(" originea reperului (x0,y0):\n");
 scanf("%f",&x0);
 fflush(stdin);
 scanf("%f",&y0);
 fflush(stdin);
 printf("\n dim:");
 scanf("%f",&dim);
 fflush(stdin);
 printf("\n nivel:");
 scanf("%d",&nivel);
 turtle_start();
 sprintf(mesaj,"dimensiune:%f",dim);
 outtextxy(0,10,mesaj);
 sprintf(mesaj,"nivele:%d",nivel);
 outtextxy(0,20,mesaj);
 set_reper(x0,y0);
 dragon(dim/sqrt(2),nivel,1);
 turtle_stop();
}
