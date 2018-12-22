/* deseneaza un arbore binar */
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include"turtle.h"
int level,x0,y0;
char mesaj[40];
float length,limit,u;
void tree(int level,float length)
{
 if (length<limit) delay(2);
   else
    if (!level) delay(2);
	else
	{
	 forward(length);
	 left(u);
	 tree(level-1,length/2);
	 right(2*u);
	 tree(level-1,length/2);
	 left(u);
	 back(length);
	}
}
void main(void)
{
 printf("\n DESENAREA UNUI ARBORE BINAR \n");
 printf("originea reperului (x0,y0): ");
 scanf("%d",&x0);
 scanf("%d",&y0);
 printf("\n level: ");
 scanf("%d",&level);
 printf("\n length: ");
 scanf("%f",&length);
 printf("\n limit: ");
 scanf("%f",&limit);
 printf("\n unghi: ");
 scanf("%f",&u);
 turtle_start();
 /* afisare in mod grafic a datelor introduse */
 sprintf(mesaj,"NIVELE :%d",level);
 outtextxy(0,10,mesaj);
 sprintf(mesaj,"LUNGIME :%f",length);
 outtextxy(0,20,mesaj);
 sprintf(mesaj,"LIMITA :%f",limit);
 outtextxy(0,30,mesaj);
 sprintf(mesaj,"UNGHI :%f",u);
 outtextxy(0,40,mesaj);
 set_reper(x0,y0);
 tree(level,length);
 turtle_stop();
}