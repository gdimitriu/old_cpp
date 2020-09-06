#include "StdAfx.h"
#include "Football.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

CFootball::CFootball(void)
{
	m_file=NULL;
	m_A=0;
	m_F=0;
	m_difference=0;
}


CFootball::~CFootball(void)
{
	close();
}


int CFootball::open(char * filename)
{
	m_file=new ifstream(filename);
	//test if the file was correct opened
	if(m_file->fail())
	{
		cout<<"Error opening file="<<filename<<endl;
		return -1;
	}
	return 0;
}


void CFootball::close(void)
{
	if(m_file!=NULL)
	{
		m_file->close();
		delete m_file;
		m_file=NULL;
	}
}


string CFootball::getTeamWithMinimumSpread(void)
{
	char buffer[256];
	string temp_teamname;
	int temp_F;
	int temp_A;
	if(NULL==m_file)
	{
		return string();
	}
	//go the fist position into the file
	m_file->seekg(0);
	//get rid of the header
	for(int i=0;i<5;++i)
	{
		m_file->getline(buffer,sizeof(buffer));
	}
	memset(buffer,'\0',sizeof(buffer));
	//get the team
	m_file->get(buffer,8);
	m_file->get(buffer,17);
	m_team=buffer;
	memset(buffer,'\0',17);
	//get the F
	m_file->get(buffer,18);
	memset(buffer,'\0',18);
	m_file->get(buffer,7);
	m_F=atoi(buffer);
	memset(buffer,'\0',7);
	//get the A
	m_file->get(buffer,3);
	memset(buffer,'\0',3);
	m_file->get(buffer,5);
	m_A=atoi(buffer);
	//get rid of the rest of the line
	m_file->getline(buffer,sizeof(buffer));
	m_difference=abs(m_F-m_A);
	for(int i=0;i<20;++i)
	{
		memset(buffer,'\0',sizeof(buffer));
		if(16==i)
		{
			//get rid of --- line
			m_file->getline(buffer,sizeof(buffer));
			continue;
		}
		m_file->get(buffer,8);
		m_file->get(buffer,17);
		temp_teamname=buffer;
		memset(buffer,'\0',17);
		//get the F
		m_file->get(buffer,18);
		memset(buffer,'\0',18);
		m_file->get(buffer,7);
		temp_F=atoi(buffer);
		memset(buffer,'\0',7);
		//get the A
		m_file->get(buffer,3);
		memset(buffer,'\0',3);
		m_file->get(buffer,5);
		temp_A=atoi(buffer);
		//get rid of the rest of the line
		m_file->getline(buffer,sizeof(buffer));
		if(m_difference>abs(temp_A-temp_F))
		{
			m_team=temp_teamname;
			m_A=temp_A;
			m_F=temp_F;
			m_difference=abs(temp_A-temp_F);
		}
	}
	cout<<m_team<<" has F="<<m_F<<" and A="<<m_A<<endl;
	return m_team;
}
