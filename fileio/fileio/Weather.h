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
	int open(char * filename);
	void close(void);
	int DayWithSmallestSpread(void);
};

