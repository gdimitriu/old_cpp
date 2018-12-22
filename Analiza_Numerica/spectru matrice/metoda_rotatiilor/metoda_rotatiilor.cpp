// metoda_rotatiilor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream.h>
#include <math.h>
#include <string.h>
#include <memory.h>
void maximum(double **mat,long *max,long m)
{
	long i,j;
	double val=fabs(mat[0][1]);
	max[0]=0;
	max[1]=1;
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			if(i!=j && val<fabs(mat[i][j]))
			{
				val=fabs(mat[i][j]);
				max[0]=i;
				max[1]=j;
			}
}
int main(int argc, char* argv[])
{
	long m;
	long max[2];
	long i,j,k;
	double **A0;
	double *temp;
	double **T;
	double **A1;
	double theta;
	double tgtheta;
	double error;
	double norma,q;
	long itter;
	cout<<"Input the dimension of the matrix\n";
	cin>>m;
	cout<<"Input the error\n";
	cin>>error;
	A0=(double **)calloc(m,sizeof(double *));
	temp=(double *)calloc(m*m,sizeof(double));
	for(i=0;i<m;i++)
	{
		A0[i]=temp;
		temp+=m;
	}
	cout<<"Input the matrix\n";
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			cin>>A0[i][j];
	T=(double **)calloc(m,sizeof(double *));
	temp=(double *)calloc(m*m,sizeof(double));
	for(i=0;i<m;i++)
	{
		T[i]=temp;
		temp+=m;
	}
	A1=(double **)calloc(m,sizeof(double *));
	temp=(double *)calloc(m*m,sizeof(double));
	for(i=0;i<m;i++)
	{
		A1[i]=temp;
		temp+=m;
	}
	//we start the computation
	norma=0.0;
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			if(i!=j) norma+=A0[i][j]*A0[i][j];
	norma=sqrt(norma);
	q=sqrt(1.0-2.0/(m*m-m));
	maximum(A0,max,m);
	itter=0;
	while(error<pow(q,itter)*norma)
	{
		if(A0[max[0]][max[1]]!=A0[max[1]][max[1]])
		{
			tgtheta=2*A0[max[0]][max[1]]/(A0[max[0]][max[0]]-A0[max[1]][max[1]]);
			theta=atan(tgtheta)/2;
			for(i=0;i<m;i++) for(j=0;j<m;j++) T[i][j]=0.0;
			for(i=0;i<m;i++) T[i][i]=1.0;
			T[max[0]][max[1]]=-sin(theta);
			T[max[1]][max[0]]=sin(theta);
			T[max[0]][max[0]]=T[max[1]][max[1]]=cos(theta);
			//we do the multiplication (T*)*A0*T
			for(i=0;i<m;i++)
				for(j=0;j<m;j++)
				{
					A1[i][j]=0.0;
					for(k=0;k<m;k++)
						A1[i][j]+=T[k][i]*A0[k][j];
				}
			for(i=0;i<m;i++)
				for(j=0;j<m;j++)
				{
					A0[i][j]=0.0;
				for(k=0;k<m;k++)
					A0[i][j]+=A1[i][k]*T[k][j];
			}
			maximum(A0,max,m);
			itter++;
		}
	}
	cout<<"The spectrum of the matrix is\n";
	for(i=0;i<m;i++) cout<<A0[i][i]<<endl;
	free(*T);
	free(T);
	free(*A0);
	free(A0);
	free(*A1);
	free(A1);
	return 0;
}
