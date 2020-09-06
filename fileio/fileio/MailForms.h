#pragma once
#include <fstream>
using namespace std;

class CMailForms
{
protected:
	ifstream *m_PersonsFile;
public:
	CMailForms(void);
	~CMailForms(void);
	int OpenFiles(char *inputPersonsFileName);
	int closeFile(void);
};

