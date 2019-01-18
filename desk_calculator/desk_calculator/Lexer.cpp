#include "StdAfx.h"
#include <iostream>
#include "Lexer.h"
#include <map>
#include <string>

Lexer::Token_value Lexer::curr_tok;
double Lexer::number_value;
std::string Lexer::string_value;
std::map<std::string,double> Lexer::table;

void Lexer::init(void)
{
	curr_tok=PRINT;
	table["pi"]=3.14159265387932385;
	table["e"]=2.7182818284590452354;
}
Lexer::Token_value Lexer::get_token_orig(void)
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

Lexer::Token_value Lexer::get_token(void)
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
