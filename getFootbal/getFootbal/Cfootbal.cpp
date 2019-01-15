#include "StdAfx.h"
#include "Cfootbal.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


Cfootbal::Cfootbal(void)
{
}


Cfootbal::~Cfootbal(void)
{
	if(NULL!=m_inputfile)
		m_inputfile->close();
}

Cfootbal::Cfootbal(string &filename)
{
	m_inputfile=new ifstream(filename.data());
	if(m_inputfile->fail())
	{
		cout<<"Could not open the file "<<filename<<endl;
		m_inputfile=NULL;
	}
}

void Cfootbal::parseFile(void)
{
	char tempLine[1000];
	string seventh,eith;
	string team;
	string temp_str;
	int count_lines;
	int F,A;
	int diff;
	//parse the header
	for(int i=0;i<5;i++)
	{
		m_inputfile->getline(tempLine,sizeof(tempLine));
	}
	//parse the rest of file
	count_lines=5;
	while(false==m_inputfile->eof())
	{
		m_inputfile->getline(tempLine,sizeof(tempLine));
		//return if the end of file is reached or the </pre> which has 6 characters
		if(m_inputfile->eof() || 6==strlen(tempLine))
			break;
		//parse the line to find out the 7th and 8th column
		++count_lines;
		if(23!=count_lines)
		{
			temp_str.clear();
			temp_str=tempLine;
			seventh.clear();
			eith.clear();
			team.clear();
			team.append(temp_str,7,16);
			seventh.append(temp_str,39,6);
			eith.append(temp_str,48,4);
			F=atoi(seventh.data());
			A=atoi(eith.data());
			diff=abs(F-A);
			if(6==count_lines)
			{
				m_team=team;
				m_absdiff=diff;
				m_F=F;
				m_A=A;
				continue;
			}
			if(m_absdiff>diff)
			{
				m_absdiff=diff;
				m_team=team;
				m_F=F;
				m_A=A;
			}
		}
	}
	cout<<m_team<<" has the minimum diference="<<m_absdiff<<" with the scorecard "<<m_F<<" vs "<<m_A<<endl;
}
