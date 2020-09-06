#include "StdAfx.h"
#include "C16_5.h"
#include <iostream>

using namespace std;


C16_5::C16_5(void)
{
	m_inputFile=NULL;
	m_outputFile=NULL;
}


C16_5::~C16_5(void)
{
}


int C16_5::OpenFiles(char *inputFileName,char *outputFileName)
{
	//open the input file
	m_inputFile=new ifstream(inputFileName);
	if(m_inputFile->fail())
	{
		cout<<"Could not open the input file="<<inputFileName<<endl;
		delete m_inputFile;
		return -1;
	}
	//open the output file
	m_outputFile=new ofstream(outputFileName);
	if(m_outputFile->fail())
	{
		cout<<"Could not open the output file="<<outputFileName<<endl;
		m_inputFile->close();
		delete m_inputFile;
		delete m_outputFile;
		return -1;
	}
	return 0;
}


int C16_5::CopyAndConvert(void)
{
	char tempValue;
	if(NULL==m_inputFile)
		return -1;
	else if(NULL==m_outputFile)
		return -1;
	while(m_inputFile->eof()!=true)
	{
		tempValue=m_inputFile->get();
		if(m_inputFile->eof()==true)
			break;
		if((tempValue & 0x80)==0)
		{
			m_outputFile->put(tempValue);
		}
	}
	m_inputFile->close();
	m_outputFile->close();
	delete m_inputFile;
	delete m_outputFile;
	m_inputFile=NULL;
	m_outputFile=NULL;
	return 0;
}
