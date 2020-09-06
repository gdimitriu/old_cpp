#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
class widget
{
public:
	widget() { cout<<"constructor\n";}
	virtual ~widget(){ cout<<"destructor\n";}
};

template<typename T> struct DeleteObject: public unary_function<const T*,void>
{
	void operator()(const T*ptr) const
	{
		delete ptr;
	}
};

struct DeleteObject2
{
	template<typename T> void operator()(const T *ptr) const
	{
		delete ptr;
	}
};

int main()
{
	ifstream dataFile("data.txt");
	list<int> data((istream_iterator<int>(dataFile)),istream_iterator<int>());
	ostream_iterator<int> output(cout," ");
	copy(data.begin(),data.end(),output);
	dataFile.close();
	cout<<endl;

	vector<widget *> _vwp;
	for(int i=0;i<5;++i)
		_vwp.push_back(new widget);
//	for(vector<widget *>::iterator i=_vwp.begin();i!=_vwp.end();++i)
//		delete *i;
//	for_each(_vwp.begin(),_vwp.end(),DeleteObject<widget>());
	for_each(_vwp.begin(),_vwp.end(),DeleteObject2());
	_vwp.clear();
}