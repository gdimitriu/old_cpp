#pragma once
#include <string>
#include <map>
using std::string;
using std::map;
class computer
{
private:
	enum Token_value { NAME,NUMBER, END, PLUS='+', MINUS='-', MUL='*', DIV='/', PRINT=';', ASSIGN='=', LP='(', RP=')' };
public:
	computer(void);
	~computer(void);
protected:
	double expr(bool get);
	Token_value curr_tok;
	double term(bool get);
	double prim(bool get);
	double number_value;
	string string_value;
	Token_value get_token(void);
	Token_value get_token_orig(void);
	map<string,double> table;
	int error(const string& s);
	int no_of_errors;
public:
	int run(void);
	int arguments(int argc, char* argv[]);
};

