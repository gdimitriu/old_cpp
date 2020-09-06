#include "StdAfx.h"
#include "Weather.h"
#include <iostream>

using namespace std;

CWeather::CWeather(void)
{
	m_file=NULL;
}


CWeather::~CWeather(void)
{
	close();
}


int CWeather::open(char * filename)
{
	m_file=new ifstream(filename);
	if(m_file->fail())
	{
		cout<<"Failed to open file="<<filename<<endl;
		return -1;
	}
	return 0;
}


void CWeather::close(void)
{
	if(m_file!=NULL)
	{
		m_file->close();
		delete m_file;
		m_file=NULL;
	}
}


int CWeather::DayWithSmallestSpread(void)
{
	char buffer[256];
	int temp_day;
	int temp_max;
	int temp_min;
	int temp_spread;
	//go the fist position into the file
	m_file->seekg(0,ios::beg);
	//get rid of header
	for(int i=0;i<8;++i)
		m_file->getline(buffer,sizeof(buffer));
	//read the first entry
	m_file->get(buffer,5);
	m_day=atoi(buffer);
	//read the second collumn
	m_file->get(buffer,5);
	//replace all unwanted characters
	for(int j=0;j<5;++j)
	{
		if((int)buffer[j]<48 || (int)buffer[j]>58)
		{
			buffer[j]=' ';
		}
	}
	m_max=atoi(buffer);
	//read the third collumn
	m_file->get(buffer,7);
	for(int j=0;j<7;++j)
	{
		if((int)buffer[j]<48 || (int)buffer[j]>58)
		{
			buffer[j]=' ';
		}
	}
	m_min=atoi(buffer);
	//get rid of the rest of the line
	m_file->getline(buffer,sizeof(buffer));
	memset(buffer,'\0',sizeof(buffer));
	temp_spread=m_max-m_min;
	//get the rest of the lines
	for(int i=1;i<30;++i)
	{
		m_file->get(buffer,5);
		temp_day=atoi(buffer);
		//read the second collumn
		m_file->get(buffer,5);
		//replace all unwanted characters
		for(int j=0;j<5;++j)
		{
			if((int)buffer[j]<48 || (int)buffer[j]>58)
			{
				buffer[j]=' ';
			}
		}
		temp_max=atoi(buffer);
		m_file->get(buffer,7);
		for(int j=0;j<7;++j)
		{
			if((int)buffer[j]<48 || (int)buffer[j]>58)
			{
				buffer[j]=' ';
			}
		}
		temp_min=atoi(buffer);
		if(temp_spread>(temp_max-temp_min))
		{
			temp_spread=temp_max-temp_min;
			m_max=temp_max;
			m_min=temp_min;
			m_day=temp_day;
		}
		//get rid of the rest of the line
		m_file->getline(buffer,sizeof(buffer));
		memset(buffer,'\0',sizeof(buffer));		
	}
	cout<<"day "<<m_day<<" has max="<<m_max<<" min="<<m_min<<endl;
	return m_day;
}
