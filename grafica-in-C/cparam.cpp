/* program care deseneaza curbe date de ecuatii parametrice */
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include"mat.h"
int gdriver=DETECT,gmode,errorcode;
int i,t1,t2,flag,h;
float a,b,arg,val1,val2;
int graphx[639],graphy[639];
void init(void)
{
 /* introducere driver grafic in executabil */
 errorcode=registerfarbgidriver(EGAVGA_driver_far);
 initgraph(&gdriver,&gmode,"");
 setviewport(320,175,500,200,0);
 setbkcolor(1);setcolor(14);
 rectangle(-150,-150,150,150);
 setviewport(170,25,470,325,1);
}
void stop(void)
{
 getch();
 closegraph();
}
void axe(void)
{
 moveto(120,150);
 lineto(180,150);
 moveto(150,120);
 lineto(150,180);
}
void graph1(int t1,int t2)
/* deseneaza curba data de ecuatiile parametrice */
{
 moveto(graphx[t1+319],graphy[t1+319]); //fara trasare
 for(i=t1+1;i<=t2;i++)
  lineto(graphx[i+319],graphy[i+319]);  //trasare
}
void main(void)
{
 h=1;
 do
 {
  t1=0;t2=0;a=0.0;b=0.0;
  clrscr();
  printf("                              CURBE PLANE REMARCABILE                         \n");
  printf("\n");
  printf("1=concoida NICOMEDE           2=melcul lui PASCAL     \n");
  printf("3=cisoida DIONCLES            4=cisoida elipsei               \n");
  printf("5=trisectorea MAC-LAURIN      6=trisectoarea LONCHAMPS        \n");
  printf("7=cicloida                    8=epicicloida                   \n");
  printf("9=hipocicloida                        10=astroida                     \n");
  printf("11=strofoida                  12=bucla MARISA AGNESI  \n");
  printf("\n");
  printf("Centrul ecranuluieste originea sistemului cartesian\n");
  printf("Pentru iesire tastati 0\n");
  printf("Precizati numarul de ordine pentru curba dorita:");
  scanf("%d",&flag);
  switch (flag)
  {
   case 0:
   h=0;
   break;
   case 1:
        clrscr();
        printf("        CURBA LUI NICOMEDE \n");
        printf(" Dati parametrii a,b:\n");
        scanf("%f",&a);
        fflush(stdin);
        scanf("%f",&b);
        fflush(stdin);
        t1=round((-M_PI/2.0)*100);t2=round((M_PI/2.0)*100);
    /* factorul 100 reprezinta scalarea imaginii */
        for(i=t1;i<=t2;i++)
        {
         arg=i/100.0;
         graphx[i+319]=round((a+b*cos(arg))*100)+150;
         graphy[i+319]=round((a*sin(arg)/cos(arg)+b*sin(arg))*100)+150;
        }
        init();
        axe();
        graph1(t1,t2);
        for(i=t1;i<=t2;i++)
        {
         arg=i/100.0;
         graphx[i+319]=round((a-b*cos(arg))*100)+150;
         graphy[i+319]=round((a*sin(arg)/cos(arg)-b*sin(arg))*100)+150;
        }
        graph1(t1,t2);
        stop();
    break;
    case 2:
        clrscr();
        printf("        MELCUL LUI PASCAL       \n");
        printf(" Dati parametrii a,b:\n");
        scanf("%f",&a);
        fflush(stdin);
        scanf("%f",&b);
        fflush(stdin);
        t1=round(-M_PI*90);t2=-t1;
        for(i=t1;i<=t2;i++)
        {
         arg=i/90.0;
         graphx[i+319]=round((2*(a*cos(arg)+b)*cos(arg))*90);
         graphy[i+319]=round((2*(a*cos(arg)+b)*sin(arg))*90);
         graphx[i+319]=graphx[i+319]+150;graphy[i+319]=graphy[i+319]+150;
        }
        init();
        axe();
        graph1(t1,t2);
        stop();
    break;
    case 3:
        clrscr();
        printf("        CISOIDA LUI DIOCLES (cisoida cercului) \n");
        printf(" Dati parametrul a:");
        scanf("%f",&a);
        fflush(stdin);
        t1=round((-M_PI/2.0)*90);t2=-t1;
        for(i=t1;i<=t2;i++)
        {
         arg=i/90.0;
         graphx[i+319]=round((2*a*sin(arg)*sin(arg))*90)+150;
         graphy[i+319]=round((2*a*sin(arg)*sin(arg)*sin(arg)/cos(arg))*90)+150;
        }
        init();
        axe();
        graph1(t1,t2);
        stop();
    break;
    case 4:
        clrscr();
        printf("        CISOIDA ELIPSEI \n");
        printf(" Dati parametrii a,b:\n");
        scanf("%f",&a);
        fflush(stdin);
        scanf("%f",&b);
        fflush(stdin);
        t1=round((-M_PI/2.0)*90);t2=-t1;
        for(i=t1;i<=t2;i++)
        {
         arg=i/90.0+0.01;
         graphx[i+319]=round((2*a*a*a/(a*a+b*b*pow(cos(arg)/sin(arg),2)))*90)+150;
         graphy[i+319]=round((2*a*a*a/(a*a*cos(arg)/sin(arg)+b*b*pow(cos(arg)/
                                sin(arg),3)))*90)+150;
        }
        init();
        axe();
        graph1(t1,t2);
        stop();
    break;
    case 5:
         clrscr();
         printf("  TRISECTOAEA LUI MAC-LAURIN \n");
         printf(" Dati parametrul a:");
         scanf("%f",&a);
         fflush(stdin);
         t1=round((-M_PI/2.0)*90);t2=-t1;
         for(i=t1;i<=t2;i++)
         {
          arg=i/90.0+0.01;
          graphx[i+319]=round((4*a*cos(arg)*cos(arg)-a)*90)+150;
          graphy[i+319]=round(((4*a*cos(arg)*cos(arg)-a)*sin(arg)/cos(arg))
                                 *90)+150;
         }
         init();
         axe();
         graph1(t1,t2);
         stop();
    break;
    case 6:
         clrscr();
         printf("               TRISECTOAREA LUI LONGCHAMPS \n");
         printf(" Dati parametrul a:");
         scanf("%f",&a);
         fflush(stdin);
         t1=round((-M_PI/2.0)*50);t2=-t1;
         for(i=t1;i<=t2;i++)
         {
          arg=i/50.0+0.01;
          graphx[i+319]=round((a/(4*cos(arg)*cos(arg)-3))*50)+150;
          graphy[i+319]=round(((a*sin(arg)/cos(arg))/(4*cos(arg)*cos(arg)-3))*
                                50)+150;
         }
         init();
         axe();
         graph1(t1,t2);
         stop();
    break;
    case 7:
         clrscr();
         printf("               CICLOIDA \n");
         printf(" Dati parametrii a,b:\n");
         scanf("%f",&a);
         fflush(stdin);
         scanf("%f",&b);
         fflush(stdin);
         t1=round((-2*M_PI*1.4)*35);t2=-t1;
         for(i=t1;i<=t2;i++)
         {
          arg=i/35.0;
          graphx[i+319]=round((a*arg-b*sin(arg))*35)+150;
          graphy[i+319]=round((a-b*cos(arg))*35)+150;
         }
         init();
         axe();
         graph1(t1,t2);
         stop();
    break;
    case 8:
         clrscr();
         printf("               EPICICLOIDA \n");
         printf(" Dati parametrii a,b:\n");
         scanf("%f",&a);
         fflush(stdin);
         scanf("%f",&b);
         fflush(stdin);
         t1=0;t2=round(10*M_PI*10);
         for(i=t1;i<=t2;i++)
         {
          arg=i/10.00;
          val1=b*arg/a;val2=arg+b*arg/a;
          graphx[i+319]=round(((a+b)*cos(val1)-b*cos(val2))*60)+150;
          graphy[i+319]=round(((a+b)*sin(val1)-b*sin(val2))*60)+150;
         }
         init();
         axe();
         graph1(t1,t2);
         stop();
    break;
    case 9:
         clrscr();
         printf("               HIPOCICLOIDA \n");
         printf(" Dati parametrii a,b:\n");
         scanf("%f",&a);
         fflush(stdin);
         scanf("%f",&b);
         fflush(stdin);
         t1=0;t2=round(10*M_PI*10);
         for(i=t1;i<=t2;i++)
         {
          arg=i/10.00;
          val1=b*arg/a;val2=arg-b*arg/a;
          graphx[i+319]=(((a-b)*cos(val1)+b*cos(val2))*150)+150;
          graphy[i+319]=(((a-b)*sin(val1)-b*sin(val2))*150)+150;
         }
         init();
         axe();
         graph1(t1,t2);
         stop();
    break;
    case 10:
         clrscr();
         printf("               ASTOIDA \n");
         printf(" Dati parametrul a:");
         scanf("%f",&a);
         fflush(stdin);
         t1=0;t2=round(2*M_PI*10);
         for(i=t1;i<=t2;i++)
         {
          arg=i/10.00;
          graphx[i+319]=round((a*cos(arg)*cos(arg)*cos(arg))*60)+150;
          graphy[i+319]=round((a*sin(arg)*sin(arg)*sin(arg))*60)+150;
         }
         init();
         axe();
         graph1(t1,t2);
         stop();
    break;
    case 11:
         clrscr();
         printf("               STROFOIDA\n");
         printf(" Dati parametrul a:");
         scanf("%f",&a);
         fflush(stdin);
         t1=round((-M_PI/2.0)*60);t2=-t1;
         for(i=t1;i<=t2;i++)
         {
          arg=i/60.0+0.01;
          graphx[i+319]=round((a+a*sin(arg))*60)+150;
          graphy[i+319]=round((a*sin(arg)/cos(arg)+a*sin(arg)*sin(arg)/
                                cos(arg))*60)+150;
         }
         init();
         axe();
         graph1(t1,t2);
         for(i=t1;i<=t2;i++)
         {
          arg=i/60.0+0.01;
          graphx[i+319]=round((a-a*sin(arg))*60)+150;
          graphy[i+319]=round((a*sin(arg)/cos(arg)-a*sin(arg)*sin(arg)/cos(arg)
                                )*60)+150;
         }
         graph1(t1,t2);
         stop();
    break;
    case 12:
         clrscr();
         printf("               BUCLA MARIA AGNESII \n");
         printf(" Dati parametrul a:");
         scanf("%f",&a);
         fflush(stdin);
         t1=1;t2=round(M_PI*60)-1;
         for(i=t1;i<=t2;i++)
         {
          arg=i/60.0;
          graphx[i+319]=round(a*cos(arg)/sin(arg)*60)+150;
          graphy[i+319]=round(a*sin(arg)*sin(arg)*60)+150;
         }
         init();
         axe();
         graph1(t1,t2);
         stop();
    break;
  }
 }while(h!=0);
}