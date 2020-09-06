#include "StdAfx.h"
#include "test_lists.h"
#include <cassert>

class IntLink : public Link
{
private:
	int m_value;
public:
	IntLink(int value) : m_value(value){};
	~IntLink(){};
	int get(){ return m_value;}
};

void test()
{
	list<Link> ilist;
	IntLink *elem;
	ilist.add(new IntLink(1),0);
	ilist.add(new IntLink(2),1);
	elem=dynamic_cast<IntLink *>(ilist.get(0));
	assert(1==elem->get());
	elem=dynamic_cast<IntLink *>(ilist.get(1));
	assert(2==elem->get());
}