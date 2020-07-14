// anagrams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FirstAnagram.h"
#include "SecondAnagram.h"
#include "ThirdAnagram.h"
#include "ForthAnagram.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CFirstAnagram firstAnagram;
	CSecondAnagram secondAnagram;
	CThirdAnagram thirdAnagram;
	CForthAnagram forthAnagram;
	forthAnagram.run();
	return 0;
}

