// Sort.cpp: implementation of the CSort class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Sort.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSort::CSort()
{
	data=NULL;
	nr=0;
}

CSort::~CSort()
{
	if(data!=NULL) free(data);
}

CSort::CSort(long *val,int n)
{
	nr=n;
	data=(long *)calloc(nr,sizeof(long));
	for(int i=0;i<nr;i++)
		data[i]=val[i];
}

void CSort::Print()
{
	for(int i=0;i<nr;i++)
		cout<<data[i]<<" ";
	cout<<endl;
}

void CSort::DirectIns()
{
	long aux;
	int i,j;
	for(i=0;i<nr;i++)
	{
		aux=data[i];
		for(j=i-1;j>=0,aux<data[j];j--)
			data[j+1]=data[j];
		data[j+1]=aux;
	}
}

void CSort::DirectSel()
{
	long min;
	int i,j,k;
	for(i=0;i<nr-1;i++)
	{
		k=i;
		min=data[i];
		for(j=i+1;j<nr;j++)
			if(data[j]<min)
			{
				k=j;
				min=data[j];
			}
		data[k]=data[i];
		data[i]=min;
	}
}

void CSort::BubleSort()
{
	long aux;
	int i,j;
	for(j=0;j<nr;j++)
		for(i=nr-1;i>j;i--)
			if(data[i-1]>data[i])
			{
				aux=data[i-1];
				data[i-1]=data[i];
				data[i]=aux;
			}
}

void CSort::ShakeSort()
{
	int left,right,i,k;
	long aux;
	left=0;
	right=nr-1;
	while(left<=right)
	{
		for(i=right;i>=left;i--)
			if(data[i-1]>data[i])
			{
				aux=data[i-1];
				data[i-1]=data[i];
				data[i]=aux;
				k=i;
			}
		left=k+1;
		for(i=left;i<=right;i++)
			if(data[i-1]>data[i])
			{
				aux=data[i-1];
				data[i-1]=data[i];
				data[i]=aux;
				k=i;
			}
		right=k-1;
	}
}

void CSort::ShellSort()
{
	long m,t,x,j,k,i;
	long *h;
	long temp;
	double val=log(nr)/log(2);
	temp=(long )val;
	if(val-temp<0.5) t=temp-1;
	else t=temp;
	h=(long *)calloc(t,sizeof(long));
	h[t-1]=1;
	for(i=t-2;i>=0;i--)	h[i]=h[i+1]*2+1;
	for(m=0;m<t;m++)
	{
		k=h[m];
		for(i=k;i<nr;i++)
		{
			x=data[i];
			j=i-k;
			while(x<data[j] && j>=0)
			{
				data[j+k]=data[j];
				j=j-k;
			}
			data[j+k]=x;
		}
	}
	free(h);
}
