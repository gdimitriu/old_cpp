// puteri.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<iostream.h>
#include<math.h>


int main(int argc, char* argv[])
{
	long N;
	long i,j,k;
	double *xn;
	double *x;
	double *z;
	double *z1;
	double norm1,norm2;
	double **A;
	double *temp;
	double error;
	cout<<"Give the dimension of space\n";
	cin>>N;
	xn=(double *)calloc(N,sizeof(double));
	x=(double *)calloc(N,sizeof(double));
	z=(double *)calloc(N,sizeof(double));
	z1=(double *)calloc(N,sizeof(double));
	A=(double **)calloc(N,sizeof(double *));
	temp=(double *)calloc(N*N,sizeof(double));
	for(i=0;i<N;i++)
	{
		A[i]=temp;
		temp+=N;
	}
	cout<<"Dati matricea simetrica si pozitiv definita\n";
	for(i=0;i<N;i++) for(j=0;j<N;j++) cin>>A[i][j];
	cout<<"Give the intitial vector\n";
	for(i=0;i<N;i++) cin>>x[i];
	//compute first
	norm1=0.0;
	for(i=0;i<N;i++) norm1+=x[i]*x[i];
	norm1=sqrt(norm1);
	cout<<norm1<<endl;
	for(i=0;i<N;i++) z[i]=x[i]/norm1;
	for(i=0;i<N;i++)
	{
		z1[i]=0.0;
		for(j=0;j<N;j++) z1[i]+=A[i][j]*z[j];
	}
	norm1=0.0;
	for(i=0;i<N;i++) norm1+=z1[i]*z1[i];
	norm1=sqrt(norm1); //we have lambda

	for(i=0;i<N;i++)
	{
		xn[i]=0.0;
		for(j=0;j<N;j++) xn[i]+=A[i][j]*x[j];
	}
	norm2=0.0;
	for(i=0;i<N;i++) norm2+=xn[i]*xn[i];
	norm2=sqrt(norm2);
	for(i=0;i<N;i++) z[i]=xn[i]/norm2;
	for(i=0;i<N;i++)
	{
		z1[i]=0.0;
		for(j=0;j<N;j++) z1[i]+=A[i][j]*z[j];
	}
	norm2=0.0;
	for(i=0;i<N;i++) norm2+=z1[i]*z1[i];
	norm2=sqrt(norm2);//we have another lambda
	cout<<norm1<<endl;
	cout<<norm2<<endl;
	cout<<"Give the error\n";
	cin>>error;
	while(fabs(norm2-norm1)>error)
	{
		norm2=norm1;
		for(i=0;i<N;i++) x[i]=xn[i];
		for(i=0;i<N;i++)
		{
			xn[i]=0.0;
			for(j=0;j<N;j++) xn[i]+=A[i][j]*x[j];
		}
		norm2=0.0;
		for(i=0;i<N;i++) norm2+=xn[i]*xn[i];
		norm2=sqrt(norm2);
		for(i=0;i<N;i++) z[i]=xn[i]/norm2;
		for(i=0;i<N;i++)
		{
			z1[i]=0.0;
			for(j=0;j<N;j++) z1[i]+=A[i][j]*z[j];
		}
		norm2=0.0;
		for(i=0;i<N;i++)
			norm2+=z[i]*z[i];
		norm2=sqrt(norm2);//we have another lambda
	}
	cout<<"Lambda="<<norm2<<endl;
	return 0;
}
