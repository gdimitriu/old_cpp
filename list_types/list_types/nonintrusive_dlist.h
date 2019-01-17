#include "intrusive_dlist.h"
#include "delem.h"
#pragma once

template<class T> class nonintrusive_dlist
{
private:
	intrusive_dlist m_dlist;
public:
	nonintrusive_dlist(void):m_dlist(){ };
	int size(void) { return m_dlist.size();}
	T front(void);
	T back(void);
	void push_front(T value);
	void push_back(T value);
	T pop_front(void);
	T pop_back(void);
	~nonintrusive_dlist();
};

template<class T> T nonintrusive_dlist<T>::front(void)
{
	CDelem<T> *_elem;
	_elem=static_cast<CDelem<T> *>(m_dlist.front());
	return(_elem->GetData());
}

template<class T> T nonintrusive_dlist<T>::back(void)
{
	CDelem<T> *_elem;
	_elem=static_cast<CDelem<T> *>(m_dlist.back());
	return(_elem->GetData());
}

template<class T> T nonintrusive_dlist<T>::pop_back(void)
{
	CDelem<T> *_elem;
	T _value;
	_elem=static_cast<CDelem<T> *>(m_dlist.pop_back());
	_value=_elem->GetData();
	delete _elem;
	return(_value);
}

template<class T> T nonintrusive_dlist<T>::pop_front(void)
{
	CDelem<T> *_elem;
	T _value;
	_elem=static_cast<CDelem<T> *>(m_dlist.pop_front());
	_value=_elem->GetData();
	delete _elem;
	return(_value);
}

template<class T> void nonintrusive_dlist<T>::push_back(T value)
{
	CDelem<T> *_elem=new CDelem<T>(value);
	m_dlist.push_back(_elem);
}

template<class T> void nonintrusive_dlist<T>::push_front(T value)
{
	CDelem<T> *_elem=new CDelem<T>(value);
	m_dlist.push_front(_elem);
}

template<class T> nonintrusive_dlist<T>::~nonintrusive_dlist()
{
	CDelem<T> *_elem;
	_elem=static_cast<CDelem<T> *>(m_dlist.pop_front());
	while(_elem!=NULL)
	{
		delete _elem;
		_elem=static_cast<CDelem<T> *>(m_dlist.pop_front());
	}
}