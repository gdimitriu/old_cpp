/* genereaza curba lui Hilbert */
#include<conio.h>
#include<stdio.h>
#include"turtle1.h"
char mesaj[50];
float dim,x0,y0;
int v,nivel;
void hilb(float dim,int nivel,int v)
{
 if(nivel)
 {
  left(v*90);
  hilb(dim,nivel-1,-v);
  forward(dim);
  right(v*90);
  hilb(dim,nivel-1,v);
  forward(dim);
  hilb(dim,nivel-1,v);
  right(v*90);
  forward(dim);
  hilb(dim,nivel-1,-v);
  left(v*90);
 }
}
void main(void)
{
 clrscr();
 printf("PROGRAM CARE DESENEAZA CURBA LUI HILBERT \n");
 printf("originea reperului (x0,y0) :\n");
 scanf("%f",&x0);
 fflush(stdin);
 scanf("%f",&y0);
 fflush(stdin);
 printf("\n dim :");
 scanf("%f",&dim);
 fflush(stdin);
 printf("\n nivel :");
 scanf("%d",&nivel);
 fflush(stdin);
 turtle_start();
 sprintf(mesaj," dimensiune:%f",dim);
 outtextxy(0,10,mesaj);
 sprintf(mesaj," nivel:%d",nivel);
 outtextxy(0,20,mesaj);
 set_reper(x0,y0);
 hilb(dim,nivel,1);
 turtle_stop();
}
