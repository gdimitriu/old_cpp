#include "intrusive_dlist.h"

CDLink *intrusive_dlist::pop_front(void)
{
	CDLink *_temp;
	if(NULL==m_front)
		return(NULL);
	if(m_front!=m_back)
	{
		_temp=m_front;
		m_front=_temp->GetNext();
		m_front->SetPrevious(NULL);
		return(_temp);
	}
	_temp=m_front;
	m_front=m_back=NULL;
	return(_temp);
}

CDLink *intrusive_dlist::pop_back(void)
{
	CDLink *_temp;
	if(NULL==m_front)
		return(NULL);
	if(m_front==m_back)
	{
		_temp=m_front;
		m_front=m_back=NULL;
		return(_temp);
	}
	_temp=m_back;
	m_back=m_back->GetPrevious();
	m_back->SetNext(NULL);
	return(_temp);
}

void intrusive_dlist::push_back(CDLink *value)
{
	if(NULL==m_back)
	{
		m_back=m_front=value;
		value->SetNext(NULL);
		value->SetPrevious(NULL);
		return;
	}
	m_back->SetNext(value);
	value->SetPrevious(m_back);
	value->SetNext(NULL);
	m_back=value;
}

void intrusive_dlist::push_front(CDLink *value)
{
	if(NULL==m_back)
	{
		m_back=m_front=value;
		value->SetNext(NULL);
		value->SetPrevious(NULL);
		return;
	}
	m_front->SetPrevious(value);
	value->SetPrevious(NULL);
	value->SetNext(m_front);
	m_front=value;
}

int intrusive_dlist::size(void)
{
	int count=0;
	for(CDLink *i=m_front;m_front!=NULL;i=i->GetNext(),++count) /* left intentionally blank */;
	return(count);
}