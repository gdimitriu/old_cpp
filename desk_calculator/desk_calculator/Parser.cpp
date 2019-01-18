#include "StdAfx.h"
#include "Parser.h"

/* this handle + and - */
double Parser::expr(bool get)
{
	double left=term(get);
	for(;;)
	{
		switch (curr_tok){
		case Lexer::PLUS:
			left+=term(true);
			break;
		case Lexer::MINUS:
			left-=term(true);
			break;
		default:
			return left;
		}
	}
	return left;
}

/* this handle * / */
double Parser::term(bool get)
{
	double left=prim(get);
	for(;;)
	{
		switch (curr_tok) {
		case Lexer::MUL:
			left*=prim(true);
			break;
		case Lexer::DIV:
			if(double d=prim(true)) {
				left/=d;
				break;
			}
			return error("divide by 0");
		default:
			return left;
		}
	}
	return left;
}


/* handles primaries */
double Parser::prim(bool get)
{
	if(get) get_token();
	switch (curr_tok) {
	case Lexer::NUMBER: //floating point constant
		{
			double v=Lexer::number_value;
			get_token();
			return v;
		}
	case Lexer::NAME:
		{
			double& v=Lexer::table[Lexer::string_value];
			if(get_token()==Lexer::ASSIGN) v=expr(true);
			return v;
		}
	case Lexer::MINUS: //unary minus
		return -prim(true);
	case Lexer::LP:
		{
			double e=expr(true);
			if(curr_tok!=Lexer::RP) return error(") expected");
			get_token(); //eat ')'
			return e;
		}
	default:
		return error("primary expected");
	}
}
