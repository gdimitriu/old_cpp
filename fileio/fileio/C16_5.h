#pragma once
#include <fstream>
using namespace std;

class C16_5
{
protected:
	ifstream *m_inputFile;
	ofstream *m_outputFile;
public:
	C16_5(void);
	~C16_5(void);
	int OpenFiles(char *inputFileName,char *outputFileName);
	int CopyAndConvert(void);
};

