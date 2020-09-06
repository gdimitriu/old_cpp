/*
(*2.5) Implement a simple M a p class based on the A s s o c class from §11.8. Make sure M a p
works correctly using both Cstyle
strings and s t r i n g s as keys. Make sure M a p works correctly
for types with and without default constructors. Provide a way of iterating over the elements of
a M a p .
*/
#pragma once
#include"assoc.h"
#include <algorithm>
#include <functional>

template<class T1> class less
{
public:
	bool operator()(const T1 &val1,const T1 &val2){return(val1<val2);}
};

template<> class less<const char *>
{
public:
	bool operator()(const char * val1,const char * val2){ if(-1==strcmp(val1,val2)) return(true);else return(false);}
};

template<class T1,class T2,class T3,class T4> class Map : public Assoc<T1,T2,T3>
{
protected:
	bool equalPair(Pair& left,Pair& right)
	{
		return(m_compare(left.first,right.first));
	}
	bool lessPair(Pair left,Pair right)
	{
		return(m_less(left.first,right.first));
	}
	T4 m_less;
	template<typename T1,typename T2,typename T3>
	class _iterator
	{
	private:
		typename std::vector<Pair>::iterator m_position;
	public:
		_iterator(typename std::vector<Pair>::iterator it) : m_position(it){};
		_iterator& operator++()
		{
			++m_position;
			return(*this);
		}
		bool operator==(_iterator it)
		{
			return(m_position==it.m_position);
		}
		bool operator!=(_iterator it)
		{
			return!(*this==it);
		}
		_iterator(_iterator &it)
		{
			m_position=it.m_position;
		}
		Pair operator*()
		{
			return *m_position;
		}
	};
public:
	typedef Pair map_pair;
	typedef _iterator<T1,T2,T3> iterator;
	Map(T3 cmp,T4 less) : Assoc(cmp) {m_less=less;};
	void insert(T1 key,T2 val);
	void erase(T1 key);
	T2 find(T1 key);
	iterator begin(void)
	{
		return(iterator(m_vec.begin()));
	}
	iterator end(void)
	{
		return(iterator(m_vec.end()));
	}
	T2& operator[](const T1&);
};

template<class T1,class T2,class T3,class T4> T2 Map<T1,T2,T3,T4>::find(T1 key)
{
	std::vector<Pair>::iterator iter;
	Pair toInsert=Pair(key,0);
	iter=std::find_if(m_vec.begin(),m_vec.end(),std::bind(&Map<T1,T2,T3,T4>::equalPair,this,std::placeholders::_1,toInsert));
	if(iter!=m_vec.end())
		return (*iter).second;
	return T2(0);
}

template<class T1,class T2,class T3,class T4> void Map<T1,T2,T3,T4>::insert(T1 key,T2 val)
{
	std::vector<Pair>::iterator iter;
	Pair toInsert=Pair(key,val);
	iter=std::lower_bound(m_vec.begin(),m_vec.end(),toInsert,std::bind(&Map<T1,T2,T3,T4>::lessPair,this,std::placeholders::_1,std::placeholders::_2));
	if(iter==m_vec.end())
	{
		m_vec.push_back(toInsert);
		return;
	}
	m_vec.insert(iter,toInsert);
}

template<class T1,class T2,class T3,class T4> void Map<T1,T2,T3,T4>::erase(T1 key)
{
	std::vector<Pair>::iterator iter;
	Pair toDelete=Pair(key,0);
	iter=std::find_if(m_vec.begin(),m_vec.end(),std::bind(&Map<T1,T2,T3,T4>::equalPair,this,std::placeholders::_1,toDelete));
	if(iter==m_vec.end())
		return;
	m_vec.erase(iter);
	m_vec.shrink_to_fit();
}

template<class T1,class T2,class T3,class T4> T2& Map<T1,T2,T3,T4>::operator[](const T1& key)
{
	std::vector<Pair>::iterator iter;
	Pair toInsert=Pair(key,0);
	iter=std::lower_bound(m_vec.begin(),m_vec.end(),toInsert,std::bind(&Map<T1,T2,T3,T4>::lessPair,this,std::placeholders::_1,std::placeholders::_2));
	if(iter==m_vec.end())
	{
		m_vec.push_back(toInsert);
		return m_vec.back().second;
	}
	std::vector<Pair>::iterator insert_iter=iter;
	if(!m_compare((*iter).first,key))
		iter=m_vec.insert(insert_iter,toInsert);
	return((*iter).second);
}