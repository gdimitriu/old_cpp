#pragma once
#include <istream>
#include <string>

using namespace std;

class Cfootbal
{
protected:
	ifstream *m_inputfile;
	string m_team;
	int m_absdiff;
	int m_F,m_A;
public:
	Cfootbal(string &filename);
	Cfootbal(void);
	~Cfootbal(void);
	void parseFile(void);
};

