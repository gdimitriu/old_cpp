#pragma once
template <class elemType> class TemplateArray
{
public:
	explicit TemplateArray(int size=DefaultArraySize);
	TemplateArray(elemType *array,int array_size);
	TemplateArray(const TemplateArray &rhs);
	virtual ~TemplateArray(void) {delete [] ia;}
	bool operator==(const TemplateArray&) const;
	bool operator!=(const TemplateArray&) const;
	TemplateArray& operator=(const TemplateArray&);
	int size() const {return _size;}
	virtual elemType& operator[](int index){ return ia[index];}
	virtual void sort();
	virtual elemType& min() const;
	virtual elemType& max() const;
	virtual int find(const elemType &value) const;
protected:
	static const int DefaultArraySize=12;
	int _size;
	elemType *ia;
private:
	void init(int sz,elemType *array);
};

template <class elemType>
void TemplateArray<elemType>::init(int sz,elemType *array)
{
	//set the data members
	_size=sz;
	ia=new elemType[_size];
	for(int ix=0;ix<_size;++ix)
	{
		if(!array)
			ia[ix]=0;
		else
			ia[ix]=array[ix];
	}
}

template <class elemType>
TemplateArray<elemType>::TemplateArray(int sz)
{
	init(sz,0);
}

template <class elemType>
TemplateArray<elemType>::TemplateArray(elemType *array,int sz)
{
	init(sz,array);
}

template <class elemType>
TemplateArray<elemType>::TemplateArray(const TemplateArray &rhs)
{
	init(rhs._size,rhs.ia);
}

template <class elemType>
void TemplateArray<elemType>::sort(void)
{

}

template <class elemType>
elemType& TemplateArray<elemType>::min(void) const
{
	return ia[0];
}

template <class elemType> 
elemType& TemplateArray<elemType>::max(void) const
{
	return ia[_size];
}

template <class elemType>
int TemplateArray<elemType>::find(const elemType &value) const
{
	for(int i=0;i<_size;++i)
	{
		if(ia[i]==value)
			return i;
	}
	return -1;
}
