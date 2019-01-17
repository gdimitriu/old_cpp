
#include "link.h"
#pragma once
class intrusive_list
{
private:
	CLink *m_first;
	CLink *m_iterator;
	CLink *m_last;
public:
	intrusive_list() {m_first=NULL;m_iterator=NULL;m_last=NULL;};
	void push_back(CLink *);
	void push_front(CLink *);
	CLink *pop_back();
	CLink *pop_front();
	CLink *back() {return m_last;};
	CLink *front() { return m_first;};
	int size();
};
