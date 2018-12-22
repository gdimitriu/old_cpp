#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
int i,j,l;
div_t dim;
char text[140];
int K=16,k=0,inalt,lung;
float xmin,xmax,ymin,ymax,r,p,q,m=100.0;
int culori[16]={6,5,3,2,1,7,15,13,12,14,4,0,10,11,9,8};
int calcul(float x,float y,int k)
/* calculeaza factorul de culoare k */
{
float x1;
k=0;
do
 {
  k=k+1;
  x1=x*x-y*y+p;
  y=2*x*y+q;
  x=x1;
 } while(((x*x+y*y)<m)&&(k<K));
 return(k);
}
void deseneaza(void)
/* deseneaza setul fractal */
{
 int nx,ny,k;
 float deltax,deltay;
 deltax=(xmax-xmin)/lung;
 deltay=(ymax-ymin)/inalt;
 for(ny=0;ny<inalt;ny++)
  for(nx=0;nx<lung;nx++)
  {
   k=calcul(xmin+nx*deltax,ymin+ny*deltay,k);
   putpixel(nx,ny,culori[k%16]);
  }
}
void main(void)
{
clrscr();
/* se introduc datele */
printf("\n           PROGRAM PENTRU DESENAEA SETULUI JULIA");
printf("\n Introduceti datele xmin,xmax,ymin,ymax:\n");
scanf("%f",&xmin);
scanf("%f",&xmax);
scanf("%f",&ymin);
scanf("%f",&ymax);
printf("\n Introduceti lungimea si inaltimea ecranulu:\n");
scanf("%i",&lung);
scanf("%d",&inalt);
printf("\n Introduceti factorii p,q:\n");
scanf("%f",&p);
scanf("%f",&q);
int graphdriver=DETECT, /* cerere de initializare grafica */
    graphmode,
    errorcode;
/* introducerea driverului grafic in compozitia executabilului */
//errorcode=registerfarbgidriver(EGAVGA_driver_far);
/* initializare mod grafic */
initgraph(&graphdriver,&graphmode,"");
errorcode=graphresult();
if (errorcode!=grOk)
 printf(" EROARE GRAFICA");
else
{
 deseneaza();
 dim=div(inalt,16);
 k=0;
 /* deseneaza benzile de culoare pentru comparatie */
 for(l=0;l<inalt;l=l+dim.quot,k++)
 for(i=lung+30;i<getmaxx();i++)
 for(j=0;j<dim.quot;j++)
 putpixel(i,j+l,culori[k]);
 /* afiseaza in modul grafic datele introduse */
 sprintf(text,"Avem introduse: %f,%f,%f,%f",xmin,xmax,ymin,ymax);
 outtextxy(50,inalt+8,text);
 sprintf(text,"Avem factorii p si q: %f,%f",p,q);
 outtextxy(50,inalt+16,text);
 getch();       // asteapa apasarea unei taste pentru iesire
 closegraph();  // inchide modul grafic
 }
}
