// TreeStack.cpp: implementation of the CTreeStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TreeStack.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTreeStack::CTreeStack()
{
	m_top=NULL;
}

CTreeStack::~CTreeStack()
{
	CStackElem *parc;
	parc=m_top;
	while(m_top!=NULL)
	{
		m_top=parc->next;
		delete parc;
	}
}

void CTreeStack::Push(CNode *node)
{
	if(m_top==NULL)
	{
		m_top=new CStackElem();
		m_top->data=node;
	}
	else
	{
		CStackElem *parc=new CStackElem();
		parc->data=node;
		parc->next=m_top;
		m_top=parc;
	}
}

CNode * CTreeStack::Pop()
{
	CStackElem *parc;
	CNode *temp;
	if(m_top==NULL) return NULL;
	parc=m_top;
	temp=parc->data;
	m_top=parc->next;
	delete parc;
	return temp;
}

void CTreeStack::Empty()
{
	CStackElem *parc;
	parc=m_top;
	while(m_top!=NULL)
	{
		m_top=parc->next;
		delete parc;
	}
}

bool CTreeStack::IsEmpty()
{
	if(m_top==NULL)
		return true;
	else
		return false;
}
