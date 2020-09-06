/* Write a singlylinked list class template that accepts elements of any type derived from a
class L i n k that holds the information necessary to link elements. This is called an intrusive list.
Using this list, write a singlylinked list that accepts elements of any type (a nonintrusive
list). Compare the performance of the two list classes and discuss the tradeoffs between them.
*/
#include <iostream>

class Link
{
private:
	class Link *m_next;
public:
	Link(){m_next=NULL;}
	class Link *getNext() {return m_next;}
	void setNext(class Link *next) {m_next=next;}
	virtual ~Link(){};
};

template<class T> class list
{
private:
	Link *m_first;
public:
	list(){m_first=NULL;}
	~list(){}
	void add(T *element,int pos);
	T *get(int pos);
};

template<class T> void list<T>::add(T *element,int pos)
{
	Link *_local1,*_local2;
	if(_local2=dynamic_cast<Link*>(element))
	{
		_local2->setNext(NULL);
	}
	else
	{
		std::cout<<"not a derived class from Link"<<std::endl<<std::flush;
		return;
	}
	if(NULL==m_first)
	{
		m_first=_local2;
		return;
	}
	_local1=m_first;
	for(int i=0;i<pos;++i)
	{
		if(NULL==_local1->getNext())
		{
			_local1->setNext(_local2);
			return;
		}
		_local1=_local1->getNext();
	}
	_local2->setNext(_local1->getNext());
	_local1->setNext(_local2);
}

template<class T> T * list<T>::get(int pos)
{
	Link *_local1;
	_local1=m_first;
	if(NULL==_local1)
	{
		return NULL;
	}
	for(int i=0;i<pos;++i)
	{
		if(NULL==_local1->getNext())
		{
			return NULL;
		}
		_local1=_local1->getNext();
	}
	return _local1;
}