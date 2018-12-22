#include"parser_func.cpp"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[])
{
	parser_func *parser;
	double *delta,a,b,h;
	char *dfunc;
	long n;
	double *x;
	double  v1,v2,v3,v4;
	long i;
	parser=new parser_func;
	dfunc=(char *)calloc(100,sizeof(char));
	printf("Introduceti pasul h=");
	scanf("%lf",&h);
	printf("Introduceti limita inferioara a intervalului\n");
	scanf("%lf",&a);
	printf("Introduceti limita superioara a intervalului \n");
	scanf("%lf",&b);
	n=(long)((b-a)/h)+1;
	x=(double *)calloc(n,sizeof(double));
	delta=(double *)calloc(n,sizeof(double));
	delta[0]=a;
	for(i=1;i<n;i++)
		delta[i]+=i*h;
	printf("Introduceti conditia initiala\n");
	scanf("%lf",&x[0]);
	printf("Introduceti functia cu t si y\n");
	fflush(stdin);
	dfunc=gets(dfunc);
	parser->set_function(dfunc);
	for(i=0;i<n-1;i++)
	{
		parser->set_var('t',delta[i]);
		parser->set_var('y',x[i]);
		parser->eval_func(&v1);
		parser->set_var('t',delta[i]+h/2);
		parser->set_var('y',x[i]+h*v1/2);
		parser->eval_func(&v2);
		parser->set_var('y',x[i]+h*v2/2);
		parser->eval_func(&v3);
		parser->set_var('t',delta[i+1]);
		parser->set_var('y',x[i]+h*v3);
		parser->eval_func(&v4);
		x[i+1]=x[i]+h*(v1+2*v2+2*v3+v4)/6;
	}
	printf("Valorile in diviziune\n");
	for(i=0;i<n;i++)
		printf("%lf ",x[i]);
	printf("\n");
	return 0;
}
