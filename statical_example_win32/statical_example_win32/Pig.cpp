#include "StdAfx.h"
#include "Pig.h"
#include <string.h>
#include <iostream>
using namespace std;

CPig::CPig(void)
{
	m_Name=NULL;
}


CPig::~CPig(void)
{
	if(m_Name!=NULL)
	{
		free(m_Name);
	}
	--m_NrOfInstances;
}
CPig::CPig(const char *name,int age)
{
	m_Name=(char *)calloc(strlen(name)+1,sizeof(char));
	strcpy_s(m_Name,(strlen(name)+1)*sizeof(char),name);
	m_Age=age;
	++m_NrOfInstances;
}
int CPig::NumberOfInstances(void)
{
	return m_NrOfInstances;
}
void CPig::PrintIndetifier(void)
{
	cout <<"Pig name="<<m_Name<<" has age="<<m_Age<<"\n";
}