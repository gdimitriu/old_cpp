/* program care deseneaza virful de lance */
#include<conio.h>
#include<stdio.h>
#include"turtle1.h"
char mesaj[40];
float x0,y0,l;
int t,s;
void lance(float l,int t,int s)
{
 if(t)
 {
  left(60*s);
  lance(l*0.5,t-1,-s);
  right(60*s);
  lance(l*0.5,t-1,s);
  right(60*s);
  lance(l*0.5,t-1,-s);
  left(60*s);
  }
 else forward(l);
}
void main(void)
{
 clrscr();
 printf("PROGRAM PENTRU DESENAREA VIRFULUI DE LANCE \n");
 printf("originea coordonatelor (x0,y0): \n");
 scanf("%f",&x0);
 fflush(stdin);
 scanf("%f",&y0);
 fflush(stdin);
 printf("\n virsta:");
 scanf("%d",&t);
 fflush(stdin);
 printf("\n dimensiune:");
 scanf("%f",&l);
 fflush(stdin);
 turtle_start();
 sprintf(mesaj,"are virsta:%f",t);
 outtextxy(0,10,mesaj);
 sprintf(mesaj,"are dimensiunea:%d",l);
 outtextxy(0,20,mesaj);
 set_reper(x0,y0);
 lance(l,t,1);
 turtle_stop();
}

