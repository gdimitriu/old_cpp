#pragma once
#include <istream>
#include <fstream>
#include <ostream>
using namespace std;
//in fact this is the example 13_2
class C13_2
{
protected:
	ifstream *m_inFile;
	ofstream *m_outFile;
	int m_spaces;
public:
	C13_2(int spaces);
	C13_2(void);
	~C13_2(void);
	int OpenInFile(void);
	int CloseInFile(void);
	int OpenOutFile(void);
	int CloseOutFile(void);
	void CopyFile(void);
};

