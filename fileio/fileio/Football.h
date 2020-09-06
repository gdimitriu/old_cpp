#pragma once
#include <fstream>
#include <string>
using namespace std;

class CFootball
{
protected:
	ifstream *m_file;
	string m_team;
	int m_F;
	int m_A;
	int m_difference;
public:
	CFootball(void);
	~CFootball(void);
	int open(char * filename);
	void close(void);
	string getTeamWithMinimumSpread(void);
};

