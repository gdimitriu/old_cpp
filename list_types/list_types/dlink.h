/*
3. (*2.5) Write intrusive and nonintrusive doublylinked lists. What operations should be provided in addition to the ones you found necessary to 
supply for a singlylinked list?
*/
#include <iostream>
#pragma once

class CDLink
{
protected:
	CDLink *m_next;
	CDLink *m_previous;
public:
	CDLink(void){ m_next=NULL; m_previous=NULL;}
	CDLink *GetNext(void) { return m_next;};
	CDLink *GetPrevious(void) { return m_previous;};
	void SetNext(CDLink *next) { m_next=next;};
	void SetPrevious(CDLink *prev) { m_previous=prev;};
};