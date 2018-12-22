/* program pentru desenarea curbei c */
#include<conio.h>
#include<stdio.h>
#include"turtle.h"
char mesaj[50];
float dim,x0,y0;
int nivel;
void curba(float dim,int nivel)
/* program recursiv */
{
 if(!nivel) forward(dim);
  else
   {
    curba(dim,nivel-1);
    right(90);
    curba(dim,nivel-1);
    left(90);
   }
}
void main(void)
{
 clrscr();
 printf(" PROGRAM PENTRU DESENUL CURBEI C \n");
 printf("originea reperului (x0,y0):\n");
 scanf("%f",&x0);
 scanf("%f",&y0);
 printf(" \n dim :");
 scanf("%f",&dim);
 printf(" \n nivel :");
 scanf("%d",&nivel);
 turtle_start();
 sprintf(mesaj,"dimensiune:%f",dim);
 outtextxy(0,10,mesaj);
 sprintf(mesaj,"nivel:%d",nivel);
 outtextxy(0,20,mesaj);
 set_reper(x0,y0);
 curba(dim,nivel);
 turtle_stop();
}
