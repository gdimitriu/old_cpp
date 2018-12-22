/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is vectori_ordonati.cpp Operatii asupra vectorilor ordonati.

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
#include<iostream.h>
#define MAX 10
int vsearch(int n,int *A,int val)
{
	//functie pentru cautarea binara modificata a unui element
	//returneaza pozitia pe care a fost gasit elementul sau
	//returneaza pozitia (+-1 pozitie) pe care trebuia sa se gaseasca elementul
	int liminf,limsup,omid,mid;
	//initializez limitele
	liminf=0;
	limsup=n-1;
	//calculez mijlocul
	mid=(liminf+limsup)/2;
	while(1)
	{
		if(val<A[mid]) limsup=mid;
		if(val>A[mid]) liminf=mid;
		omid=mid;
		mid=(liminf+limsup)/2;
		if(A[mid]==val) break; //am gasit valoarea
		if(limsup==liminf || omid==mid) break; //nu am gasit valoarea
	}
	return mid;
}
void deplasare(int *n,int *A,int pos)
{
	//procedura de deplasare a vectorului pentru a face loc elementului de inserat
	int i;
	for(i=*n-1;i>=pos;i--) A[i+1]=A[i];
	*n=*n+1;
}
void inserare(int *n,int *A,int val,int max)
{
	/*
		procedura de inserare a unui element folosind cautarea binara modificata pentru
		a gasi pozitia pe care trebuie inserat elementul
	*/
	int mid;
	if(*n==0)
	{
		A[0]=val;
		*n=1;
		return;
	}
	if(val<=A[0]) //daca este primul element
	{
		deplasare(n,A,0);
		A[0]=val;
		return;
	}
	else if (A[*n-1]<=val) //daca este pe ultima pozitie
	{
		if((*n+1)>max) cout<<"Imposibil, overflow";
		else
		{
			A[*n]=val;
			*n=*n+1;
		}
	}
	else
	{
		mid=vsearch(*n,A,val); //caut elementul
		if(A[mid]<val) mid++; //daca este mai mic decit valoarea de mijloc
		else mid--; //daca este mai mare decit valoarea de mijloc
		deplasare(n,A,mid); //deplasez elementele
		A[mid]=val;
	}
}
void cautare_vector_ordonat(int *A,int n,int val,int *loc)
{
	//cautare in mod normal liniara
	*loc=-1;
	int i=0;
	while(i<n && A[i]<val) i=i+1;
	if(i>n-1) cout<<"Cautare fara succes\n";
	if(A[i]==val)
	{
		cout<<"Cautarea a avut succes\n";
		*loc=i;
	}
	else cout<<"Cautare fara succes\n";
}
void cautare_binara(int *A,int n,int val,int *loc)
{
	//cautare binara nemodificata
	int liminf=0;
	int limsup=n-1;
	int mid=(limsup+liminf)/2;
	*loc=-1;
	//realizez procedeul divide et impera
	while(liminf<=limsup && val!=A[mid])
	{
		if(val<A[mid]) limsup=mid-1;
		else if(val>A[mid]) liminf=mid+1;
		mid=(liminf+limsup)/2;
	}
	//verific daca valaorea din mijloc este valoarea cautata
	if(A[mid]==val)
	{
		cout<<"Cautare cu succes\n";
		*loc=mid;
	}
	else cout<<"Cautare fara succes\n";
}
int main(int argc, char* argv[])
{
	int flag=1;
	int n=0;
	int A[MAX],val,poz;
	while(flag==1)
	{
		cout<<"Introduceti valoarea val\n";
		cin>>val;
		inserare(&n,A,val,10);
		cout<<"Doriti alt element 0/1";
		cin>>flag;
		if(flag==1 && (n-1)==MAX)
		{
			cout<<"Nu mai este spatiu\n";
			flag=0;
		}
	}
	cout<<"Vectorul are "<<n<<" componente\n";
	for(int i=0;i<MAX;i++) cout<<A[i]<<endl;
	cout<<"Introduceti valoarea de cautat\n";
	cin>>val;
	cautare_vector_ordonat(A,n,val,&poz);
	if(poz>=0) cout<<"Elementul "<<val<<" a fost gasit cu ajutorul cautarii normale pe pozitia "<<poz<<endl;
	cautare_binara(A,n,val,&poz);
	if(poz>=0) cout<<"Elementul "<<val<<" a fost gasit cu ajutorul cautarii binare pe pozitia "<<poz<<endl;
	return 0;
}
