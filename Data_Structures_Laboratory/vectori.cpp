/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is vectori.cpp Functii de baza pentru vectori in alocare statica.

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

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int vector[MAX];
void introducere(int *vec,int *nr)
{
	printf("Cite numere aveti de introdus < %d\n",MAX);
	scanf("%d",nr);fflush(stdin);
	printf("Introduceti valorile\n");
	for(int i=0;i<*nr;i++) scanf("%d",&vec[i]);
}
void viziteaza(int val)
{
	//functia pentru vizitarea unui element din vector
	printf("%d \n",val);
	fflush(stdout);
}
void traversare(int *vec,int start,int stop)
{
	//functia de traversare a vectorului
	int i=start;
	while(i<stop)
	{
		viziteaza(vec[i]);
		i=i+1;
	}
}
void inserare(int *vect,int *nr,int val,int k)
{
	//functie pentru inserarea unui element pe o pozitie data in structura
	int i;
	if((*nr+1)>MAX) //verific daca am loc
	{
		printf("Depasire de structura\n");
		return;
	}
	if(k<0) //verific daca nu se cere introducerea pe o pozitie aberanta
	{
		printf("Imposibil sa pun pe -1\n");
		return;
	}
	//fac loc la element
	i=*nr-1;
	while(i>=k)
	{
		vect[i+1]=vect[i];
		i=i-1;
	}
	//inserez elementul
	vect[k]=val;
	//reactualizez numarul de elemente din structura
	*nr=*nr+1;
}
void stergere(int *vect,int *nr,int *x,int k)
{
	//functie pentru extragerea unui element de pe pozitia k din vector
	int i;
	*x=vect[k]; //salvez valoarea
	for(i=k;i<(*nr-1);i++) vect[i]=vect[i+1]; //refac structura
	*nr=*nr-1; //refac numarul de elemente din structura
}
void cauta1(int *vect,int nr,int val,int *poz)
{
	*poz=-1; //initializez pozitia
	int i=0;
	while(i<nr && vect[i]!=val) i=i+1; //caut elementul
	if(i<nr) *poz=i; //returnez pozitia gasita
}
void cauta_marcaj(int *vect,int nr,int val,int *poz)
{
	vect[nr]=val;
	int i=0;
	while(vect[i]!=val) i=i+1;
	*poz=i;
}
int main(int argc, char* argv[])
{
	int nr;
	int x;
	int poz;
	introducere(vector,&nr);
	printf("Vectorul dupa introducerea datelor\n");
	traversare(vector,0,nr);
	inserare(vector,&nr,10,2);
	printf("Vectorul dupa inserare\n");
	traversare(vector,0,nr);
	stergere(vector,&nr,&x,2);
	printf("Elementul extras este %d.\n",x);
	printf("Vectorul dupa extragere\n");
	traversare(vector,0,nr);
	printf("Elementul de cautat\n");scanf("%d",&x);
	cauta1(vector,nr,x,&poz);
	if(poz>=0) printf("Elementul %d a fost gasit pe pozitia %d in vector\n",x,poz);
	else printf("Elementul %d nu a fost gasit in vector\n",x);
	cauta_marcaj(vector,nr,x,&poz);
	printf("Cautare cu componenta marcaj\n");
	if(poz==nr) printf("Elementul %d nu a fost gasit in vector\n",x);
	else printf("Elementul %d a fost gasit pe pozitia %d in vector\n",x,poz);
	return 0;
}
