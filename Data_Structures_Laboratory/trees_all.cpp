/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is sortari.cpp trees_all.cpp fisier pentru arbori binari ordonati: 
	toate functiile posibile recursiv si iterativ.

    Data Structures Laboratory is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Data Structures Laboratory is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Data Structures Laboratory; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/


#include<stdio.h>
#include<stdlib.h>
struct element
{
	int info;
	struct element *fii[2];
};
struct element *virf,*temp,*temp1;
struct stiva
{
	struct element *element;
	struct stiva *legatura;
};
struct stiva *tempstiva;
void push(struct element *element,struct stiva **virf)
{
	tempstiva=(struct stiva *)calloc(1,sizeof(struct stiva));
	tempstiva->element=element;
	if(*virf==NULL)
	{
		*virf=tempstiva;
		tempstiva->legatura=NULL;
	}
	else
	{
		tempstiva->legatura=*virf;
		*virf=tempstiva;
	}
}
struct element *pop(struct stiva **virf)
{
	struct element *ret;
	if(*virf==NULL) return NULL;
	ret=(*virf)->element;
	tempstiva=*virf;
	*virf=(*virf)->legatura;
	free(tempstiva);
	return ret;
}
	
int introducere(int info)
{
	int flag;
	int test;
	temp=(struct element *)calloc(1,sizeof(struct element));
	temp->info=info;
	if(virf==NULL)
	{
		temp->fii[0]=NULL;
		temp->fii[1]=NULL;
		virf=temp;
	}
	else
	{
		temp->fii[0]=NULL;
		temp->fii[1]=NULL;
		temp1=virf;
		flag=0;
		while(flag==0)
		{
			test=temp1->info<temp->info;
			if(temp1->fii[test]==NULL)
			{
				temp1->fii[test]=temp;
				flag=1;
			}
			else 
			{
				temp1=temp1->fii[test];
			}
		}
	}
	return 0;
}
int RSD(void)
{
	int flag;
	int flag1;
	int i;
	int visite;
	struct stiva *virfstiva=NULL;
	printf("RSD\n");fflush(stdout);
	if(virf==NULL)
	{
		printf("L'arbre est vide.\n");
		fflush(stdout);
		return 1;
	}
	else
	{
		printf("%d ",virf->info);fflush(stdout);
		flag=0;
		flag1=0;
		temp1=virf;
		while(flag==0)
		{
			if(temp1->fii[0]!=NULL && flag1==0)
			{
				push(temp1,&virfstiva);
				temp1=temp1->fii[0];
				printf("%d ",temp1->info);fflush(stdout);
			}
			else
			if(temp1->fii[1]!=NULL)
			{
				temp1=temp1->fii[1];
				flag1=0;
				printf("%d ",temp1->info);fflush(stdout);
			}
			else
			{
				temp1=pop(&virfstiva);
				if(temp1==NULL) flag=1;
				else	flag1=1;
			}
		}
	}
	return 0;
}

int SRD(void)
{
	int flag;
	int flag1;
	int i;
	int visite;
	struct stiva *virfstiva=NULL;
	printf("\nSRD\n");fflush(stdout);
	if(virf==NULL)
	{
		printf("L'arbre est vide.\n");
		fflush(stdout);
		return 1;
	}
	else
	{
		flag=0;
		flag1=0;
		temp1=virf;
		while(flag==0)
		{
			if(temp1->fii[0]!=NULL && flag1==0)
			{
				push(temp1,&virfstiva);
				temp1=temp1->fii[0];
			}
			else
			if(temp1->fii[1]!=NULL)
			{
				printf("%d ",temp1->info);fflush(stdout);
				temp1=temp1->fii[1];
				flag1=0;
			}
			else
			{
				printf("%d ",temp1->info);fflush(stdout);
				temp1=pop(&virfstiva);
				if(temp1==NULL) flag=1;
				else	flag1=1;
			}
		}
	}
	return 0;
}
int frunze(struct element **virf1)
{
	struct element *virfint;
	int nr=0;
	virfint=*virf1;
	if(virfint==NULL) return 0;
	if(virfint->fii[0]==NULL && virfint->fii[1]==NULL) return 1;
	if(virfint->fii[0]!=NULL) nr+=frunze(&(virfint->fii[0]));
	if(virfint->fii[1]!=NULL) nr+=frunze(&(virfint->fii[1]));
	return nr;
}
void SRD_rec(struct element **virf1)
{
	struct element *virfint;
	virfint=*virf1;
	if(virfint==NULL) return;
	if(virfint->fii[0]!=NULL) SRD_rec(&(virfint->fii[0]));
	printf("%d ",virfint->info);fflush(stdout);
	if(virfint->fii[1]!=NULL) SRD_rec(&(virfint->fii[1]));
}
void RSD_rec(struct element **virf1)
{
	struct element *virfint;
	virfint=*virf1;
	if(virfint==NULL) return;
	printf("%d ",virfint->info);fflush(stdout);
	if(virfint->fii[0]!=NULL) RSD_rec(&(virfint->fii[0]));
	if(virfint->fii[1]!=NULL) RSD_rec(&(virfint->fii[1]));
}
void SDR(struct element **virf1)
{
	struct element *virfint;
	virfint=*virf1;
	if(virfint==NULL) return;
	if(virfint->fii[0]!=NULL) SDR(&(virfint->fii[0]));
	if(virfint->fii[1]!=NULL) SDR(&(virfint->fii[1]));
	printf("%d ",virfint->info);fflush(stdout);
}

int main()
{
	int data[10]={10,12,2,3,20,45,15,18,6,9};
	int i;
	virf=NULL;
	for(i=0;i<10;i++)
		introducere(data[i]);
	printf("\nRSD\n");fflush(stdout);
	RSD_rec(&virf);
	printf("\nSRD\n");fflush(stdout);
	SRD_rec(&virf);
	printf("\nSDR\n");fflush(stdout);
	SDR(&virf);
	printf("\nNR funze=%d\n",frunze(&virf));fflush(stdout);
}