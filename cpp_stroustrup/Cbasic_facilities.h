#pragma once
#include <string>
using std::string;

class Cbasic_facilities
{
public:
	Cbasic_facilities(void);
	~Cbasic_facilities(void);
	void run(void);
	void cap5_11(void);
	void cap5_12(void);
	void cap6_03(void);
	void cap6_10(void);
	void cap6_12(void);
	void cap6_13(void);
	void cap6_14(void);
	void cap6_16(void);
	void cap6_17(void);
	void cap7_08(void);
	struct Tnode {
		string word;
		int count;
		Tnode * left ;
		Tnode * right ;
	};
	void cap7_07(void);
	void cap7_09(void);
	void cap7_11(void);
	void cap7_15(void);
	void cap7_19(void);
	void cap8_05(void);
};

