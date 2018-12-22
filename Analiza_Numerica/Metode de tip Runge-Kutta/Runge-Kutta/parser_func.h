// parser_func.h: interface for the parser_func class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSER_FUNC_H__13461D80_C4F7_4B2D_8163_7774087898F5__INCLUDED_)
#define AFX_PARSER_FUNC_H__13461D80_C4F7_4B2D_8163_7774087898F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define DELIMITATOR 1
#define VARIABILA 2
#define NUMAR 3
#define FUNCTION 4
class parser_func  
{
public:
	double get_var(char var);
	void unset_var(char var);
	void set_var(char var,double val);
	void empty_vars();
	parser_func();
	virtual ~parser_func();
	void set_function(char *func);
	void eval_func(double *rez);
protected:
	char * get_argument(char *work);
	bool is_function;
	double eval_math(char *s);
	double find_var(char *s);
	long isdelim(char c);
	void serror(long error);
	void putback();
	void get_token(void);
	void atom(double *rez);
	void eval_func6(double *rez);
	void eval_func5(double *rez);
	void eval_func4(double *rez);
	void eval_func3(double *rez);
	void eval_func2(double *rez);
	void eval_func1(double *rez);
	char simb[80];
	char tip_simb;
	double *vars;
	char *prog;
	char *function;
	double (*math_f[13])(double arg);
};

#endif // !defined(AFX_PARSER_FUNC_H__13461D80_C4F7_4B2D_8163_7774087898F5__INCLUDED_)
