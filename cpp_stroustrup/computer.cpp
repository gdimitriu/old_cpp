#include "StdAfx.h"
#include "computer.h"
#include <iostream>
#include <sstream>
#include <string>
using std::string;

computer::computer(void)
{
	curr_tok=PRINT;
	no_of_errors=0;
	table["pi"]=3.14159265387932385;
	table["e"]=2.7182818284590452354;
}


computer::~computer(void)
{
}

/* this handle + and - */
double computer::expr(bool get)
{
	double left=term(get);
	for(;;)
	{
		switch (curr_tok){
		case PLUS:
			left+=term(true);
			break;
		case MINUS:
			left-=term(true);
			break;
		default:
			return left;
		}
	}
	return left;
}

/* this handle * / */
double computer::term(bool get)
{
	double left=prim(get);
	for(;;)
	{
		switch (curr_tok) {
		case MUL:
			left*=prim(true);
			break;
		case DIV:
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
double computer::prim(bool get)
{
	if(get) get_token();
	switch (curr_tok) {
		case NUMBER: //floating point constant
			{
				double v=number_value;
				get_token();
				return v;
			}
		case NAME:
			{
				double& v=table[string_value];
				if(get_token()==ASSIGN) v=expr(true);
				return v;
			}
		case MINUS: //unary minus
			return -prim(true);
		case LP:
			{
				double e=expr(true);
				if(curr_tok!=RP) return error(") expected");
				get_token(); //eat ')'
				return e;
			}
		default:
			return error("primary expected");
	}
}

computer::Token_value computer::get_token_orig(void)
{
	char ch=0;
	std::cin>>ch;
	switch(ch) {
	case 0:
		return curr_tok=END; //assign and return
	case ';':
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return curr_tok=Token_value(ch);
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '.':
		std::cin.putback(ch);
		std::cin>>number_value;
		return curr_tok=NUMBER;
	default: //NAME,NAME=, or error
		if(isalpha(ch)) {
			std::cin.putback(ch);
			std::cin>>string_value;
			return curr_tok=NAME;
		}
		error("bad token");
		return curr_tok=PRINT;
	}
	return PRINT;
}

computer::Token_value computer::get_token(void)
{
	char ch;
	do { //skip whitespace except '\n'
		if(!std::cin.get(ch)) return curr_tok=END;
	} while (ch!='\n' && isspace(ch));
	switch(ch){
	case ';':
	case '\n':
		return curr_tok=PRINT;
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return curr_tok=Token_value(ch);
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '.':
		std::cin.putback(ch);
		std::cin>>number_value;
		return curr_tok=NUMBER;
	default: //NAME,NAME=, or error
		if(isalpha(ch)) {
			string_value=ch;
			while(std::cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
			std::cin.putback(ch);
			return curr_tok=NAME;
		}
		error("bad token");
		return curr_tok=PRINT;
	}
	return PRINT;
}

int computer::error(const string& s)
{
	no_of_errors++;
	std::cerr<<"error: "<<s<<std::endl;
	return 1;
}


int computer::run(void)
{
	while(std::cin) {
		get_token();
		if(curr_tok==END) break;
		if(curr_tok==PRINT) continue;
		std::cout<<expr(false)<<std::endl;
	}
	return no_of_errors;
}


int computer::arguments(int argc, char* argv[])
{
	std::istream* input;
	switch(argc) {
	case 1:
		input=&std::cin;
		break;
	case 2:
		input=new std::istringstream(string(argv[1]),std::istringstream::in);
		break;
	default:
		error("too many arguments");
		return 1;
	}

	while(*input) {
		get_token();
		if(curr_tok==END) break;
		if(curr_tok==PRINT) continue;
		std::cout<<expr(false)<<std::endl;
	}
	if(input!=&std::cin) delete input;
	return no_of_errors;
}

/*
Allow a user to define functions in the calculator. Hint: Define a function as a sequence of
operations just as a user would have typed them. Such a sequence can be stored either as a
character string or as a list of tokens. Then read and execute those operations when the function
is called. If you want a userdefined
function to take arguments, you will have to invent a notation
for that.
Convert the desk calculator to use a s y m b o l structure instead of using the static variables
n u m b e r _ v a l u e and s t r i n g _ v a l u e .
*/
/*
Add functions such as s q r t (), l o g (), and s i n () to the desk calculator from §6.1. Hint:
Predefine the names and call the functions through an array of pointers to functions. Don’t forget
to check the arguments in a function call.
*/