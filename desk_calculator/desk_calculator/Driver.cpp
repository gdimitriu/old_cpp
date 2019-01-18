#include "StdAfx.h"
#include <iostream>
#include <sstream>
#include "Error.h"
#include "Lexer.h"
#include "Parser.h"
#include "Driver.h"

void Driver::init(void)
{
	Lexer::init();
	Error::init();
}

int Driver::run(void)
{
	while(std::cin) {
		Lexer::get_token();
		if(Lexer::curr_tok==Lexer::END) break;
		if(Lexer::curr_tok==Lexer::PRINT) continue;
		std::cout<<Parser::expr(false)<<std::endl;
	}
	return Error::get_nr_of_errors();
}


int Driver::arguments(int argc, char* argv[])
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
		Error::error("too many arguments");
		return 1;
	}

	while(*input) {
		Lexer::get_token();
		if(Lexer::curr_tok==Lexer::END) break;
		if(Lexer::curr_tok==Lexer::PRINT) continue;
		std::cout<<Parser::expr(false)<<std::endl;
	}
	if(input!=&std::cin) delete input;
	return Error::get_nr_of_errors();
}

