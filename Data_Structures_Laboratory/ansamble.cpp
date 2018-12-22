/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is ansamble.cpp Fisier pentru crearea si decapitarea unui ansamblu.

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
void insert_heap(int *ans,int *n,int val)
{
	int p;
	int tata;
	p=*n; //initializare parcurgere
	while(p>0)
	{
		tata=p/2;
		if(val>ans[tata])
		{
			ans[p]=ans[tata];//tata coboara pe pozitia fiului
			p=tata;
		}
		else
		{
			ans[p]=val;
			*n=*n+1; //creez o noua pozitie pt urmatoarea valoare
			return;
		}
	}
	ans[0]=val; //val era mai mare decit orice val din ansamblu
	*n=*n+1; //creez o noua pozitie pt urmatoarea valoare
}
void delete_heap(int *ans,int *n,int *val)
{
	int last,left,right,p;
	*val=ans[0];
	last=ans[*n-1];
	*n=*n-1;
	p=0;
	left=1;
	right=2;
	while(right<*n)
	{
		if(last>=ans[left] && last>=ans[right])
		{
			ans[p]=last;
			return;
		}
		else
		{
			if(ans[left]>ans[right])
			{
				ans[p]=ans[left];
				p=left;
			}
			else
			{
				ans[p]=ans[right];
				p=right;
			}
			left=2*p;
			right=2*p+1;
		}
	}
	if(left==*n-1 && last<ans[left])
	{
		ans[p]=ans[left];
		p=left;
	}
	ans[p]=last;
}


int main(int argc, char* argv[])
{
	int V[10];
	int n,i,j,val;
	int nr;
	for(i=0;i<10;i++) V[i]=0;
	cout<<"Cite elemente aveti in ansamblu\n";
	cin>>n;
	nr=0;
	for(i=0;i<n;i++)
	{
		cin>>val;
		insert_heap(V,&nr,val);
	}
	cout<<"Ansamblul datelor\n";
	for(j=0;j<n;j++)
		cout<<V[j]<<" ";
	cout<<endl;
	for(i=0;i<n;i++)
	{
		delete_heap(V,&nr,&val);
		cout<<"extras "<<val<<endl;
		cout<<"Ansamblul datelor\n";
		for(j=0;j<n;j++)
			cout<<V[j]<<" ";
		cout<<endl;
	}
	return 0;
}
