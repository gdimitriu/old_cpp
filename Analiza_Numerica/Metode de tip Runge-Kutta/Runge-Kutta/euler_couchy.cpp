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
	double  sum1,sum2;
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

	parser->set_var('t',delta[0]);
	parser->set_var('y',x[0]);
	parser->eval_func(&sum1);
	for(i=1;i<n;i++)
	{
		parser->set_var('t',delta[i-1]+h);
		parser->set_var('y',x[i-1]+h*sum1);
		parser->eval_func(&sum2);
		x[i]=x[i-1]+(delta[i]-delta[i-1])*(sum2+sum1)/2;
		sum1=sum2;
	}
	printf("Valorile in diviziune\n");
	for(i=0;i<n;i++)
		printf("%lf ",x[i]);
	printf("\n");
	return 0;
}
