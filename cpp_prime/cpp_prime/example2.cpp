#include "StdAfx.h"
#include "example2.h"
#include <string>
#include <iostream>
#include "TemplateArray.h"

void testExample2(void)
{
		Example2<TemplateArray<int>*> ex1;
		TemplateArray<int> ex2;
		ex1.min(&ex2);
		Example2<int> sa(1024),sb;
		sa=sb;
		Example2<std::string> exs("Walden");
		std::cout<<"xs: "<<exs<<std::endl;
}