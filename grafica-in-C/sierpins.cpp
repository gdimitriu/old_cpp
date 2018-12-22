/* program care deseneaza curba lui Sierpinski */
#include<conio.h>
#include<stdio.h>
#include"turtle.h"
char mesaj[50];
float dim,d,x0,y0;
int i,nivel;
void spk(float dim,int nivel)
{
 if(nivel)
 {
   d=dim/sqrt(2);
   spk(dim,nivel-1);
   right(45);
   forward(d);
   right(45);
   spk(dim,nivel-1);
   left(90);
   forward(dim);
   left(90);
   spk(dim,nivel-1);
   right(45);
   forward(d);
   right(45);
   spk(dim,nivel-1);
  }
}
void main(void)
{
 clrscr();
 printf(" PROGRAM CARE DESENEAZA CURBA LUI SIERPINSKI \n");
 printf(" Originea reperului (x0,y0): ");
 scanf("%f",&x0);
 scanf("%f",&y0);
 printf("\n dim :");
 scanf("%f",&dim);
 printf("\n nivel :");
 scanf("%d",&nivel);
 turtle_start();
 sprintf(mesaj," Dimensiune:%f",dim);
 outtextxy(0,10,mesaj);
 sprintf(mesaj," Nivele:%d",nivel);
 outtextxy(0,20,mesaj);
 set_reper(x0,y0);
 d=dim/sqrt(2);
 for(i=1;i<5;i++)
 {
  spk(dim,nivel);
  right(45);
  forward(d);
  right(45);
 }
 turtle_stop();
}
