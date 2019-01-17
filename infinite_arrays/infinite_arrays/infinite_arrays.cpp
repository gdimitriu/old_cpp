// infinite_arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CiA.h"
#include "CsA.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	CiA infinite_array;
	//set the value inside first bucket
	infinite_array[50]=50;
	//set the value outside the first bucket
	infinite_array[101]=101;
	//get the values
	cout<<"index 50 should have="<<infinite_array[50]<<endl;
	cout<<"index 101 should have="<<infinite_array[101]<<endl;
	unsigned int testIndexes[]={102,200,2000,3000,4000,22,2022,10120,2232};
	//set the test values
	for(int i=0;i<sizeof(testIndexes)/sizeof(int);++i)
	{
		infinite_array[testIndexes[i]]=testIndexes[i];
	}
	//get test the values and compare with realones
	int nr_errors=0;
	for(int i=0;i<sizeof(testIndexes)/sizeof(int);++i)
	{
		if(infinite_array[testIndexes[i]]!=testIndexes[i])
		{
			cout<<"Error testing at index="<<i<<" we have the value="<<infinite_array[testIndexes[i]]<<" instead="<<testIndexes[i]<<endl;
			++nr_errors;
		}
	}
	if(0!=nr_errors)
	{
		cout<<"we have "<<nr_errors<<"  errors\n";
	}
	cout<<"vector test for infinite_array is finished\n";

	CsA	*sparse_array;
	sparse_array=new CsA();
	(*sparse_array)[50]=50;
	(*sparse_array)[101]=101;
	//get the values
	cout<<"index 50 should have="<<(*sparse_array)[50]<<endl;
	cout<<"index 101 should have="<<(*sparse_array)[101]<<endl;
	//test with a sparse vector in which the value is equal to the index
	unsigned long testlong[]={1011,20,200,1730,17720,3732,3323};
	for(int i=0;i<sizeof(testlong)/sizeof(long);++i)
	{
		(*sparse_array)[testlong[i]]=testlong[i];
	}
	nr_errors=0;
	for(int i=0;i<sizeof(testlong)/sizeof(long);++i)
	{
		if((*sparse_array)[testlong[i]]!=testlong[i])
		{
			cout<<"error testing at index="<<i<<" we have the value="<<(*sparse_array)[testlong[i]]<<" instead of"<<testlong[i]<<endl;
			++nr_errors;
		}
	}
	if(0!=nr_errors)
	{
		cout<<"we have "<<nr_errors<<" errors\n";
	}
	cout<<"vector test for sparse vector is finished\n";
	//list the vector
	sparse_array->List();
	delete sparse_array;
	return 0;
}

