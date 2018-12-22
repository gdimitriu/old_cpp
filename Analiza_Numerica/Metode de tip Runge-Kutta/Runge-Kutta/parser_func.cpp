// parser_func.cpp: implementation of the parser_func class.
//
//////////////////////////////////////////////////////////////////////

#include "parser_func.h"
#include <iostream.h>
#include<stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

parser_func::parser_func()
{
	vars=(double *)calloc(26,sizeof(double));
	prog=NULL;
	function=NULL;
	math_f[0]=cos;
	math_f[1]=acos;
	math_f[2]=sin;
	math_f[3]=asin;
	math_f[4]=tan;
	math_f[5]=atan;
	math_f[6]=cosh;
	math_f[7]=sinh;
	math_f[8]=tanh;
	math_f[9]=exp;
	math_f[10]=log;
	math_f[11]=log10;
	math_f[12]=fabs;
	is_function=false;
}

parser_func::~parser_func()
{
	if(vars!=NULL) free(vars);
	if(prog!=NULL) free(prog);
}

void parser_func::eval_func(double *rez)
//input point
{
	prog=function;
	get_token();
	if(!*simb)
	{
		serror(2);
		return;
	}
	eval_func1(rez);
	if(*simb) serror(0); //last simbol is null
}

void parser_func::eval_func1(double *rez)
//processing a atribution
{
	long fanta;
	char temp_simb[80],sseg_tip;
	
	if(tip_simb==VARIABILA)
	{
		//save the old simbol;
		strcpy(temp_simb,simb);
		sseg_tip=tip_simb;
		//computin the index of the variable
		fanta=toupper(*simb)-'A';
		get_token();
		if(*simb!='=')
		{
			putback();//return the curent segment
			//restore the old simbol without atributs
			strcpy(simb,temp_simb);
			tip_simb=sseg_tip;
		}
		else
		{
			get_token(); //get the next part of the expresion
			eval_func2(rez);
			vars[fanta]=*rez;
			return;
		}
	}
	eval_func2(rez);
}

void parser_func::eval_func2(double *rez)
//add or difference of two elements
{
	char op;
	double temp;
	
	eval_func3(rez);
	op=*simb;
	while(op=='+' || op=='-')
	{
		get_token();
		eval_func3(&temp);
		switch(op)
		{
		case '-':
			*rez=*rez-temp;
			break;
		case '+':
			*rez=*rez+temp;
			break;
		}
		op=*simb;
	}
}

void parser_func::eval_func3(double *rez)
//product or division of two elements
{
	char op;
	double temp;
	
	eval_func4(rez);
	while((op=*simb)=='*' || op=='/' || op=='%')
	{
		get_token();
		eval_func4(&temp);
		switch(op)
		{
		case '*':
			*rez=(*rez)*temp;
			break;
		case '/':
			*rez=(*rez)/temp;
			break;
		case '%':
			*rez=(long)*rez%(long)temp;
			break;
		}
	}
}

void parser_func::eval_func4(double *rez)
//process an exponent
{
	double temp,ex;
	eval_func5(rez);
	if(*simb=='^')
	{
		get_token();
		eval_func4(&temp);
		*rez=pow(*rez,temp);
	}
}

void parser_func::eval_func5(double *rez)
//eval + or - unary
{
	char op;
	op=0;
	if((tip_simb==DELIMITATOR) && *simb=='+' || *simb=='-')
	{
		op=*simb;
		get_token();
	}
	eval_func6(rez);
	if(op=='-') *rez=-(*rez);
}
 
void parser_func::eval_func6(double *rez)
//process parantheses expresion
{
	if(*simb=='(')
	{
		get_token();
		eval_func2(rez);
		if(*simb!=')')
			serror(1);
		get_token();
	}
	else atom(rez);
}

double parser_func::eval_math(char *s)
//evaluate a mathematical predefinite function
{
	double rez;
	int findex;
	if(strcmp(s,"cos")==0) //we have cos
		 findex=0;
	else if(strcmp(s,"acos")==0) //we have arccos
		findex=1;
	else if(strcmp(s,"sin")==0) //we have sin
		findex=2;
	else if(strcmp(s,"asin")==0) //we have arcsin
		findex=3;
	else if(strcmp(s,"tan")==0) //we have tangent
		findex=4;
	else if(strcmp(s,"atan")==0) //we have arctangent
		findex=5;
	else if(strcmp(s,"cosh")==0) //we have hiperbolic cosinus 
		findex=6;
	else if(strcmp(s,"sinh")==0) //we have hyperbolic sinus 
		findex=7;
	else if(strcmp(s,"tanh")==0) //we have hyperbolic tangent
		findex=8;
	else if(strcmp(s,"exp")==0) //we have exponential
		findex=9;
	else if(strcmp(s,"log")==0) //we have natural logarithm
		findex=10;
	else if(strcmp(s,"log10")==0) //we have 10 base logarithm
		findex=11;
	else if(strcmp(s,"fabs")==0) //we have absolute value
		findex=12;
	else findex=-1;
	char *argument;
	char *work;
	char old_tip_simb;
	old_tip_simb=tip_simb;	
	work=(char *)calloc(80,sizeof(char));
	argument=get_argument(work);
	eval_func(&rez);
	free(work);
	prog=argument;
	if(findex==-1)
		return 0.0;
	else return math_f[findex](rez);
}

void parser_func::atom(double *rez)
//read the value of the number or a variable
{
	switch(tip_simb)
	{
	case VARIABILA:
		*rez=find_var(simb);
		get_token();
		return;
	case NUMAR:
		*rez=atof(simb);
		get_token();
		return;
	case FUNCTION:
		*rez=eval_math(simb);
		get_token();
		return;
	default:
		serror(0);
	}
}

void parser_func::get_token()
//return the next simbol
{
	char *temp;
	tip_simb=0;
	temp=simb;
	*temp='\0';

	if(!prog) return; //end of expresion
	while(isspace(*prog)) ++prog;
	if(strchr("+-*/%^=()",*prog))
	{
		tip_simb=DELIMITATOR;
		*temp++=*prog++;
	}
	else if(isalpha(*prog) && !isalpha(*(prog+1)))
	{
		while(!isdelim(*prog)) *temp++=*prog++;
		tip_simb=VARIABILA;
	}
	else if(isalpha(*prog) && isalpha(*(prog+1)))
	{
		while(!isdelim(*prog)) *temp++=*prog++;
		tip_simb=FUNCTION;
	}
	else if(isdigit(*prog))
	{
		while(!isdelim(*prog)) *temp++=*prog++;
		tip_simb=NUMAR;
	}
	*temp='\0';
}

void parser_func::putback()
//return one simbol from the input flux
{
	char *s;
	s=simb;
	for(;*s;s++) prog--;
}

void parser_func::serror(long error)
//print a sintax error
{
	static char *e[]={
		"Sintax error",
		"Unbalance bracket",
		"Not an expresion"
	};
	cout<<e[error]<<endl;
}

double parser_func::find_var(char *s)
//return the value of a variable
{
	if(!isalpha(*s))
	{
		serror(1);
		return 0.0;
	}
	return vars[toupper(*simb)-'A'];
}

long parser_func::isdelim(char c)
//return 0 is c is a delimitator
{
	if(strchr(" +-/*%^=()",c) || c==9 || c=='\r' || c==0)
		return 1;
	return 0;
}

void parser_func::empty_vars()
//empty the variable memory
{
	if(vars!=NULL) free(vars);
	vars=(double *)calloc(26,sizeof(double));
}

void parser_func::set_var(char var, double val)
//set a variable to a value
{
	if(!isalpha(var))
	{
		serror(1);
		return;
	}
	vars[toupper(var)-'A']=val;
}

void parser_func::unset_var(char var)
//unset a variable
{
	if(!isalpha(var))
	{
		serror(1);
		return;
	}
	vars[toupper(var)-'A']=0.0;
}

double parser_func::get_var(char var)
//get a variable
{
	if(!isalpha(var))
	{
		serror(1);
		return 0.0;
	}
	return vars[toupper(var)-'A'];
}

void parser_func::set_function(char *func)
//set the function to the system
{
	if(function!=NULL) free(function);
	function=(char *)calloc(strlen(func)+1,sizeof(char));
	strcpy(function,func);
	prog=function;
}

char * parser_func::get_argument(char *work)
//get the argument of a predefined function
{
	char *temp;
	prog++;
	long i=0;
	long parantheses=1;
	while(parantheses!=0)
	{
		if(*prog=='(') parantheses++;
		if(*prog==')') parantheses--;
		if(parantheses==0) break;
		work[i]=*prog;
		i++;
		prog++;
	}
	prog++;
	temp=prog;
	prog=work;
	return temp;
}
