#pragma once
#include <istream>
#include <fstream>
//in fact this is the example 16_1
using namespace std;
class C13_1
{
protected:
	ifstream *m_file;
	int m_count;
public:
	C13_1(void);
	~C13_1(void);
	int FileOpen(void);
	int countLines(void);
	int FileClose(void);
};

