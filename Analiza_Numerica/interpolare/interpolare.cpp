// interpolare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream.h>
#include<math.h>
double lagrange(double *x,double *f,long n,double x1)
{
	double temp,temp1;
	long i,j;
	temp=0.0;
	for(i=0;i<n;i++)
	{
		temp1=1.0;
		for(j=0;j<n;j++)
			if(j!=i) temp1*=(x1-x[j])/(x[i]-x[j]);
		temp+=f[i]*temp1;
	}
	return temp;
}
double deriv(double *x,double *f,long n,double x1)
{
	double temp;
	cout<<"Give the value of the derivate of the function in point "<<x1<<" of "<<n<<" order\n";
	cin>>temp;
	return temp;
}
double difdiv(double *x,double *f,long n1,long n2)
{
	double temp,temp1;
	long dif,i;
	if(n1==n2) return f[n1];
	if(fabs(x[n2]-x[n1])>1e-12) temp=(difdiv(x,f,n1+1,n2)-difdiv(x,f,n1,n2-1))/(x[n2]-x[n1]);
	else
	{
		dif=n2-n1+1;
		temp1=1.0;
		for(i=2;i<dif;i++) temp1=temp1*i;
		temp=1/temp1*deriv(x,f,dif-1,x[n1]);
	}
	return temp;
}
double delta(double *x,double *f,long i,double pas)
{
	double temp,temp1;
	long j;
	temp1=1.0;
	for(j=2;j<=i;j++) temp1=temp1*j;
	temp=pow(pas,i)*temp1*difdiv(x,f,0,i);
	return temp;
}
double echidistante(double *x,double *f,long n,double step,double pas)
{
	double temp,temp1,temp2;
	long i,j;
	temp=0.0;
	for(i=0;i<n;i++)
	{
		temp1=step;
		for(j=i-1;j>0;j--) temp1=temp1*(step-j);
		temp2=1.0;
		for(j=2;j<=i;j++) temp2*=j;
		temp=temp+(temp1/temp2)*delta(x,f,i,pas);
	}
	return temp;
}
int main(int argc, char* argv[])
{
	double *x;
	double *f;
	double x1;
	double pas;
	double val;
	long n;
	long n1;
	long i;
	cout<<"How many values do you have?\n";
	cin>>n;
	x=new double[n];
	f=new double[n];
/*	//lagrange
	cout<<"Input x,f\n";
	for(i=0;i<n;i++)
	{
		cout<<"x=";
		cin>>x[i];
		cout<<"f=";
		cin>>f[i];
	}*/
	//echidistante
	cout<<"Input x0 ";cin>>x[0];
	cout<<"Input pas ";cin>>pas;
	for(i=1;i<n;i++)
		x[i]=x[0]+i*pas;
	cout<<"Input function values\n";
	for(i=0;i<n;i++)
	{
		cout<<"f("<<x[i]<<")=";
		cin>>f[i];
	}
	cout<<"How many values do you want\n";
	cin>>n1;
	for(i=0;i<n1;i++)
	{
//		cout<<"X=";cin>>x1;
//		cout<<"F="<<lagrange(x,f,n,x1)<<endl;
		cout<<"Step of value=";cin>>val;
		cout<<"F="<<echidistante(x,f,n,val,pas)<<endl;
	}
	delete []x;
	delete []f;
	return 0;
}
