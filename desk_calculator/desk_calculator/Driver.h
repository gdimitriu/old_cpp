#ifndef DC_DRIVER_H
	#define DC_DRIVER_H
	#include "Error.h"
	#include "Lexer.h"
	#include "Parser.h"

	namespace Driver {
		using std::string;
		int run(void);
		void init(void);
		int arguments(int argc, char* argv[]);
	}
#endif
