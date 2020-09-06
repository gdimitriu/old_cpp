#include "StdAfx.h"
#include "C16_3.h"
#include <iostream>

using namespace std;

C16_3::C16_3(void)
{
}


C16_3::~C16_3(void)
{
	CloseFiles();
}


void C16_3::CloseFiles(void)
{
	if(m_inputFile!=NULL)
	{
		m_inputFile->close();
		delete m_inputFile;
		m_inputFile=NULL;
	}
	if(m_output3File!=NULL)
	{
		m_output3File->close();
		delete m_output3File;
		m_output3File=NULL;
	}
	if(m_outputRestFile!=NULL)
	{
		m_outputRestFile->close();
		delete m_outputRestFile;
		m_outputRestFile=NULL;
	}
}


int C16_3::OpenFiles(char * inputFile, char * output3File, char * outputRestFile)
{
	m_inputFile=new ifstream(inputFile);
	if(m_inputFile->fail())
	{
		cout<<"could not open input file="<<inputFile<<endl;
		delete m_inputFile;
		return -1;
	}
	m_output3File=new ofstream(output3File);
	if(m_output3File->fail())
	{
		cout<<"could not open output file="<<output3File<<endl;
		CloseFiles();
		return -1;
	}
	m_outputRestFile=new ofstream(outputRestFile);
	if(m_outputRestFile->fail())
	{
		cout<<"could not open output file="<<outputRestFile<<endl;
		CloseFiles();
		return -1;
	}
	return 0;
}


void C16_3::CreateFiles(void)
{
	long number;
	while(m_inputFile->eof()!=true)
	{
		(*m_inputFile)>>number;
		//if the number is divided by 3 write into the output3file
		if(0==number%3)
		{
			(*m_output3File)<<number<<" ";
		}
		//if the number is not divided by 3 write into the restfile
		else
		{
			(*m_outputRestFile)<<number<<" ";
		}
	}
}
