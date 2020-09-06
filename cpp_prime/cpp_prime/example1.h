#pragma once
template <class elemType>
class example1
{
public:
	example1(elemType min,elemType max) {_mix=min; _max=max;};
	example1(const elemType *array, int size) {};
	elemType& operator[](int index){return parray[index];};
	bool operator==(const example1& ex) const {return true;};
	bool insert(const double* val,int poz) {return true;};
	bool insert(double val) {return true;};
	elemType min() const { return _min;};
	elemType max() const { return _max;};
	int count(elemType value) const {return 0;};
private:
	int size;
	elemType *parray;
	elemType _min;
	elemType _max;
};

