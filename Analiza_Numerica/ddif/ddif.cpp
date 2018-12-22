// ddif.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream.h>
#include<math.h>
#include<stdlib.h>

long factorial(long val)
{
	if(val==0L) return 1L;
	else return val*factorial(val-1);
}

double fct(double t,double y)
{
	return t+y;
}

int main(int argc, char* argv[])
{
	double *delta;
	long n,n1;
	double *x,*x1,*x2;
	double  sum,sum2,sum1;
	double h,b,a;
	long i,j;
	double m;
	cout<<"Input the number of elements in division\n";
	cin>>n1;
	delta=(double *)calloc(n1,sizeof(double));
	x=(double *)calloc(n1,sizeof(double));
	cout<<"Input the division\n";
	for(i=0;i<n1;i++)
		cin>>delta[i];
	cout<<"Input the initial condition\n";
	cin>>x[0];
	for(i=1;i<n1;i++)
	{
		x[i]=x[i-1]+fct(delta[i-1],x[i-1])*(delta[i]-delta[i-1]);
	}
	cout<<"From now he have Euler-summed\n";
	free(delta);
	cout<<"Input h=";
	cin>>h;
	cout<<"Input  the initial condition\n";
	cin>>a;
	cout<<"Input the last value\n";
	cin>>b;
	n=(long)((b-a)/h)+1;
	x1=(double *)calloc(n,sizeof(double));
	x2=(double *)calloc(n,sizeof(double));
	delta=(double *)calloc(n,sizeof(double));
	delta[0]=a;
	for(i=1;i<n;i++)
		delta[i]+=i*h;
	x2[0]=a;
	sum1=fct(delta[0],x2[0]);
	for(i=1;i<n;i++)
	{
		sum=0;
		for(j=1;j<n;j++)
			sum+=pow(h,j)*fct(delta[i-1],x1[i-1])/factorial(j);
		x1[i]=x1[i-1]+sum;
		sum2=fct(delta[i-1]+h,x2[i-1]+h*sum1);
		x2[i]=x2[i-1]+(delta[i]-delta[i-1])*(sum2+sum1)/2;
		sum1=sum2;
	}
	cout<<"Values in division points for Euler\n";
	for(i=0;i<n1;i++)
		cout<<x[i]<<" ";
	cout<<endl;
	cout<<"Values in division points for Euler-summed\n";
	for(i=0;i<n;i++)
		cout<<x1[i]<<" ";
	cout<<endl;
	cout<<"Values in division points for Euler-Couchy\n";
	for(i=0;i<n;i++)
		cout<<x2[i]<<" ";
	cout<<endl;
	return 0;
}
