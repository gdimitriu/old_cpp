#include "StdAfx.h"
#include "Horse.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

CHorse::CHorse(void)
{
	m_Name=NULL;
	++m_NrOfInstances;
}


CHorse::~CHorse(void)
{
	if(m_Name!=NULL)
	{
		free(m_Name);
	}
}

CHorse::CHorse(const char *name,int age)
{
	m_Name=(char *)calloc(strlen(name)+1,sizeof(char));
	strcpy_s(m_Name,(strlen(name)+1)*sizeof(char),name);
	++m_NrOfInstances;
	m_Age=age;
}

int CHorse::NumberOfInstances(void)
{
	return m_NrOfInstances;
}
void CHorse::PrintIndetifier(void)
{
	cout<<"Horse name="<<m_Name<<" has age="<<m_Age<<"\n";
}