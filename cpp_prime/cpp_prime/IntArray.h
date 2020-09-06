#pragma once
class IntArray
{
public:
	//constructors and destructors
	explicit IntArray(int sz=DefaultArraySize);
	IntArray(int *array,int array_size);
	IntArray(const IntArray &rhs);
	virtual ~IntArray() { delete []ia;}
	//quality and inequality operations
	bool operator==(const IntArray&) const;
	bool operator!=(const IntArray&) const;
	//assignment operator
	IntArray& operator=(const IntArray&);
	int size() const {return _size;}
	virtual void sort(void);
	virtual int min(void) const;
	virtual int max(void) const;
	//if the value is found within the array retur the index of its first occurence
	//otherwise return -1
	virtual int find(int value) const;
	//subscript operator
	virtual int& operator[](int index);
protected:
	void init(int sz,int *array);
	static const int DefaultArraySize=12;
	//internal data representation
	int _size;
	int *ia;
};

