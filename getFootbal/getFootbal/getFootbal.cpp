// getFootbal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Cfootbal.h"
#include <iostream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string str("football.dat");
	Cfootbal foot(str);
	foot.parseFile();
	return 0;
}

