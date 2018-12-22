// vector_1d_histogram1d.cpp : Defines the entry point for the console application.
//
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Random Numbers Laboratory.
	It generate 1 dimensional random vector and make it's histogram.

    Random Numbers Laboratory is free software; you can redistribute it 
	and/or modify it under the terms of the GNU General Public License 
	as published by the Free Software Foundation; either version 2 of 
	the License, or (at your option) any later version.

    Random Numbers Laboratory is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Random Numbers Laboratory; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/
#include<iostream.h>
#include<stdlib.h>
#include<math.h>
#include<fstream.h>
void genrand(long nr,double *generate,int type,bool print)
{
	double inf,sup;
	double niu;
	double genu,geny;
	long i;
	switch(type)
	{
	case 0: //weibull
		{
			cout<<"Give niu"<<endl;
			cin>>niu;
			double maxx=pow(1/niu,1/(niu-1));
			double powm=pow(maxx,niu);
			for(i=0;i<nr;i++)
			{
				do
				{
					geny=pow(-log(rand()/(double)RAND_MAX),1/niu);
					genu=rand()/(double)RAND_MAX;
				}
				while(0<=genu && genu<=exp(-geny+pow(geny,niu)+maxx-powm));
				if(rand()/(double)RAND_MAX<0.5) generate[i]=geny;
				else generate[i]=-geny;
				if(print==true) cout<<generate[i]<<" ";
			}
			break;
		}
	case 1: //G(0,1)
		{
			for(i=0;i<nr;i++)
			{
				do
				{
					geny=log(rand()/(double)RAND_MAX);
					genu=rand()/(double)RAND_MAX;
				}
				while(0<=genu && genu<=exp(-geny*geny/2+geny-1/2));
				if(rand()/(double)RAND_MAX<0.5) generate[i]=geny;
				else generate[i]=-geny;
				if(print==true) cout<<generate[i]<<" ";
			}
			break;
		}
	case 2: //Gauss with LC
		{
			for(i=0;i<nr;i++)
			{
					for(int j=0;j<12;j++)
						generate[i]+=rand()/(double)RAND_MAX;
					generate[i]=generate[i]-6;
					if(print==true) cout<<generate[i]<<" ";
			}
			break;
		}
	case 3: //Uniform in a interval
		{
			cout<<"Give the interval"<<endl;
			cout<<"inf=";
			cin>>inf; //inf
			cout<<"sup=";
			cin>>sup; //sup 
			for(i=0;i<nr;i++)
			{
				generate[i]+=inf+(sup-inf)*rand()/(double)RAND_MAX; 
				if(print==true) cout<<generate[i]<<" ";
			}
			break;
		}
	default:
		{
		}
	}
}
int main(int argc, char* argv[])
{
	double *generate;
	double *intervals;
	long *relfreq;
	long nr;
	double max,min;
	long innr,i,j;
	long type;

	cout<<"Give the number of values nr=";
	cin>>nr;
	cout<<"Input the type of the elements:";
	cin>>type;
	generate=new double[nr];
	for(i=0;i<nr;i++) generate[i]=0;
	genrand(nr,generate,type,false);
	//from here we create the histogram for the generated numbers
	cout<<"Give the number of desired intervals ";
	cin>>innr;
	intervals=new double[innr];
	relfreq=new long[innr];
	for(i=0;i<innr;i++) relfreq[i]=0;
	max=generate[0];
	min=generate[0];
	for(i=0;i<nr;i++)
	{
		if(max<generate[i]) max=generate[i];
		if(min>generate[i]) min=generate[i];
	}
	intervals[0]=min;
	intervals[innr-1]=max;
	double step;
	step=(max-min)/(innr-1);
	for(i=1;i<innr-1;i++)
		intervals[i]=intervals[i-1]+step;
	for(j=0;j<nr;j++)
	{
		for(i=1;i<innr;i++)
			if(intervals[i-1]<generate[j] && intervals[i]>=generate[j] )
			{
				relfreq[i]++;
				break;
			}			
	}
	cout<<"The histogram is\n";
	for(i=1;i<innr;i++)
		cout<<"In ["<<intervals[i-1]<<","<<intervals[i]<<"] we have "<<relfreq[i]<<endl;
	delete []generate;
	delete []relfreq;
	delete []intervals;
	return 0;
}
