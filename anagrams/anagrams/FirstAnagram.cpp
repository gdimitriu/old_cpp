#include "FirstAnagram.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

CFirstAnagram::CFirstAnagram(void)
{
}


CFirstAnagram::~CFirstAnagram(void)
{
}


void CFirstAnagram::run(void)
{
	cout<<"Anagram finding program:\n"
		<<"finds all words in a dictionary that can\n"
		<<"be formed with the letter of a given world.\n"<<endl;
	cout<<"First, enter the name of the file containing\n"
		<<"the dictionary: "<<flush;
	string dictionary_name;
	cin>>dictionary_name;
	ifstream ifs(dictionary_name.c_str());
	if(!ifs.is_open())
	{
		cout<<"Eh? Could not open file named "
			<<dictionary_name<<endl;
		exit(1);
	}
	cout<<"\nReading the dictionary ..."<<flush;
	typedef istream_iterator<string> string_input;
	vector<string> dictionary;
	copy(string_input(ifs),string_input(),back_inserter(dictionary));
	cout<<"\nThe dictionary contains "
		<<dictionary.size()<<" words.\n\n";
	cout<<"Now type a word (or any string of letters),\n"
		<<"and I'll see if it has any anagrams: "<<flush;
	sort(dictionary.begin(),dictionary.end());
	for(string_input j(cin);j!=string_input();++j)
	{
		string word=*j;
		sort(word.begin(),word.end());
		bool found_one=false;
		do
		{
			if(binary_search(dictionary.begin(),dictionary.end(),word))
			{
				cout<<" "<<word<<endl;
				found_one=true;
			}
		} while(next_permutation(word.begin(),word.end()));
		if(!found_one)
			cout<<" Sorry, none found.\n";
		cout<<"\nType another word "
			<<"(or the end-of-file char to stop): "<<flush;
	}
}
