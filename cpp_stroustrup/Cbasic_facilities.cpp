#include "StdAfx.h"
#include "Cbasic_facilities.h"
#include <cstring>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using std::set;
using std::string;
using std::vector;
using std::basic_string;

Cbasic_facilities::Cbasic_facilities(void)
{
}


Cbasic_facilities::~Cbasic_facilities(void)
{
}


void Cbasic_facilities::run(void)
{
}

/*
Read a sequence of words from input. Use Quit as a word that terminates the input. Print
the words in the order they were entered. Don’t print a word twice. Modify the program to sort
the words before printing them.
*/
static void cap5_11_unsorted(void)
{
	string inputData;
	std::cin>>inputData;
	vector<string> storage;
	while(inputData!="Quit")
	{
		if(storage.end()==std::find(storage.begin(),storage.end(),inputData))
			storage.push_back(inputData);
		std::cin>>inputData;
	}
	for(vector<string>::iterator iter=storage.begin();iter!=storage.end();++iter)
		std::cout<<*iter<<std::endl;
	std::cout<<std::endl<<"sorted now"<<std::endl;
	std::sort(storage.begin(),storage.end());
	for(vector<string>::iterator iter=storage.begin();iter!=storage.end();++iter)
		std::cout<<*iter<<std::endl;
}

static void cap5_11_sorted(void)
{
	string inputData;
	set<string> storage;
	std::cin>>inputData;
	while(inputData!="Quit")
	{
		storage.insert(inputData);
		std::cin>>inputData;
	}
	for(set<string>::iterator iterator=storage.begin();iterator!=storage.end();++iterator)
		std::cout<<*iterator<<std::endl;
}

void Cbasic_facilities::cap5_11(void)
{
	cap5_11_unsorted();
}

/*
Write a function that counts the number of occurrences of a pair of letters in a string and
another that does the same in a zeroterminated array of char (a Cstyle string). For example,
the pair "ab" appears twice in "xabaacbaxabb".
*/
void Cbasic_facilities::cap5_12(void)
{
	string sInputString;
	string sToFind;
	std::cout << "Enter Input String like xabaacbaxabb" << std::endl;
	std::cin >> sInputString;
	std::cout << "Enter input pair to be found like ab" << std::endl;
	std::cin>>sToFind;
	basic_string<char>::size_type position=0;
	int number=0;
	// string based stl find
	while(position<sInputString.size())
	{
		position=sInputString.find(sToFind,position);
		if(position==basic_string<char>::npos)
		{
			break;
		}
		number++;
		position+=2;
	}
	std::cout<<"occurences string based="<<number<<std::endl;
	number=0;
	const char* const ccpcInputString=sInputString.c_str();
	const int ciLength=strlen(ccpcInputString);
	const char* const ccpcToFind=sToFind.c_str();
	int i=0;
	while(i<ciLength)
	{
		if(ccpcInputString[i]==ccpcToFind[0])
		{
			++i;
			if(ccpcInputString[i]==ccpcToFind[1])
			{
				++i;
				++number;
			}
		}
		else
		{
			++i;
		}
	}
	std::cout<<"occurences char based="<<number<<std::endl;
}

/*
Read a sequence of possibly whitespaceseparated(name,value) pairs, where the name is a single 
whitespace separated word and the value is an integer or a floatingpoint value. Compute and 
print the sum and mean for each  name and the sum and mean for all names.
*/
void Cbasic_facilities::cap6_03(void)
{
}

/*
Write these functions: strlen(), which returns the length of a Cstyle string; strcpy(),
which copies a string into another; and strcmp(), which compares two strings. Consider what
the argument types and return types ought to be. Then compare your functions with the standard
library versions as declared in <cstring > (<string.h>)
*/
static long my_strlen(const char *input)
{
	long length=0;
	const char *pIterator;
	for(pIterator=input;*pIterator!='\0';pIterator++)
		length++;
	return length;
}
static char *my_strcpy(char *destination,const char *source	)
{
	while(*destination++=*source++);
	return destination;
}
static int my_strcmp(const char *first,const char *second)
{
	const char *pIteratorFirst;
	const char *pIteratorSecond;
	for(pIteratorFirst=first,pIteratorSecond=second;*pIteratorFirst!='\0' && *pIteratorSecond!='\0';pIteratorFirst++,pIteratorSecond++)
	{
		if(*pIteratorFirst<*pIteratorSecond)
			return -1;
		if(*pIteratorFirst>*pIteratorSecond)
			return 1;
	}
	if(*pIteratorFirst=='\0' && *pIteratorSecond!='\0')
		return -1;
	if(*pIteratorFirst!='\0' && *pIteratorSecond=='\0')
		return 1;
	return 0;
}
void Cbasic_facilities::cap6_10(void)
{
	char* first="test a ";
	char* second="test b";
	std::cout<<"strlen testing"<<std::endl;
	assert(7==my_strlen(first));
	assert(6==my_strlen(second));
	std::cout<<"---OK."<<std::endl;
	std::cout<<"strcpy testing"<<std::endl;
	char *destination=new char[32];
	my_strcpy(destination,first);
	assert(strcmp(first,destination)==0);
	std::cout<<"---OK."<<std::endl;
	std::cout<<"strcmp testing"<<std::endl;
	char *one="aaaabbb";
	char *two="aaabbbb";
	char *three="aaaa";
	assert(strcmp(three,one)==-1);
	assert(strcmp(one,three)==1);
	assert(strcmp(one,two)==-1);
	assert(strcmp(two,one)==1);
	assert(strcmp(two,two)==0);

	assert(my_strcmp(three,one)==-1);
	assert(my_strcmp(one,three)==1);
	assert(my_strcmp(one,two)==-1);
	assert(my_strcmp(two,one)==1);
	assert(my_strcmp(two,two)==0);
	std::cout<<"---OK."<<std::endl;
}

/* modify the cap6_03 to compute also the median */

void Cbasic_facilities::cap6_12(void)
{
}

/*
Write a function cat() that takes two Cstyle
string arguments and returns a string that is
the concatenation of the arguments. Use new to find store for the result.
*/

static char *cat(const char *first,const char *second)
{
	char *result;
	long firstLength=0;//=strlen(first);
	const char *pIterator;
	for(pIterator=first;*pIterator!='\0';pIterator++)
	{
		firstLength++;
	}
	long secondLength=0;//strlen(second);
	for(pIterator=second;*pIterator!='\0';pIterator++){
		secondLength++;
	}
	long int overallLength=firstLength+secondLength+1;
	result=new char[overallLength];
	std::copy(first,first+firstLength,result);
	std::copy(second,second+secondLength+1,result+firstLength);
	return result;
}
void Cbasic_facilities::cap6_13(void)
{
	string first,second;
	getline(std::cin,first);
	getline(std::cin,second);
	std::cout<<first<<second<<std::endl;
	char *result=cat(first.c_str(),second.c_str());
	std::cout<<result;
}

/*
Write a function rev() that takes a string argument and reverses the characters in it. That
is, after rev(p) the last character of p will be the first, etc.
*/
static void rev(string &sInputString)
{
	char temp;
	long int iForward=0;
	long int iBackward=sInputString.length()-1;
	while(iForward<iBackward)
	{
		temp=sInputString.at(iForward);
		sInputString.at(iForward)=sInputString.at(iBackward);
		sInputString.at(iBackward)=temp;
		++iForward;
		--iBackward;
	}
}
void Cbasic_facilities::cap6_14(void)
{
	std::cout<<"rev for an even string"<<std::endl;
	string sTestInDataEven("qwerty");
	string sTestOutDataEven("ytrewq");
	rev(sTestInDataEven);
	assert(sTestInDataEven==sTestOutDataEven);
	std::cout<<"rev for an odd string"<<std::endl;
	string sTestInDataOdd("qwertyu");
	string sTestOutDataOdd("uytrewq");
	rev(sTestInDataOdd);
	assert(sTestInDataOdd==sTestOutDataOdd);
	std::cout<<"---OK."<<std::endl;
}

/*
Write a function atoi (const char *) that takes a string containing digits and returns the
corresponding int . For example, atoi ("123") is 123 . Modify atoi() to handle C++ octal and
hexadecimal notation in addition to plain decimal numbers. Modify atoi() to handle the C++ character
constant notation.
*/
void Cbasic_facilities::cap6_16(void)
{
}

/*
Write a function itoa(int i,char b[]) that creates a string representation of i in b and
returns b.
*/
void Cbasic_facilities::cap6_17(void)
{
}

/*
Write a function to invert a twodimensional array. hint C7.
*/
void Cbasic_facilities::cap7_08(void)
{
}

/*
Write a function for entering new words into a tree of Tnodes. Write a function to write out a
tree of Tnodes. Write a function to write out a tree of Tnodes with the words in alphabetical
order. Modify Tnode so that it stores (only) a pointer to an arbitrarily long word stored as an
array of characters on free store using new . Modify the functions to use the new definition of
Tnode .
*/
void Cbasic_facilities::cap7_07(void)
{
}

/*
Write an encryption program that reads from cin and writes the encoded characters to cout .
You might use this simple encryption scheme: the encrypted form of a character c is c^key[i],
where key is a string passed as a commandline argument. The program uses the characters in
key in a cyclic manner until all the input has been read. Reencrypting encoded text with the
same key produces the original text. If no key (or a null string) is passed, then no encryption is
done.
I will modify the program to not take the key from command line but from cin.
*/
/*
7_10 is 
Write a program to help decipher messages encrypted with the method described in
above without knowing the key. Hint: See David Kahn: The Codebreakers, Macmillan,
1967, New York, pp. 207213.
*/
static string encrypt(const string &sInput,const string &sKey)
{
	string sEncrypted;
	string::const_iterator iterKey=sKey.begin();
	for(string::const_iterator iter=sInput.begin();iter!=sInput.end();++iter)
	{		
		sEncrypted+=(*iter)^(*iterKey);
		++iterKey;
		if(iterKey==sKey.end())
			iterKey=sKey.begin();
	}
	return sEncrypted;
}
void Cbasic_facilities::cap7_09(void)
{
	string sInput="this is a string test";
	string sKey="god";
	std::cout<<"Encrypt-Decrypt"<<std::endl;
	string sEncrypted=encrypt(sInput,sKey);
	string sDecrypted=encrypt(sEncrypted,sKey);
	assert(sDecrypted==sInput);
	std::cout<<"---OK."<<std::endl;
}

/*
Write an error function that takes a printf style
format string containing %s , %c , and %d
directives and an arbitrary number of arguments. Don’t use printf(). Look at §21.8 if you
don’t know the meaning of %s , %c , and %d . Use <cstdarg>
*/
void Cbasic_facilities::cap7_11(void)
{
}

/*
Write a macro processor that defines and expands simple macros (like the C preprocessor
does). Read from cin and write to cout . At first, don’t try to handle macros with arguments.
Hint: The desk calculator contains a symbol table and a lexical analyzer that you could
modify.
*/
void Cbasic_facilities::cap7_15(void)
{
}

/*
Define a struct Date to keep track of dates. Provide functions that read Dates from
input, write Dates to output, and initialize a Date with a date.
Write functions to add one day, one month, and one year to a Date..
Write a function that gives the day of the week for a given Date . Write a function that gives the
Date of the first Monday following a given Date .
*/
void Cbasic_facilities::cap7_19(void)
{
}

/*
Write a program that throws an exception in one function and catches it in another.
*/
void Cbasic_facilities::cap8_05(void)
{
}
