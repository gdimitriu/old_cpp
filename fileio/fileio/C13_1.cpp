#include "StdAfx.h"
#include "C13_1.h"
#include <iostream>

using namespace std;


C13_1::C13_1(void)
{
}


C13_1::~C13_1(void)
{
	FileClose();
}


int C13_1::FileOpen(void)
{
	m_file=new ifstream("test.txt");
	if(m_file->fail())
	{
		cerr<<"could not open file\n";
		delete m_file;
		m_file=NULL;
		return -1;
	}
	return 0;
}


int C13_1::countLines(void)
{
	char buffer[100];
	int m_count;
	m_count=0;
	while(false==m_file->eof())
	{
		m_file->getline(&buffer[0],sizeof(buffer));
		++m_count;
		cout<<buffer<<'\n';
	}
	cout<<"nr of lines is:"<<m_count<<"\n";
	return m_count;
}


int C13_1::FileClose(void)
{
	if(m_file!=NULL)
	{
		m_file->close();
		delete m_file;
	}
	m_file=NULL;
	return 0;
}
