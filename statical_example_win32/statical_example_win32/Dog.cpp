#include "StdAfx.h"
#include "Dog.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

CDog::CDog(void)
{
	m_Name=NULL;
	++m_NrOfInstances;
}


CDog::~CDog(void)
{
	if(m_Name!=NULL)
	{
		free(m_Name);
	}
	--m_NrOfInstances;
}

CDog::CDog(const char *name,int age)
{
	m_Name=(char *)calloc(strlen(name)+1,sizeof(char));
	strcpy_s(m_Name,(strlen(name)+1)*sizeof(char),name);
	m_Age=age;
	++m_NrOfInstances;
}

int CDog::NumberOfInstances(void)
{
	return m_NrOfInstances;
}


void CDog::PrintIndetifier(void)
{
	cout<<"Dog name="<<m_Name<<" has age="<<m_Age<<"\n";
}
