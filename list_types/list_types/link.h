/* Write a singlylinked list class template that accepts elements of any type derived from a
class L i n k that holds the information necessary to link elements. This is called an intrusive list.
Using this list, write a singlylinked list that accepts elements of any type (a nonintrusive
list). Compare the performance of the two list classes and discuss the tradeoffs between them.
*/
#include <iostream>
#pragma once
class CLink
{
private:
	CLink *m_next;
public:
	CLink(){ m_next=NULL;};
	void SetNext(CLink *value){m_next=value;};
	CLink *GetNext(void){return m_next;};
};