#ifndef DC_ERROR_H
	#define DC_ERROR_H
	#include <string>

	namespace Error {
		using std::string;
		int error(const string& s);
		int get_nr_of_errors(void);
		void init(void);
		extern int no_of_errors;
	}
#endif