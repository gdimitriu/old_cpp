#pragma once
#include <ostream>
template <class elemType>
class Example2
{
public:
	explicit Example2(elemType val=elemType()) : _val(val) {}
	bool min(elemType value) { return _val<value;}
	bool value(elemType new_val) {_val=new_val;}
	void print(std::ostream &os) { os<<_val;}
private:
	elemType _val;
};

template<class elemType> std::ostream& operator<<(std::ostream &os,Example2<elemType>& ex) { ex.print(os); return os; }
