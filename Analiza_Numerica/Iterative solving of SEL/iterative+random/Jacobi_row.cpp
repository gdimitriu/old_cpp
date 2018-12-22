// Jacobi_row.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include <math.h>
#include <stdlib.h>
int jacobi_row(double **mat,double *va,double *xn,double err,long N)
/*
	returneaza 0 in caz de succes si -1 in caz de insucces.
	mat este matricea A, va este vectorul termenilor liber, xn este solutia
	err este eroarea cu care dorim sa calculam solutia sistemului
	N este dimensiunea sistemului
*/
{
	double *xn_1;
	double max,sum,q;
	long i,j,crt;
	double count;
	for(i=0;i<N;i++)
	{
		sum=0.0;
		for(j=0;j<N;j++) if(j!=i) sum+=fabs(mat[i][j]);
		if(fabs(mat[i][i])<sum)
		{
			cout<<"Sistemul nu poate fi rezolvat deoarece nu este dominant diagonal pe linii\n";
			return -1;
		}
	}
	xn_1=new double[N];
	//calculam q
	q=0.0;
	for(j=1;j<N;j++) q+=fabs(mat[0][j]/mat[0][0]);
	for(i=1;i<N;i++)
	{
		sum=0.0;
		for(j=0;j<N;j++) if(j!=i) sum+=fabs(mat[i][j]/mat[i][i]);
		if(q<sum) q=sum;
	}
	max=fabs(va[0]/mat[0][0]);
	for(i=1;i<N;i++) if(max<fabs(va[i]/mat[i][i])) max=fabs(va[i]/mat[i][i]);
	count=q*max/(1-q);
	for(i=0;i<N;i++) xn[i]=va[i]/mat[i][i];
	cout<<"q="<<q<<endl<<"max="<<max<<endl<<"count="<<fabs(count)<<endl;
	crt=0;
	while(fabs(count)>err)
	{
		for(i=0;i<N;i++) xn_1[i]=xn[i];
		for(i=0;i<N;i++)
		{
			xn[i]=va[i]/mat[i][i];
			for(j=0;j<N;j++) if(i!=j) xn[i]-=mat[i][j]/mat[i][i]*xn_1[j];
		}
		max=fabs(xn[0]-xn_1[0]);
		for(i=1;i<N;i++) if(max<fabs(xn[i]-xn_1[i])) max=fabs(xn[i]-xn_1[i]);
		count=q*max/(1-q);
		crt++;
	}
	//print the values
	cout<<"Dupa "<<crt<<" pasi avem solutia"<<endl;
	delete []xn_1;
	return 0;
}
int main(int argc, char* argv[])
{
	double **mat, *z,*xn,*va;
	double *temp,err;
	long i,j,N;
	double sum;
	char test;
	cout<<"Introduceti dimensiunea N=";cout.flush();cin>>N;
	cout<<"Introduceti eroarea, err=";cout.flush();cin>>err;
	/* alocam memoria */
	mat=(double **)calloc(N,sizeof(double *));
	temp=(double *)calloc(N*N,sizeof(double));
	for(i=0;i<N;i++)
	{
		mat[i]=temp;
		temp+=N;
	}
	z=new double[N];
	xn=new double[N];
	va=new double[N];
	cout<<"Doriti random sau manual (r/m)?\n";
	cin>>test;
	do
	switch(test)
	{
	case 'r':
	{
		/* generam matricea si implicit sistemul de ecuatii*/
		for(i=0;i<N;i++) z[i]=i+1; //generam solutia sistemului
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
				if(i!=j)
				{
					mat[i][j]=20000*rand()/(double)RAND_MAX;
					if((rand()/(double)RAND_MAX)<0.5) mat[i][j]=-mat[i][j];
				}
			}
		for(i=0;i<N;i++)
		{
			sum=0.0;
			for(j=0;j<N;j++) if(j!=i) sum+=fabs(mat[i][j]);
			//creem elementul diagonal
			mat[i][i]=sum+(20000+sum)*rand()/(double)RAND_MAX+0.00001;
			if((rand()/(double)RAND_MAX)<0.5) mat[i][i]=-mat[i][i];
		}
		//generam termenul liber
		for(i=0;i<N;i++)
		{
			va[i]=0.0;
			for(j=0;j<N;j++) va[i]+=mat[i][j]*z[j];
		}
		//print the matrix
		cout<<endl;
		cout<<"Doriti sa afisati matricea (y/n) ?";
		char test1;
		cin>>test1;
		if(test1=='y' || test1=='Y')
		{
			for(i=0;i<N;i++)
			{
				for(j=0;j<N;j++) cout<<mat[i][j]<<" ";
				cout<<"| "<<va[i]<<endl;
			}
			cout<<endl<<endl;
		}
		break;
	}
	case 'm':
	{
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				cin>>mat[i][j];
		cout<<"Introduceti vectorul termenilor liberi\n";
		for(i=0;i<N;i++) cin>>va[i];
		break;
	}
	default:
	{
		cout<<"Ati introdus gresit.\n";
		cout<<"Doriti random sau manual (r/m)?\n";
		cin>>test;
	}
	}
	while(test!='r' && test!='m');
	int solutie;
	solutie=jacobi_row(mat,va,xn,err,N);
	if(test=='m' && solutie==0)
		for(i=0;i<N;i++)
			cout<<"X["<<i<<"]="<<xn[i]<<endl;
	if(test=='r' && solutie==0)
		for(i=0;i<N;i++) if(fabs(xn[i]-z[i])>err) cout<<"eroare la "<<i<<"trebuia sa fie "<<z[i]<<"is este "<<xn[i];
	/* eliberam memoria */
	free(*mat);
	free(mat);
	delete []z;
	delete []xn;
	delete []va;
	return 0;
}
