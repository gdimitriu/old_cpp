// cpp_prime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "IntArray.h"
#include "IntArrayRC.h"
#include "TemplateArray.h"
#include "templateMain.h"
#include "generic_ex.h"
#include "JustLanguage.h"

static void swap(IntArray &ia,int i, int j)
{
	int tmp=ia[i];
	ia[1]=ia[j];
	ia[j]=tmp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int array[4]={0,1,2,3};
	IntArray ia1(array,4);
	IntArrayRC ia2(array,4);
	std::cout<<"swap() with IntArray ia1"<<std::endl;
	swap(ia1,1,ia1.size()-1);
	std::cout<<"swap() with InatArrayRC ia2"<<std::endl;
	swap(ia2,1,ia2.size()-1);

	templateMain templateEx;
//	templateEx.run();
//	generic_ex generic_example;
//	generic_example.run();
	JustLanguage lang;
	lang.run();
	return 0;
}

