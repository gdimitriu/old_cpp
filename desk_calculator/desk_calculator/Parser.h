#ifndef DC_PARSER_H
	#define DC_PARSER_H
	#include "Lexer.h"

	namespace Parser {
		using Lexer::curr_tok;
		using Lexer::get_token;
		using Error::error;
		double expr(bool get);
		double term(bool get);
		double prim(bool get);
	}
#endif
