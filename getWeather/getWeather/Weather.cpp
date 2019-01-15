#include "StdAfx.h"
#include "Weather.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

CWeather::CWeather(void)
{
	m_file=NULL;
}


CWeather::~CWeather(void)
{
	closeFile();
}


int CWeather::openFile(char *filename)
{
	m_file=new ifstream(filename);
	if(m_file->fail())
	{
		cout<<"Could not open file="<<filename<<endl;
		delete m_file;
		m_file=NULL;
		return -1;
	}
	return 0;
}


void CWeather::closeFile(void)
{
	if(m_file!=NULL)
	{
		m_file->close();
		delete m_file;
		m_file=NULL;
	}
}


int CWeather::findAndPrintSmallSpread(void)
{
	string tmpline;
	char line[1000];
	int iterator;
	int day,max,min;
	if(NULL==m_file)
		return -1;
	//did we got the end of file from a previous find ?
	if(m_file->eof())
		m_file->seekg(0,ios_base::beg);
	//get rid of header
	for(iterator=0;iterator<8;++iterator)
		m_file->getline(line,sizeof(line),'\n');
	//get the 30 days
	m_file->getline(line,sizeof(line),'\n');
	tmpline=line;
	parseLine(tmpline,m_day,m_max,m_min);
	for(iterator=0;iterator<29;++iterator)
	{
		m_file->getline(line,sizeof(line),'\n');
		tmpline.clear();
		tmpline=line;
		parseLine(tmpline,day,max,min);
		if((max-min)<(m_max-m_min))
		{
			m_day=day;
			m_max=max;
			m_min=min;
		}
	}
	cout<<"day "<<m_day<<" has the max="<<m_max<<" and min="<<m_min<<endl;
	return m_day;
}


void CWeather::parseLine(string &line,int &day,int &max,int &min)
{
	string tmpString;
	tmpString.append(line,0,5);
	day=atoi(tmpString.data());
	tmpString.clear();
	tmpString.append(line,4,4);
	max=atoi(tmpString.data());
	tmpString.clear();
	tmpString.append(line,8,6);
	//replace the nonumerical cahracters
	for(int i=0;i<tmpString.size();++i)
	{
		if(tmpString[i]<48 || tmpString[i]>57)
		{
			tmpString[i]=' ';
		}
	}
	min=atoi(tmpString.data());
}
