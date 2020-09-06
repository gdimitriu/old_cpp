#include "StdAfx.h"
#include "C13_2.h"
#include <iostream>
#include <iomanip>

using namespace std;

C13_2::C13_2(int spaces)
{
	m_spaces=spaces;
}

C13_2::C13_2(void)
{
}


C13_2::~C13_2(void)
{
	CloseInFile();
	CloseOutFile();
}


int C13_2::OpenInFile(void)
{
	m_inFile=new ifstream("inputTabs.txt");
	if(m_inFile->fail())
	{
		cout<<"Could not open the file inputTabs.txt\n";
		delete m_inFile;
		m_inFile=NULL;
		return -1;
	}
	return 0;
}


int C13_2::CloseInFile(void)
{
	if(m_inFile!=NULL)
	{
		m_inFile->close();
		delete m_inFile;
		m_inFile=NULL;
	}
	return 0;
}


int C13_2::OpenOutFile(void)
{
	m_outFile=new ofstream("outputTabs.txt",ios::out);
	if(m_outFile->fail())
	{
		cout<<"failed to create the file outputTabs.txt\n";
		delete m_outFile;
		m_outFile=NULL;
		return -1;
	}
	return 0;
}


int C13_2::CloseOutFile(void)
{
	if(m_outFile!=NULL)
	{
		m_outFile->close();
		delete m_outFile;
		m_outFile=NULL;
	}
	return 0;
}


void C13_2::CopyFile(void)
{
	char ch;
	int position;
	if(!(NULL!=m_inFile && NULL!=m_outFile))
		return;
	position=0;
	while(false==m_inFile->eof())
	{
		m_inFile->get(ch);
		if(true==m_inFile->eof())
			break;
		if('\t'==ch)
		{
			for(int i=position;i <m_spaces;++i)
				m_outFile->put(' ');
			position=0;
		}
		else
		{
			m_outFile->put(ch);
			++position;
			if('\n'==ch)
				position=0;
			if(position>=m_spaces)
				position=0;
		}
	}
	return;
}
