#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int K=16,inalt,lung;
int i,l,j;
char text[140];
div_t dim;
float x,y,r,qmax,qmin,pmax,pmin,m=100.0;
int cul,k=0;
int culori[16]={6,5,3,2,1,7,15,13,12,14,4,0,10,11,9,8};
int calcul(float p,float q,int k)
/* calculeaza factorul de culoare k */
{
  float x1,y1;
  k=0;
  x=0;
  y=0;
  do
  {
    k=k+1;
    x1=x*x-y*y+p;
    y1=2*x*y+q;
    x=x1;
    y=y1;
    r=x*x+y*y;
  } while ((r<m)&&(k<K));
 return(k);
 }
void desenare(void)
/* deseneaza setul de fractali mandelbot */
{
  int np,nq;
  float deltap,deltaq;
  deltap=(pmax-pmin)/lung;
  deltaq=(qmax-qmin)/inalt;
  for(nq=0;nq<inalt;nq++)
  {
        for(np=0;np<lung;np++)
        {
                cul=calcul(pmin+np*deltap,qmin+nq*deltaq,k);
                putpixel(np,nq,culori[cul%16]);
        }
  }
}
void main(void)
{
clrscr();
/* se introduc factorii necesari calcularii */
printf("\n              PROGRAM PENTRU DESENAREA SETULUI MANDELBOT");
printf("\n Introduceti datele xmin,xmax,ymin,ymax:\n");
scanf("%f",&pmin);
scanf("%f",&pmax);
scanf("%f",&qmin);
scanf("%f",&qmax);
printf("\n Intoduceti lungimea si inaltimea:\n");
scanf("%d",&lung);
scanf("%d",&inalt);
/* cerere de autodetectie grafica */
int graphdriver=DETECT,
    graphmode,
    errorcode;
/* introducere in executabil a driverului grafic */
//errorcode=registerfarbgidriver(EGAVGA_driver_far);
/* initializare mod grafic */
initgraph(&graphdriver,&graphmode,"");
errorcode=graphresult();
if(errorcode!=grOk)
{
        printf("EROARE GRAFICA");
        grapherrormsg(errorcode);
}
else
{
 desenare();
 dim=div(inalt,16);
 k=0;
 /* desenare benzi de culoare pentru comparare */
 for(l=0;l<inalt;l=l+dim.quot,k++)
 for(i=lung+30;i<getmaxx();i++)
 for(j=0;j<dim.quot;j++)
  putpixel(i,l+j,culori[k]);
 /* afisare in mod grafic a datelor introduse */
 sprintf(text,"Avem introduse: %f,%f,%f,%f",pmin,pmax,qmin,qmax);
 outtextxy(50,inalt+10,text);
 getch();       // asteapta apasarea unei tasste pentru iesire
 closegraph(); // inchide modul grafic
}
}