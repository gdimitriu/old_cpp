#include "intrusive_list.h"

int intrusive_list::size(void)
{
	int count=0;
	for(CLink *i=m_first;i!=NULL;i=i->GetNext(),++count) /* this is left empty */;
	return count;
}

void intrusive_list::push_back(CLink *value)
{
	if(NULL==m_last)
	{
		m_first=m_last=value;
		return;
	}
	m_last->SetNext(value);
	m_last=value;
}

void intrusive_list::push_front(CLink *value)
{
	if(NULL==m_first)
	{
		m_first=m_last=value;
		return;
	}
	value->SetNext(m_first);
	m_first=value;
}

CLink *intrusive_list::pop_front(void)
{
	CLink *temp;
	//check if is empty
	if(NULL==m_first)
		return NULL;
	temp=m_first;	
	m_first=m_first->GetNext();
	if(NULL==m_first)
		m_last=NULL;
	return temp;
}

CLink *intrusive_list::pop_back(void)
{
	CLink *before_last;
	CLink *temp;
	//check if is empty
	if(NULL==m_first)
		return NULL;
	//check if we had only one element
	if(m_first==m_last)
	{
		temp=m_first;
		m_last=m_first=NULL;
		return temp;
	}
	for(CLink *i=m_first;i!=NULL;i=i->GetNext())
	{
		if(i->GetNext()==m_last)
		{
			before_last=i;
			break;
		}
	}
	temp=m_last;
	m_last=before_last;
	if(NULL==m_last)
		m_first=NULL;
	else
		m_last->SetNext(NULL);
	return temp;
}