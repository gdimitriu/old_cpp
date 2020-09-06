#pragma once
#include <fstream>
using namespace std;
class C16_4
{
protected:
	ifstream *m_inputFile;
	ofstream *m_outputFile;
public:
	C16_4(void);
	~C16_4(void);
	int convertToBinary(char * inputFile, char * outputFile);
	int convertToText(char * inputFile, char * outputFile);
};

