#include "dlink.h"
#pragma once

class intrusive_dlist
{
protected:
	CDLink *m_front;
	CDLink *m_back;
public:
	intrusive_dlist(void) { m_front=m_back=NULL;};
	CDLink *front(void) { return m_front;};
	CDLink *back(void) { return m_back;};
	CDLink *pop_front(void);
	CDLink *pop_back(void);
	void push_front(CDLink *value);
	void push_back(CDLink *value);
	~intrusive_dlist(){};
	int size(void);
};