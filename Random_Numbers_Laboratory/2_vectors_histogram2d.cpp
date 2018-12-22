// 2_vectors_histogram2d.cpp : Defines the entry point for the console application.
//
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Random Numbers Laboratory.
	It generate 2 random vector given by their matrix corelation and makes 
	their histogram in 2D.
	It also generate a uniform multidimensional vector.

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

#include <stdlib.h>
#include <iostream.h>
#include <math.h>
double *z,*x;
double **sigma;
double **c;
double *temp;
int n,i,j,r;
double u;
double m;
double *generate1,*generate2;
int nr;

void uniformn() //uniform multidimensional vector
{
	double *v;
	int i;
	int n;
	double *a;
	double *b;
	cout<<"How many values do you have\n";
	cin>>n;
	cout<<"Give the values a and b\n";
	a=new double[n];
	b=new double[n];
	v=new double[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	for(i=0;i<n;i++)
		v[i]=a[i]+(b[i]-a[i])*rand()/(double)RAND_MAX;
	for(i=0;i<n;i++)
		cout<<v[i]<<endl;
	delete[] a;
	delete[] b;
	delete[] v;
}
void gauss() //gaussian multidimensional coralte by a matrix
{
	int i,j,r;
	for(i=0;i<n;i++)
		c[i][0]=sigma[i][0]/sigma[0][0];
	double dtemp;
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
		{
			if(j<i)
			{
				dtemp=0.0;
				for(r=0;r<j-1;r++) dtemp+=c[i][r]*c[j][r];
				c[i][j]=(sigma[i][j]-dtemp)/c[j][j];
			}
			if(j==i)
			{	
				dtemp=0.0;
				for(r=0;r<i-1;r++) dtemp+=c[i][r]*c[i][r];
				c[i][i]=sqrt(sigma[i][i]-dtemp);
			}
		}
	for(i=0;i<n;i++)
	{
		z[i]=0.0;
		for(j=0;j<12;j++) z[i]+=rand()/(double)RAND_MAX;
		z[i]-=6.0;
	}
	for(i=0;i<n;i++)
	{
		x[i]=0.0;
		for(j=0;j<n;j++)
			for(r=0;r<n;r++)
			{
				x[i]+=c[i][j]*z[j];
			}
		x[i]+=m;
	}
}
int main(int argc, char* argv[])
{
	cout<<"Input n\n";
	cin>>n;
	sigma=(double **)calloc(n,sizeof(double*));
	temp=(double *)calloc(n*n,sizeof(double));
	for(i=0;i<n;i++)
	{
		sigma[i]=temp;
		temp+=n;
	}
	z=new double[n];
	x=new double[n];
	c=(double **)calloc(n,sizeof(double*));
	temp=(double*)calloc(n*n,sizeof(double));
	for(i=0;i<n;i++)
	{
		c[i]=temp;
		temp+=n;
	}
	cout<<"Input sigma simetric and positive definite (corelation matrix)\n";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>sigma[i][j];
	cout<<"Input m\n";
	cin>>m;
	cout<<"Give the number of values nr=";
	cin>>nr;
	generate1=new double[nr];
	generate2=new double[nr];
	for(i=0;i<nr;i++) { generate1[i]=0; generate2[i]=0; }
	for(i=0;i<nr;i++)
	{
		gauss();
		generate1[i]=x[0];
		generate2[i]=x[1];
	}
	if(n==2)
	{
		double *intervals1,*intervals2;
		double max[2],min[2];
		int **relfreq;
		int *tempi;
		int innr;
		//here is the 2D histogram
		double step[2];
		cout<<"Give the number of desired intervals ";
		cin>>innr;
		intervals1=new double[innr];
		intervals2=new double[innr];
		relfreq=(int **)calloc(innr,sizeof(int*));
		tempi=(int*)calloc(innr*innr,sizeof(int));
		for(i=0;i<innr;i++)
		{
			relfreq[i]=tempi;
			tempi+=innr;
		}
		for(i=0;i<innr;i++)
			for(j=0;j<innr;j++) relfreq[i][j]=0;
		max[0]=generate1[0];
		min[0]=generate1[0];
		max[1]=generate2[0];
		min[1]=generate2[0];
		cout<<"By\n";cout.flush();
		for(i=0;i<nr;i++)
		{
			if(max[0]<generate1[i]) max[0]=generate1[i];
			if(min[0]>generate1[i]) min[0]=generate1[i];
			if(max[1]<generate2[i]) max[1]=generate2[i];
			if(min[1]>generate2[i]) min[1]=generate2[i];
		}
		intervals1[0]=min[0];
		intervals1[innr-1]=max[0];
		intervals2[0]=min[1];
		intervals2[innr-1]=max[1];
		step[0]=(max[0]-min[0])/(innr-1);
		step[1]=(max[1]-min[1])/(innr-1);
		for(i=1;i<innr-1;i++)
		{
			intervals1[i]=intervals1[i-1]+step[0];
			intervals2[i]=intervals2[i-1]+step[1];
		}
		int k;
		for(j=0;j<nr;j++)
		{
			for(i=1;i<innr;i++)
				if(intervals1[i-1]<generate1[j] && intervals1[i]>=generate1[j] )
				{
					for(k=1;k<innr;k++)
					{
						if(intervals2[k-1]<generate2[j] && intervals2[k]>=generate2[j] )
						{
							relfreq[i][k]++;
							break;
						}
					}
					break;
				}
		}
		cout<<"The histogram is\n";
		for(i=1;i<innr;i++)
		{
			cout<<"In ["<<intervals1[i-1]<<","<<intervals1[i]<<"]";
		}
		cout<<endl;
		for(i=1;i<innr;i++)
		{
			cout<<"["<<intervals2[i-1]<<","<<intervals2[i]<<"] ";
			for(j=1;j<innr;j++)
				cout<<relfreq[i][j]<<" ";
			cout<<endl;
		}
		free(*relfreq);
		free(relfreq);
		delete [] intervals1;
		delete [] intervals2;
	}
	free(*sigma);
	free(sigma);
	free(*c);
	free(c);
	delete []z;
	delete []x;
	return 0;
}
