#include"parser_func.cpp"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
parser_func *parser;
double *x;
long factorial(long val)
{
	if(val==0L) return 1L;
	else return val*factorial(val-1);
}
double derivata(double t,double y,double h,long ordin)
{
	double val1,val2;
	double valt,valy;
	double temp;
	if(ordin==0) return x[0];
	else if(ordin==1)
	{
		parser->set_var('t',t);
		parser->set_var('y',y);
		parser->eval_func(&val1);
		return val1;
	}
	else if(ordin==2)
	{
			parser->set_var('t',t+0.5*h);
			parser->set_var('y',y);
			parser->eval_func(&val1);
			parser->set_var('t',t-0.5*h);
			parser->set_var('y',y);
			parser->eval_func(&val2);
			valt=(val1-val2)/h;
			parser->set_var('y',y+0.5*h);
			parser->set_var('t',t);
			parser->eval_func(&val1);
			parser->set_var('y',y-0.5*h);
			parser->set_var('t',t);
			parser->eval_func(&val2);
			valy=(val1-val2)/h;
			parser->set_var('t',t);
			parser->set_var('y',y);
			parser->eval_func(&temp);
			valy=valy*temp;
			return valt+valy;
	}
	else
	{
			val1=derivata(t+0.5*h,y,h,ordin-1);
			val2=derivata(t-0.5*h,y,h,ordin-1);
			valt=(val1-val2)/h;
			val1=derivata(t,y+0.5*h,h,ordin-1);
			val2=derivata(t,y-0.5*h,h,ordin-1);
			valy=(val1-val2)/h;
			parser->set_var('t',t);
			parser->set_var('y',y);
			parser->eval_func(&temp);
			valy=valy*temp;
			return valt+valy;
	}
	return 0.0;
}
int main(int argc, char* argv[])
{
	double *delta;
	char *dfunc;
	long n,n1;
	double h;
	double sum;
	long i,j;
	parser=new parser_func;
	dfunc=(char *)calloc(100,sizeof(char));
	printf("Introduceti numarul de valori ale diviziunii\n");
	scanf("%ld",&n1);
	delta=(double *)calloc(n1,sizeof(double));
	x=(double *)calloc(n1,sizeof(double));
	printf("Introduceti diviziunea\n");
	for(i=0;i<n1;i++)
		scanf("%lf",&delta[i]);
	printf("Introduceti conditia initiala\n");
	scanf("%lf",&x[0]);
	printf("Introduceti parametrul n\n");
	scanf("%ld",&n);
	printf("Introduceti pasul derivatei\n");
	scanf("%lf",&h);
	printf("Introduceti functia cu t si y\n");
	fflush(stdin);
	dfunc=gets(dfunc);
	parser->set_function(dfunc);
	for(i=1;i<n1;i++)
	{
		sum=0.0;
		for(j=1;j<=n;j++)
			sum=sum+derivata(delta[i-1],x[i-1],h,j)*pow(delta[i]-delta[i-1],j)/factorial(j);
		x[i]=x[i-1]+sum;
	}
	printf("Valorile in diviziune\n");
	for(i=0;i<n1;i++)
		printf("%lf ",x[i]);
	printf("\n");
	return 0;
}
