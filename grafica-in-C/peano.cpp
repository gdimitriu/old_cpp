/* genereaza curba lui peano */
#include<conio.h>
#include<stdio.h>
#include"turtle1.h"
char mesaj[50];
float dim,x0,y0;
int nivel;
void peano(float dim,int nivel)
{
 if(nivel==0) forward(dim);
 else
  {
   peano(dim/3,nivel-1);
   left(90);
   peano(dim/3,nivel-1);
   right(90);
   peano(dim/3,nivel-1);
   right(90);
   peano(dim/3,nivel-1);
   right(90);
   peano(dim/3,nivel-1);
   left(90);
   peano(dim/3,nivel-1);
   left(90);
   peano(dim/3,nivel-1);
   left(90);
   peano(dim/3,nivel-1);
   right(90);
   peano(dim/3,nivel-1);
  }
}
void main(void)
{
 clrscr();
 printf("PROGRAM CARE DESENEAZA CURBA LUI PEANO \n");
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
 fflush(stdin);
 turtle_start();
 sprintf(mesaj,"dimensiune:%f",dim);
 outtextxy(0,10,mesaj);
 sprintf(mesaj,"nivele:%d",nivel);
 outtextxy(0,20,mesaj);
 set_reper(x0,y0);
 peano(dim,nivel);
 turtle_stop();
}
