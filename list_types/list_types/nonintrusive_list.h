#include "intrusive_list.h"
#include "elem.h"

template<class T> class nonintrusive_list
{
private:
	intrusive_list m_list;
public:
	nonintrusive_list():m_list(){};
	void push_front(T value);
	void push_back(T value);
	T front(void);
	T back(void);
	T pop_back(void);
	T pop_front(void);
	int size(void) { return m_list.size();};
	~nonintrusive_list();
};


template<class T> void nonintrusive_list<T>::push_front(T value)
{
	Celem<T> *_element;
	_element=new Celem<T>(value);
	m_list.push_front(_element);
}

template<class T> void nonintrusive_list<T>::push_back(T value)
{
	Celem<T> *_element;
	_element=new Celem<T>(value);
	m_list.push_back(_element);
}

template<class T> T nonintrusive_list<T>::front(void)
{
	Celem<T> *_element;
	_element=static_cast<Celem<T> *>(m_list.front());
	return(_element->GetData());
}

template<class T> T nonintrusive_list<T>::back(void)
{
	Celem<T> *_element;
	_element=static_cast<Celem<T> *>(m_list.back());
	return(_element->GetData());
}

template<class T> T nonintrusive_list<T>::pop_back()
{
	Celem<T> *_element;
	T _temporary;
	_element=static_cast<Celem<T> *>(m_list.pop_back());
	_temporary=_element->GetData();
	delete _element;
	return _temporary;
}

template<class T> T nonintrusive_list<T>::pop_front()
{
	Celem<T> *_element;
	T _temporary;
	_element=static_cast<Celem<T> *>(m_list.pop_front());
	_temporary=_element->GetData();
	delete _element;
	return _temporary;
}

template<class T> nonintrusive_list<T>::~nonintrusive_list()
{
	Celem<T> *_element;
	for(int i=m_list.size();i>0;--i)
	{
		_element=static_cast<Celem<T> *>(m_list.pop_front());
		delete _element;
	}
}