#pragma once
#include <fstream>
using namespace std;
class CWeather
{
protected:
	ifstream *m_file;
	int m_day;
	int m_max;
	int m_min;
public:
	CWeather(void);
	~CWeather(void);
	int openFile(char *filename);
	void closeFile(void);
	int findAndPrintSmallSpread(void);
	void parseLine(string &line,int &day,int &max,int &min);
};

