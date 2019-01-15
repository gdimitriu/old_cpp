#include "StdAfx.h"
#include "ssort.h"
#include <iostream>
#include <cstring>
#include <functional>

struct User {
		char* name;
		char* id;
		int dept;
	};
User heads[]={
		"Ritchie D.M","dmr",11271,
		"Sethi R.","ravi",11272,
		"Szymanski T.G.","tgs",11273,
		"Schryer N.L.","nls",11274,
		"Schryer N.L.","nls",11275,
		"Kernighan B.W.","bwk",11276
};

static void print_id(User* v,int n)
{
	for(int i=0;i<n;++i)
		std::cout<<v[i].name<<'\t'<<v[i].id<<'\t'<<v[i].dept<<std::endl;
}
ssort::ssort(void)
{
}


ssort::~ssort(void)
{
}

void ssort::sort(void *base,size_t n,size_t sz, CFT cmp)
/*
	sort the "n" elements of vector "base" into increasing order
	using the comparison function pointed to by "cmp".
	The elements are of size "sz". Shell sort (Knuth, Vol3,pg84)
*/
{
	for(int gap=n/2;0<gap;gap/=2)
		for(unsigned int i=gap;i<n;++i)
			for(int j=i-gap;0<=j;j-=gap)
			{
				char* b=static_cast<char *>(base);	//necessary cast
				char* pj=b+j*sz;					//&base[j]
				char* pjg=b+(j+gap)*sz;				//&base[j+gap]
				if(cmp(pj,pjg)<0)	//swap base[j] and base[j+gap]
				{
					for(unsigned int k=0;k<sz;k++)
					{
						char temp=pj[k];
						pj[k]=pjg[k];
						pjg[k]=temp;
					}
				}
			}
}
static int cmp1(const void* p,const void* q)
{
	return strcmp(static_cast<const User *>(p)->name,static_cast<const User*>(q)->name);
}

static int cmp2(const void* p,const void *q)
{
	return static_cast<const User*>(p)->dept-static_cast<const User*>(q)->dept;
}

void ssort::run(void)
{
	std::cout<<"Heads in alphabetical order:\n";
	sort(heads,6,sizeof(User),cmp1);
	print_id(heads,6);
	std::cout<<"Heads in order of department number:\n";
	sort(heads,6,sizeof(User),cmp2);
	print_id(heads,6);
}
