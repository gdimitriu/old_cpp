// cuadraturi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include <math.h>
double fct(double x)
{
	double fx;
	fx=exp(x)*cos(x*3.14)+exp(x)*sin(x)/x-x*log(x+3/x+cos(x));
//	fx=sin(x);
	return fx;
}
double trapez(double a,double b,double h)
{
	long n;
	long i;
	double x1,x2;
	double Tn;
	n=(long)((b-a)/h);
	Tn=0;
	for(i=0;i<n-1;i++)
	{
		x1=a+i*h;
		x2=a+(i+1)*h;
		Tn+=fct(x1)+fct(x2);
	}
	x1=x2;
	x2=b;
	Tn+=fct(x1)+fct(x2);
	Tn=Tn*h/2;
	return Tn;
}
double simpson(double a,double b,double h)
{
	long n,i;
	double x1,x2,x3;
	double Sn;
	n=(long)((b-a)/(2*h));
	Sn=0.0;
	for(i=0;i<n-1;i++)
	{
		x1=a+2*i*h;
		x2=a+(2*i+1)*h;
		x3=a+(2*i+2)*h;
		Sn+=(x3-x1)*(fct(x1)+4*fct(x2)+fct(x3));
	}
	x1=x2;
	x2=x3;
	x3=b;
	Sn+=(x3-x1)*(fct(x1)+4*fct(x2)+fct(x3));
	Sn=Sn/6;
	return Sn;
}
double gauss3(double a,double b,double h)
{
	double x,x1,sigma,v1,v2;
	long n,i;
	n=(b-a)/h;
	x=a;
	x1=a+h;
	sigma=0.0;
	for(i=0;i<n;i++)
	{
		v1=x1-x;
		v2=x1+x;
		sigma+=5.0/18.0*v1*fct(v2/2.0-v1/2.0*sqrt(3.0/5.0))+4.0/9.0*v1*fct(v2/2.0)+5.0*v1/18.0*fct(v2/2.0+v1/2.0*sqrt(3.0/5.0));
		x=x1;
		x1=x1+h;
	}
	return sigma;
}
double gauss5(double a,double b,double h)
{
	double x,x1,sigma,v1,v2;
	long n,i;
	n=(b-a)/h;
	x=a;
	x1=a+h;
	sigma=0.0;
	for(i=0;i<n;i++)
	{
		v1=x1-x;
		v2=x1+x;
		sigma+=v1/2*(0.2369*fct(v2/2.0+v1/2.0*0.9062)+0.4786*fct(v2/2.0+v1/2.0*0.5384)+0.5688*fct(v2/2.0)+0.47862*fct(v2/2.0-v1/2.0*0.5384)+0.23692*fct(v2/2.0-v1/2.0*0.90617));
		x=x1;
		x1=x1+h;
	}
	return sigma;
}
int main(int argc, char* argv[])
{
	double a,b,h;
	cout<<"Input the computing step\n";
	cin>>h;
	cout<<"Input the interval\n";
	cin>>a;
	cin>>b;
	cout<<"Tn="<<trapez(a,b,h)<<endl;
	cout<<"Sn="<<simpson(a,b,h)<<endl;
	cout<<"G3="<<gauss3(a,b,h)<<endl;
	cout<<"G5="<<gauss5(a,b,h)<<endl;
	return 0;
}
