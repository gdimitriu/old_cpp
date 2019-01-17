#include "StdAfx.h"
#include "CsA.h"
#include "CnodeSparse.h"
#include <iostream>

CsA::CsA(void)
{
	m_head=NULL;
}


CsA::~CsA(void)
{
	CnodeSparse *temporary;
	while(NULL!=m_head)
	{
		if(NULL!=m_head->m_next)
		{
			temporary=m_head;
			m_head=m_head->m_next;
			delete temporary;
		}
		else
		{
			delete m_head;
			m_head=NULL;
		}
	}
}

double &CsA::operator [] (unsigned long index)
{
	CnodeSparse *current;
	CnodeSparse *temporary;
	//if nothing is allocated
	if(NULL==m_head)
	{
		m_head=new CnodeSparse(index);
		return(m_head->m_value);
	}
	//if we are lucky and the required index is the first one
	if(index==m_head->m_index)
	{
		return(m_head->m_value);
	}
	//if the index is less than the smallest index from the sparse array
	if(index<m_head->m_index)
	{
		current=new CnodeSparse(index);
		current->m_next=m_head;
		m_head=current;
		return(m_head->m_value);
	}
	current=m_head;
	while(NULL!=current)
	{
		//if we had found the value
		if(current->m_index==index)
		{
			return (current->m_value);
		}
		//we had reach the final and the final is less than the required value
		if(NULL==current->m_next && current->m_index<index)
		{
			current->m_next=new CnodeSparse(index);
			return(current->m_next->m_value);
		}
		//the index is between two elements and does not exit before
		if(current->m_index<index && current->m_next->m_index>index)
		{
			temporary=new CnodeSparse(index);
			temporary->m_next=current->m_next;
			current->m_next=temporary;
			return(temporary->m_value);
		}
		current=current->m_next;
	}
	return(current->m_value);
}

void CsA::List(void)
{
	using namespace std;
	CnodeSparse *current;
	for(current=m_head;current!=NULL;current=current->m_next)
	{
		cout<<"at index="<<current->m_index<<" we have value="<<current->m_value<<endl;
	}
}
