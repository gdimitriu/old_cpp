#include <functional>
#include <string>
#include <algorithm>
using std::pair;
using std::string;
using std::binary_function;
using std::sort;

struct PS:pair<string,string>
{
	PS(): pair<string,string>(string(),string()){}
	PS(const string& s): pair<string,string>(s,s)
	{
		sort(first.begin(),first.end());
	}
	operator string() const{return second;}
};
struct FirstLess : binary_function<PS,PS,bool>
{
	bool operator()(const PS& p,const PS& q) const
	{
		return p.first<q.first;
	}
};
struct FirstEqual: binary_function<PS,PS,bool>
{
	bool operator()(const PS& p,const PS& q) const
	{
		return p.first==q.first;
	}
};