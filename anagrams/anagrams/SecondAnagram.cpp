#include "SecondAnagram.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "ps.h"
using std::vector;
using std::copy;
using std::sort;
static FirstLess firstLess;
static FirstEqual firstEqual;
CSecondAnagram::CSecondAnagram(void)
{
}


CSecondAnagram::~CSecondAnagram(void)
{
}


void CSecondAnagram::run(void)
{
	std::cout<<"Anagram group finding program:\n"
		<<"finds all anagram groups in a dictionary.\n\n"
		<<std::flush;
	std::cout<<"First, enter the name of the file containing\n"
		<<"the dictionary: "<<std::flush;
	string dictionary_name;
	std::cin>>dictionary_name;
	std::ifstream ifs(dictionary_name.c_str());
	if(!ifs.is_open())
	{
		std::cout<<"Eh? Could not open file named "
			<<dictionary_name<<std::endl;
		exit(1);
	}
	std::cout<<"\nReading the dictionary ..."<<std::flush;
	typedef std::istream_iterator<string> string_input;
	vector<PS> word_pairs;
	copy(string_input(ifs),string_input(),std::back_inserter(word_pairs));
	std::cout<<"\nSearching "<<word_pairs.size()
		<<" words for anagram groups..."<<std::flush;
	//bring all anagram groups together
	sort(word_pairs.begin(),word_pairs.end(),firstLess);
	//prepare to output the anagram groups
	vector<PS>::const_iterator j=word_pairs.begin(),finis=word_pairs.end(),k;
	//output all of the anagram groups
	std::cout<<"\n\nThe anagram groups are:"<<std::endl;
	while(true)
	{
		//advance j to the start of the next anagram group (if any)
		j=std::adjacent_find(j,finis,firstEqual);
		//test for completion
		if(j==finis) break;
		//find the end position,k,of the anagram group that begins at j
		k=std::find_if(j+1,finis,not1(bind1st(firstEqual,*j)));
		//output the anagram group in position j to k
		std::cout<<" ";
		copy(j,k,std::ostream_iterator<string>(std::cout," "));
		std::cout<<std::endl;
		j=k;
	}
}


void CSecondAnagram::run_asfirst(void)
{
	std::cout<<"Anagram finding program:\n"
		<<"finds all words in a dictionary that can\n"
		<<"be formed with the letter of a given world.\n"<<std::endl;
	std::cout<<"First, enter the name of the file containing\n"
		<<"the dictionary: "<<std::flush;
	string dictionary_name;
	std::cin>>dictionary_name;
	std::ifstream ifs(dictionary_name.c_str());
	if(!ifs.is_open())
	{
		std::cout<<"Eh? Could not open file named "
			<<dictionary_name<<std::endl;
		exit(1);
	}
	std::cout<<"\nReading the dictionary ..."<<std::flush;
	typedef std::istream_iterator<string> string_input;
	vector<PS> word_pairs;
	copy(string_input(ifs),string_input(),std::back_inserter(word_pairs));
	std::cout<<"\nThe dictionary contains "
		<<word_pairs.size()<<" words.\n\n";
	std::cout<<"Now type a word (or any string of letters),\n"
		<<"and I'll see if it has any anagrams: "<<std::flush;
	//bring all anagram groups together
	sort(word_pairs.begin(),word_pairs.end(),firstLess);
	for(string_input strInput(std::cin);strInput!=string_input();++strInput)
	{
		string word=*strInput;
		sort(word.begin(),word.end());
		bool found_one=false;
		//iterators into the anagram groups
		vector<PS>::const_iterator j=word_pairs.begin(),finis=word_pairs.end(),k;
		//advance j to the start of the next anagram group (if any)
		j=std::adjacent_find(j,finis,firstEqual);
		while(j!=finis)
		{
			//find the end position,k,of the anagram group that begins at j
			k=std::find_if(j+1,finis,not1(bind1st(firstEqual,*j)));
			if(j->first==word)
			{
				//output the anagram group in position j to k
				copy(j,k,std::ostream_iterator<string>(std::cout," "));
				std::cout<<std::endl;
				found_one=true;
				break;
			}
			j=k;
		}
		if(!found_one)
			std::cout<<" Sorry, none found.\n";
		std::cout<<"\nType another word "
			<<"(or the end-of-file char to stop): "<<std::flush;
	}
}
