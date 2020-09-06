/*
this is the class assoc from the 11.8 chapter
*/
#pragma once
#include <vector>
#include <iterator>
#include <iostream>
#include <string.h>
#include <functional>
using std::vector;
using std::pair;

template<class T1> class equal
{
public:
	bool operator()(const T1 &val1,const T1 &val2){return(val1==val2);}
};

template<> class equal<const char *>
{
public:
	bool operator()(const char * val1,const char * val2){ if(0==strcmp(val1,val2)) return(true);else return(false);}
};

template<class T1,class T2,class T3> class Assoc
{
public:
protected:
	T3 m_compare;
	Assoc(const Assoc&); //private to prevent copying
	Assoc& operator=(const Assoc&); //private to prevent copying
public:
	vector<pair<T1,T2>> m_vec; //for testing purpose
	Assoc(T3 cmp):m_compare(cmp){}
	T2& operator[](const T1&);
	void print_all() const;
	void clear(void);
	typedef typename pair<T1,T2> Pair;
};

template<class T1,class T2,class T3> void Assoc<T1,T2,T3>::clear(void)
{
	m_vec.clear();
}

template<class T1,class T2,class T3> T2& Assoc<T1,T2,T3>::operator[](const T1 &s)
{
	//search for s; return it's value if found; otherwise make a new Pair and return the default value 0
	for(vector<pair<T1,T2>>::iterator p=m_vec.begin();p!=m_vec.end();++p)
		if(m_compare(s,p->first)) return(p->second);
	m_vec.push_back(pair<T1,T2>(s,T2())); //initial value 0
	return m_vec.back().second; //return last element;
}

template<class T1,class T2,class T3> void Assoc<T1,T2,T3>::print_all(void) const
{
	for(vector<pair<T1,T2>>::const_iterator p=m_vec.begin();p!=m_vec.end();++p)
		std::cout<<p->first<<" : " <<p->second<<std::endl;
}
