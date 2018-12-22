// vector_2d.cpp : Defines the entry point for the console application.
//
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Random Numbers Laboratory.
	It generates a 2 dimensional vector given by it's probability matrix.

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
#include<math.h>
#include<stdlib.h>


int main(int argc, char* argv[])
{
	double **probmat;
	double **yps;
	double *xp;
	double *x; //x vector
	double *y;//y vector
	double *temp;
	long xn,yn,i,j,k;
	cout<<"Input dimnesiunile \n";
	cout<<"dimY=un=)";
	cin>>yn;
	cout<<"dimX=xn=";
	cin>>xn;
	probmat=(double **)calloc(xn,sizeof(double *));
	temp=(double *)calloc(xn*yn,sizeof(double));
	for(i=0;i<xn;i++)
	{
		probmat[i]=temp;
		temp+=yn;
	}
	x=(double *)calloc(xn,sizeof(double));
	y=(double *)calloc(yn,sizeof(double));
	xp=(double *)calloc(xn,sizeof(double));
	yps=(double **)calloc(xn,sizeof(double *));
	temp=(double *)calloc(xn*yn,sizeof(double));
	for(i=0;i<xn;i++)
	{
		yps[i]=temp;
		temp+=yn;
	}
	cout<<"Input data X\n";
	for(i=0;i<xn;i++) cin>>x[i];
	cout<<"Input data Y\n";
	for(j=0;j<yn;j++) cin>>y[i];
	cout<<"Input probability matrix\n";
	for(i=0;i<xn;i++)
	{
		for(j=0;j<yn;j++)
		{
			cin>>probmat[i][j];
		}
	}
	for(i=0;i<xn;i++)
	{
		xp[i]=0.0;
		for(j=0;j<yn;j++)
			xp[i]=xp[i]+probmat[i][j];
	}
	cout<<"by x\n";cout.flush();
	for(i=1;i<xn;i++) xp[i]=xp[i-1]+xp[i]; //for prob
	for(i=0;i<xn;i++) cout<<xp[i]<<endl;cout.flush();
	for(i=0;i<xn;i++)
	{
		for(j=0;j<yn;j++)
			yps[i][j]=probmat[i][j]/xp[i];
		for(j=1;j<yn;j++)
			yps[i][j]=yps[i][j]+yps[i][j-1];
	}
	cout<<"Generate x\n";cout.flush();
	long nr;
	cout<<"How many run do you have\n";
	cin>>nr;
	double genx;
	for(k=0;k<nr;k++)
	{
		genx=(double)rand()/(double)RAND_MAX;
		for(i=0;i<xn;i++)
			if(genx<xp[i]) break;
		cout<<"X="<<x[i]<<endl;cout.flush();
		genx=(double)rand()/(double)RAND_MAX;
		for(j=0;j<yn;j++)
			if(genx<yps[i][j]) break;
		cout<<"Y="<<y[i]<<endl;cout.flush();
	}
	return 0;
}
