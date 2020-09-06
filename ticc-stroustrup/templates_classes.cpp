// templates_classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
template <class T> T max(T t1,T t2)
{
	if(t1<t2)
		return t2;
	else
		return t1;
}
const int s=7;
inline int max(int i,int j) {return max<int>(i,j);}
inline double max(int i,double d){ return max<double>(i,d);}
inline double max(double d,int i) { return max<double>(d,i);}
inline double max(double d1,double d2) {return max<double>(d1,d2);}
void k()
{
	max(1,2);		//max<int>(1,2)
	max('a','b');	//max<char>('a','b')
	max(2.7,4.9);	//max<double>(2.7,4.9)
	max(s,7);		//max<int>(int(s),7) (trivial conversion used)
	max('a',1);
	max(2.7,4);
}



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

