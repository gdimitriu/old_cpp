#include "StdAfx.h"
#include "templateMain.h"
#include "TemplateArray.h"
#include "TemplateArrayRC.h"
#include <iostream>
#include <complex>


templateMain::templateMain(void)
{
}


templateMain::~templateMain(void)
{
}


template <class elemType>
	void swap(TemplateArray<elemType> &array,int i,int j)
{
	elemType tmp=array[i];
	array[i]=array[j];
	array[j]=tmp;
}

	enum Status
	{
	abc,
	cde
	};
	typedef std::string *Pstring;
void templateMain::run(void)
{
	const int array_size=4;
	//elemtype becomes int
	TemplateArray<int> ia(array_size);
	//elemType becomes double
	TemplateArray<double> da(array_size);
	//elemType bcomes char
	TemplateArray<char> ca(array_size);
	int ix;
	for(ix=0;ix<array_size;++ix)
	{
		ia[ix]=ix;
		da[ix]=ix*1.75;
		ca[ix]=ix+'a';
	}
	for(ix=0;ix<array_size;++ix)
	{
		std::cout<<"["<<ix<<"] ia: "<<ia[ix]<<"\tca: "<<ca[ix]<<"\tda: "<<da[ix]<<std::endl;
	}
	TemplateArrayRC<int> ia_rc(10);
	swap(ia,1,ia.size());
	swap(ia_rc,1,ia_rc.size());
	//tests
	
	//TemplateArray<int *&> pri(1024);
	//TemplateArray<TemplateArray<int>> aai(1024);
	TemplateArray<std::complex<double>> acd(1024);
	//TemplateArray<Status> as(1024);
	TemplateArray<Pstring> ap(1024);
}
