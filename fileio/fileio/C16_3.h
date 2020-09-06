#pragma once
#include <fstream>
using namespace std;

class C16_3
{
protected:
	ifstream *m_inputFile;
	ofstream *m_output3File;
	ofstream *m_outputRestFile;
public:
	C16_3(void);
	~C16_3(void);
	void CloseFiles(void);
	int OpenFiles(char * inputFile, char * output3File, char * outputRestFile);
	void CreateFiles(void);
};

