#include"parser_func.cpp"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[])
{
	parser_func *parser;
	double *delta;
	char *dfunc;
	long n,n1;
	double *x;
	char ctemp;
	double  val1,val2,temp;
	long i;
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
	printf("Introduceti functia cu t si y\n");
	fflush(stdin);
	dfunc=gets(dfunc);
	parser->set_function(dfunc);
	for(i=1;i<n1;i++)
	{
		parser->set_var('t',delta[i-1]);
		parser->set_var('y',x[i-1]);
		parser->eval_func(&temp);
		x[i]=x[i-1]+temp*(delta[i]-delta[i-1]);
	}
	printf("Valorile in diviziune\n");
	for(i=0;i<n1;i++)
		printf("%lf ",x[i]);
	printf("\n");
	return 0;
}
