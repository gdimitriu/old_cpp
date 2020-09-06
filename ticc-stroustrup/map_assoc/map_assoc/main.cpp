#include "assoc.h"
#include "assoc_map.h"
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
class Datatest
{
private:
	string m_data;
	explicit Datatest(){};
public:	
	Datatest(string val) : m_data(val){};
	void set(string& val){ m_data=val;}
	string get(void){ return m_data;}
	bool operator<(const Datatest& right) const
	{
		return m_data<right.m_data;
	}
	bool operator==(const Datatest& right) const
	{
		return m_data==right.m_data;
	}
};

void classtests(void)
{
//data for testing
	vector<string> _temp;
	_temp.push_back("aaa");
	_temp.push_back("a32");
	_temp.push_back("a1");
	_temp.push_back("a23");
	_temp.push_back("a23");
	_temp.push_back("a1");
//now the real class tests
	equal<Datatest> _equal;
	less<Datatest> _less;
	Map<Datatest,double,equal<Datatest>,less<Datatest>> map(_equal,_less);
//	Datatest _data;
	//put the data into the map
	for(vector<string>::const_iterator p=_temp.begin();p!=_temp.end();++p)
		map[Datatest(*p)]++;
	//-------------------------------------------------------------------
	Map<Datatest,double,equal<Datatest>,less<Datatest>>::iterator it=map.begin();
//	Map<Datatest,double,equal<Datatest>,less<Datatest>>::map_pair result;
	for(;it!=map.end();++it)
	{
		Map<Datatest,double,equal<Datatest>,less<Datatest>>::map_pair result=*it;
		std::cout<<"key="<<result.first.get()<<" value="<<result.second<<std::endl;
	}
}

void normaltests(void)
{
	equal<string> _cmp;
	Assoc<string,double,equal<string>> vec(_cmp);
	vector<string> _temp;
	_temp.push_back("aaa");
	_temp.push_back("a32");
	_temp.push_back("a1");
	_temp.push_back("a23");
	_temp.push_back("a23");
	_temp.push_back("a1");
	for(vector<string>::const_iterator p=_temp.begin();p!=_temp.end();++p)
		vec[*p]++;
	vec.print_all();
	std::cout<<"finished standard assoc"<<std::endl;

	equal<const char *> _cmpC;
	less<const char *> _lessC;
    Assoc<const char *,double,equal<const char *>> vecC(_cmpC);
	for(vector<string>::const_iterator p=_temp.begin();p!=_temp.end();++p)
		vecC[p->c_str()]++;
	vecC.print_all();
	std::cout<<"finished cstyle assoc"<<std::endl;
//-------------------------------------------------------------------------
	less<string> _less;
	Map<string,double,equal<string>,less<string>> map(_cmp,_less);
	for(vector<string>::const_iterator p=_temp.begin();p!=_temp.end();++p)
		map[*p]++;
/*	for(vector<Assoc<string,double,equal<string>>::Pair>::iterator iter=vec.m_vec.begin();iter!=vec.m_vec.end();++iter)
	{
		map.insert((*iter).m_key,(*iter).m_val);
	}
*/
//--------------------------------------------------------------------------
	map.print_all();
	std::cout<<"print using iterator"<<std::endl;
	Map<string,double,equal<string>,less<string>>::iterator it=map.begin();
//	Map<string,double,equal<string>,less<string>>::map_pair result;
	for(;it!=map.end();++it)
	{
		Map<string,double,equal<string>,less<string>>::map_pair result=*it;
		std::cout<<"key="<<result.first<<" value="<<result.second<<std::endl;
	}
//--------------------------------------------------------------------------
	std::cout<<"now delete the a23"<<std::endl;
	map.erase(string("a23"));
	map.print_all();
//--------------------------------------------------------------------------
	std::cout<<"find value a1="<<map.find(string("a1"))<<std::endl;
	std::cout<<"Finished standard map"<<std::endl;
    Map<const char *,double,equal<const char *>,less<const char *>>mapC(_cmpC,_lessC);
//	for(vector<string>::const_iterator p=_temp.begin();p!=_temp.end();++p)
//		mapC[p->c_str()]++;
	for(vector<Assoc<string,double,equal<string>>::Pair>::iterator iter=vec.m_vec.begin();iter!=vec.m_vec.end();++iter)
	{
		mapC.insert((*iter).first.c_str(),(*iter).second);
	}
	mapC.print_all();
	std::cout<<"find value a1="<<mapC.find("a1")<<std::endl;
	std::cout<<"finished cstyle map"<<std::endl;
}
int main()
{
	normaltests();
	classtests();
}
