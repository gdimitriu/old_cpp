#ifndef DC_LEXER_H
	#define DC_LEXER_H
	#include <string>
	#include <map>
	#include "Error.h"

	namespace Lexer {
		using std::string;
		using std::map;
		using Error::error;
		enum Token_value { NAME,NUMBER, END, PLUS='+', MINUS='-', MUL='*', DIV='/', PRINT=';', ASSIGN='=', LP='(', RP=')' };
		extern Token_value curr_tok;
		extern double number_value;
		extern string string_value;
		extern map<std::string,double> table;
		void init(void);
		Token_value get_token(void);
		Token_value get_token_orig(void);
	}
#endif