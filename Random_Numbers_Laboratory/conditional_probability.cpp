// histograma1.cpp : Defines the entry point for the console application.
//
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Random Numbers Laboratory.
	It generate a conditional probability vector.

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


int main(int argc, char* argv[])
{
	long *generate;
	double *probabilitati;
	double *cprob;
	long nr,nre;
	double genx;
	long *element;
	long innr,i,j,rnr;
	long *medie,*dispersie;

	cout<<"Give the number of elements\n";
	cin>>nre;
	element=new long[nre];
	innr=0;
	cout<<"Give the elements\n";
	for(i=0;i<nre;i++)
	{
		cin>>element[i];
		innr+=element[i];
	}
	probabilitati=new double[nre];
	for(i=0;i<nre;i++)
		probabilitati[i]=element[i]/(double)innr;
	cprob=new double[nre];
	generate=new long[nre];
	cprob[0]=probabilitati[0];
	for(i=1;i<nre;i++)
	{
		cprob[i]=cprob[i-1]+probabilitati[i];
	}
	cout<<"Give the number of runtime\n";
	cin>>nr;
	cout<<"Give the number of vectors\n";
	cin>>rnr;
	medie=new long[nre];
	dispersie=new long[nre];
	for(i=0;i<nre;i++) medie[i]=dispersie[i]=0;
	for(long k=0;k<rnr;k++)
	{
		for(i=0;i<nre;i++) generate[i]=0;
		for(j=0;j<nr;j++)
		{
			genx=(double)rand()/(double)RAND_MAX;
			for(i=0;i<nre;i++)
				if(genx<cprob[i]) break;
			generate[i]++;
		}
		for(i=0;i<nre;i++)
		{
			medie[i]+=generate[i];
			dispersie[i]+=generate[i]*generate[i];
		}
	}
	double *nprob;
	double *ndisp;
	nprob=new double[nre];
	ndisp=new double[nre];
	for(i=0;i<nre;i++)
	{
		nprob[i]=(double)medie[i]/(double)rnr;
		ndisp[i]=(double)dispersie[i]/(double)rnr-nprob[i]*nprob[i];
	}
	for(i=0;i<nre;i++)
		cout<<"prob orig "<<nr*probabilitati[i]<<" computing average "<<nprob[i]<<endl;
	return 0;
}
