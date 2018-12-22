/* program pentru desenarea curbelor KOCH */
#include<conio.h>
#include<stdio.h>
#include"turtle.h"
char mesaj[50];
int i,nivel;
float x0,y0,lat;
void koch(float lat,int nivel)
/* deseneaza recursiv o latura */
{
 if(nivel==0) forward(lat);
   else
    {
	koch(lat/3,nivel-1);
	left(60);
	koch(lat/3,nivel-1);
	right(120);
	koch(lat/3,nivel-1);
	left(60);
	koch(lat/3,nivel-1);
    }
}
void main(void)
{
 clrscr();
 printf("  PROGRAM CARE DESENEAZA CURBA LUI KOCH ");
 printf("\n Originea reperului:(x0,y0) \n");
 scanf("%f",&x0);
 scanf("%f",&y0);
 printf("\n lat:");
 scanf("%f",&lat);
 printf("\n nivel: ");
 scanf("%d",&nivel);
 turtle_start();
 sprintf(mesaj," lat de %f",lat);
 outtextxy(0,10,mesaj);
 sprintf(mesaj," nivele %d",nivel);
 outtextxy(0,20,mesaj);
 set_reper(x0,y0);
 for(i=1;i<4;i++)
 {
  koch(lat,nivel);
  right(120);
 }
 turtle_stop();
}
