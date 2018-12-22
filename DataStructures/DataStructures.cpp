// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include "Fifo.h"
#include "MFifo.h"
#include "DList.h"
#include "Tree.h"
#include "Sort.h"

long datl[10]={100,4,2,5,7,3,2,10,11,0};
double datd[10]={0.1,4.1,2.1,5.1,7.1,3.1,2.1,10.1,11.1,100.1};
char dats[10][3]={"r1","e1","c1","d1","f1","h1","g1","01","i1","+1"};
char datc[10]={'r','e','c','d','f','h','g','0','i','+'};

void print(void *data,int type)
{
	if(type==0)
		cout<<"Data "<<*((long *)data)<<endl;
	else if(type==1)
		cout<<"Data "<<*((double *)data)<<endl;
	else if(type==2)
		cout<<"Data "<<(char *)data<<endl;
	else if(type==3)
		cout<<"Data "<<*((char *)data)<<endl;
}
void sortari(void)
{
	CSort *sort;
	sort=new CSort(datl,10);
	sort->DirectIns();
	sort->Print();
	delete sort;
	sort=new CSort(datl,10);
	sort->DirectSel();
	sort->Print();
	delete sort;
	sort=new CSort(datl,10);
	sort->BubleSort();
	sort->Print();
	delete sort;
	sort=new CSort(datl,10);
	sort->ShakeSort();
	sort->Print();
	delete sort;
	sort=new CSort(datl,10);
	sort->ShellSort();
	sort->Print();
}

void tree(void)
{
	int type;
	long dim=10;
	int i;
	CTree treed;
	for(i=0;i<dim;i++)
		treed.Add(datl[i]);
	for(i=0;i<dim;i++)
		treed.Add(datd[i]);
	for(i=0;i<dim;i++)
		treed.Add(dats[i]);
	for(i=0;i<dim;i++)
		treed.Add(datc[i]);
	treed.Del(datl[5]);
	treed.Del(datd[5]);
	treed.Del(datc[5]);
	treed.Del(dats[5]);
//	for(type=3;type<4;type++)
//		treed.PrintSRD(type);
//		treed.PrintRSD(type);
//		treed.PrintSDR(type);

	for(type=0;type<4;type++)
	{
		void *dat;
		dat=treed.Get(type);
		while(dat!=NULL)
		{
			print(dat,type);
			dat=treed.Get(type);
		}
	}
}
void dlist(void)
{
	void *data;
	int type;
	long dim=10;
	CDList list;
	int i,j,k,l,m;
	i=0;
	j=0;
	k=0;
	l=0;
	m=0;
	while(j<dim || k<dim || l<dim || m<dim)
	{
		if(i%4==0 && j<dim)
		{
			list.Add(datl[j]);
			j++;
		}
		if(i%4==1 && k<dim)
		{
			list.Add(datd[k]);
			k++;
		}
		if(i%4==2 && l<dim)
		{
			list.Add(datc[l]);
			l++;
		}
		if(i%4==3 && m<dim)
		{
			list.Add(dats[m]);
			m++;
		}
		i++;
	}
	list.Del(datl[5]);
	list.Del(datd[5]);
	list.Del(dats[5]);
	list.Del(datc[5]);

	for(type=0;type<4;type++)
	{
		data=list.Get(type);
		while(data!=NULL)
		{
			print(data,type);
			data=list.Get(type);
		}
	}
}
void mfifo(void)
{
	void *data;
	int type;
	long dim=4;
	CMFifo fifo;
	int i,j,k,l,m;
	i=0;
	j=0;
	k=0;
	l=0;
	m=0;
	while(j<dim || k<dim || l<dim || m<dim)
	{
		if(i%4==0 && j<dim)
		{
			fifo.Push(datl[j]);
			j++;
		}
		if(i%4==1 && k<dim)
		{
			fifo.Push(datd[k]);
			k++;
		}
		if(i%4==2 && l<dim)
		{
			fifo.Push(datc[l]);
			l++;
		}
		if(i%4==3 && m<dim)
		{
			fifo.Push(dats[m]);
			m++;
		}
		i++;
	}
	for(type=0;type<4;type++)
	{
		data=fifo.Pop(type);
		while(data!=NULL)
		{
			print(data,type);
			data=fifo.Pop(type);
		}
	}
}
void fifo(void)
{
	void *data;
	int type;
	long dim=4;
	CFifo fifo;
	int i,j,k,l,m;
	i=0;
	j=0;
	k=0;
	l=0;
	m=0;
	while(j<dim || k<dim || l<dim || m<dim)
	{
		if((i+j+k)%5==0)
		{
			data=fifo.Pop(&type);
			if(type!=-1) cout<<"special ";
			print(data,type);
		}
		else
		{
			if(i%4==0 && j<dim)
			{
				fifo.Push(datl[j]);
				j++;
			}
			if(i%4==1 && k<dim)
			{
				fifo.Push(datd[k]);
				k++;
			}
			if(i%4==2 && l<dim)
			{
				fifo.Push(datc[l]);
				l++;
			}
			if(i%4==3 && m<dim)
			{
				fifo.Push(dats[m]);
				m++;
			}
		}
		i++;
	}
	data=fifo.Pop(&type);
	while(type!=-1)
	{
		print(data,type);
		data=fifo.Pop(&type);
	}
}
void stiva(void)
{
	void *data;
	int type;
	long dim=4;
	int i,j,k,l,m;
	CStack stack;
	i=0;j=0;k=0;l=0;m=0;
	while(j<dim || k<dim || l<dim || m<dim)
	{
		if((i+j+k)%5==0)
		{
			data=stack.Pop(&type);
			if(type!=-1) cout<<"special ";
			print(data,type);
		}
		else
		{
			if(i%4==0 && j<dim)
			{
				stack.Push(datl[j]);
				j++;
			}
			if(i%4==1 && k<dim)
			{
				stack.Push(datd[k]);
				k++;
			}
			if(i%4==2 && l<dim)
			{
				stack.Push(dats[l]);
				l++;
			}
			if(i%4==3 && m<dim)
			{
				stack.Push(datc[m]);
				m++;
			}
		}
		i++;
	}
	data=stack.Pop(&type);
	while(type!=-1)
	{
		print(data,type);
		data=stack.Pop(&type);
	}
}
int main(int argc, char* argv[])
{
//	stiva();
//	fifo();
//	mfifo();
//	dlist();
//	tree();
	sortari();
	return 0;
}
