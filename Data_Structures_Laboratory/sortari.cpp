/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is sortari.cpp Diferite sortari pentru vectori alocati static.

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
#include<math.h>
int vector[100];
//sortare directa (insertie directa)
void sortinsdir(int *A,int n)
{
	int i,j,aux;
	for(i=1;i<n;i++)
	{
		aux=A[i];
		//cautam pozitia corecta a componentei curente
		j=i-1;
		while(j>=0 && aux<A[j])
		{
			A[j+1]=A[j];
			j--;
		}
		//facem inserarea componentei curente in pozitia corecta
		A[j+1]=aux;
	}
}
//sortare prin selectie directa (cautarea minimului)
void sortseldir(int *A,int n)
{
	int i,k,min,j;
	for(i=0;i<n-1;i++)
	{
		//cautam valoarea minima in A[i]..A[n-1]
		k=i;
		min=A[i];
		for(j=i+1;j<n;j++) 
			if(A[j]<min)
			{
				k=j;
				min=A[j];
			}
		//aducem minimul curent pe pozitia lui
		A[k]=A[i];
		A[i]=min;
	}
}
//sortare prin inteschimbare dicreta(buble sort)
void sortinteschdir(int *A,int n)
{
	int j,i,aux;
	for(j=1;j<n;j++)
		for(i=n-1;i>=j;i--)
			if(A[i-1]>A[i])
			{
				aux=A[i-1];
				A[i-1]=A[i];
				A[i]=aux;
			}
}
//sortare prin interschimbare directa imbunatatita
void sortinteschdir1(int *A,int n)
{
	int j,i;
	int sch,aux;
	j=1;//initializeaza parcurgerea sursei
	sch=1;
	while(j<n && sch!=0)
	{
		sch=0;
		for(i=n-1;i>=j;i--)
			if(A[i-1]>A[i])
			{
				aux=A[i-1];
				A[i-1]=A[i];
				A[i]=aux;
				sch++;
			}
		j++;
	}
}
//sortare prin interschimbare directa imbunatatita
void sortinteschdir2(int *A,int n)
{
	int j,i,aux,k;
	j=1;
	while(j<n)
	{
		i=n-1;
		while(i>=j)
		{
			if(A[i-1]>A[i])
			{
				aux=A[i-1];
				A[i-1]=A[i];
				A[i]=aux;
				k=i; //mem poz ultimei interschimbari
			}
			i--;
		}
		j=k+1; //initializeaza parcurgerea noii surse
	}
}
//algoritmul Shake Sort
void shakesort(int *A,int n)
{
	int left, right,i,k,aux;
	left=0;right=n-1; //initializam sursa
	while(left<right)
	{
		for(i=right;i>=left;i--)
		{
			if(A[i-1]>A[i])
			{
				aux=A[i-1];
				A[i-1]=A[i];
				A[i]=aux;
				k=i;
			}
		}
		left=k+1; //redefinesc extremitatea stinga a sursei
		for(i=left;i<=right;i++)
			if(A[i-1]>A[i])
			{
				aux=A[i-1];
				A[i-1]=A[i];
				A[i]=aux;
				k=i=1;
			}
		right=k-1;
	}
}
//functia care realizeaza trunc
int trunc(double val)
{
	int temp;
	temp=(int)val;
	if(val-temp<0.5) return temp;
	else return temp+1;
}
//algoritmul Shell Sort
void shellsort(int *A,int n)
{
	int m,t,x,j,k,i;
	int *h;
	t=trunc(log(n)/log(2))-1;
	h=new int[t];
	h[t-1]=1;
	for(i=t-2;i>=0;i--)	h[i]=h[i+1]*2+1;
	for(m=0;m<t;m++)
	{
		k=h[m];
		for(i=k;i<n;i++)
		{
			x=A[i];
			j=i-k;
			while(x<A[j] && j>=0)
			{
				A[j+k]=A[j];
				j=j-k;
			}
			A[j+k]=x;
		}
	}
	delete[] h;
}

int main(int argc, char* argv[])
{
	int i,n;
	cout<<"Cite numere aveti<100 n=";cin>>n;
	for(i=0;i<n;i++)
		cin>>vector[i];
	//sortinsdir(vector,n);
	//sortseldir(vector,n);
	//sortinteschdir(vector,n);
	//sortinteschdir1(vector,n);
	//sortinteschdir2(vector,n);
	//shakesort(vector,n);
	shellsort(vector,n);
	cout<<"Dupa sortare vectorul a devenit\n";
	for(i=0;i<n;i++)
		cout<<" "<<vector[i];
	cout<<endl;
	return 0;
}
