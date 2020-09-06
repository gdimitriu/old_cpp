/*
5. (*2) Define a s o r t () that takes its comparison criterion as a template argument. Define a class
R e c o r d with two data members c o u n t and p r i c e . Sort a v e c t o r <R e c o r d > on each data member.
*/
#include <iostream>
#include <vector>

using std::vector;

class Record
{
public:
	int count;
	int price;
};

bool compare_count(Record &first,Record &second)
{
	if(first.count<second.count)
		return false;
	return true;
}
template<class predicate,class rec> void sort_13_5(vector<rec> &vector_to_sort,predicate compare)
{
	rec _temp;
	rec _max;
	vector<rec>::iterator _position;
	for(vector<rec>::iterator i=vector_to_sort.begin();i!=vector_to_sort.end();++i)
	{
		_max=*i;
		_position=i;
		for(vector<rec>::iterator j=i+1;j!=vector_to_sort.end();++j)
		{
			if(false==compare(_max,*j))
			{
				_max=*j;
				_position=j;
			}
		}
		if(i!=_position)
		{
			_temp=*i;
			*i=*_position;
			*_position=_temp;
		}
	}
};