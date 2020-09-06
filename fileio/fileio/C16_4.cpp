#include "StdAfx.h"
#include "C16_4.h"
#include <fstream>
#include <iostream>

using namespace std;

C16_4::C16_4(void)
{
}


C16_4::~C16_4(void)
{
}


int C16_4::convertToBinary(char * inputFile, char * outputFile)
{
	long tempValue;
	m_inputFile= new ifstream(inputFile);
	if(m_inputFile->fail())
	{
		cout<<"Could not open the input file "<<inputFile<<endl;
		delete m_inputFile;
		m_inputFile=NULL;
		return -1;
	}
	m_outputFile=new ofstream(outputFile,ios::binary);
	if(m_outputFile->fail())
	{
		cout<<"Could not open the output file "<<outputFile<<endl;
		m_inputFile->close();
		delete m_inputFile;
		m_inputFile=NULL;
		m_outputFile->close();
		delete m_outputFile;
		m_outputFile=NULL;
		return -1;
	}
	while(!m_inputFile->eof())
	{
		(*m_inputFile)>>tempValue;
		m_outputFile->write((char *)&tempValue,sizeof(long));
	}
	m_inputFile->close();
	m_outputFile->close();
	delete m_inputFile;
	delete m_outputFile;
	return 0;
}


int C16_4::convertToText(char * inputFile, char * outputFile)
{
	long tempValue;
	m_inputFile= new ifstream(inputFile,ios::binary);
	if(m_inputFile->fail())
	{
		cout<<"Could not open the input file "<<inputFile<<endl;
		delete m_inputFile;
		m_inputFile=NULL;
		return -1;
	}
	m_outputFile=new ofstream(outputFile);
	if(m_outputFile->fail())
	{
		cout<<"Could not open the output file "<<outputFile<<endl;
		m_inputFile->close();
		delete m_inputFile;
		m_inputFile=NULL;
		m_outputFile->close();
		delete m_outputFile;
		m_outputFile=NULL;
		return -1;
	}
	while(!m_inputFile->eof())
	{
		m_inputFile->read((char *)(&tempValue),sizeof(long));
		if(m_inputFile->eof())
		{
			break;
		}
		(*m_outputFile)<<tempValue<<" ";
	}
	m_inputFile->close();
	m_outputFile->close();
	delete m_inputFile;
	delete m_outputFile;
	return 0;
}
