#include "StdAfx.h"
#include "MailForms.h"
#include <iostream>
using namespace std;


CMailForms::CMailForms(void)
{
	m_PersonsFile=NULL;
}


CMailForms::~CMailForms(void)
{
	closeFile();
}

//this function is used to open the input file
//it will return -1 in case of errror
int CMailForms::OpenFiles(char *inputPersonsFileName)
{
	if(NULL!=m_PersonsFile)
	{
		m_PersonsFile->close();
		delete m_PersonsFile;
	}
	m_PersonsFile=new ifstream(inputPersonsFileName);
	if(NULL==m_PersonsFile)
	{
		return -1;
	}
	//see if the file was find and open correctly
	if(m_PersonsFile->fail())
	{
		cout<<"Could not open the input file "<<inputPersonsFileName<<endl;
		delete m_PersonsFile;
		m_PersonsFile=NULL;
		return -1;
	}
	return 0;
}


int CMailForms::closeFile(void)
{
	if(m_PersonsFile!=NULL)
	{
		m_PersonsFile->close();
		delete m_PersonsFile;
		m_PersonsFile=NULL;
	}
	return 0;
}
