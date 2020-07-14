#include "ForthAnagram.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <iterator>

using std::multimap;
using std::map;
using std::string;
using std::list;
using std::pair;
using std::greater;


CForthAnagram::CForthAnagram(void)
{
}


CForthAnagram::~CForthAnagram(void)
{
}


void CForthAnagram::run(void)
{
	typedef multimap<string,string> multimap_1;
	//define PS as multimap_1::value_type
	typedef multimap_1::value_type PS;
	typedef multimap_1::const_iterator PSi;
	typedef pair<PSi,PSi> PPS;
	std::cout<<"Anagram group finding program:\n"
		<<"finds all anagram groups in a dictionary.\n\n";
	//get the dictionary name and prepare to read it in
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
	std::cout<<"\nReading the dictionary...." <<std::flush;
	//copy words of dictionary into a multimap
	typedef std::istream_iterator<string> string_input;
	multimap_1 word_pairs;
	//copy the dictionary to the multimap
	for(string_input in(ifs);in!=string_input();++in)
	{
		string word=*in;
		sort(word.begin(),word.end());
		word_pairs.insert(PS(word,*in));
	}
	std::cout<<"\nSearching "<<word_pairs.size()
		<<" words for anagram groups..."<<std::flush;
	//set up the map from anagram group sizes ot lists of groups of that size
	typedef map<int,list<PPS>,greater<int>> map_1;
	map_1 groups;
	//find all the anagram groups and save thier positions in the groups map:
	std::cout<<"\n\nThe anagram groups are: "<<std::endl;
	//prepare to iterate through the multimap entries
	PSi j=word_pairs.begin(),finis=word_pairs.end(),k;
	while(true)
	{
		//make j point to the next anagram group, or to the end of the multimap:
		//find adjacent map entries than are equal
		j=std::adjacent_find(j,finis,not2(word_pairs.value_comp()));
		//test for completion
		if(j==finis) break;
		//find the end of a series of equal map entries
		k=std::find_if(j,finis,bind1st(word_pairs.value_comp(),*j));
		//get the size of the range of equal items and store the range
		multimap_1::size_type n=std::distance(j,k);
		if(n>1)
			//save the positions j and k delimiting the anagram group in the list of groups of size n:
			groups[n].push_back(PPS(j,k));
		//prepare to continue search at position k:
		j=k;
	}
	//iterate through the groups map to output the anagram groups in order of decreasing size
	map_1::const_iterator m;
	for(m=groups.begin();m!=groups.end();++m)
	{
		std::cout<<"\nAnagram groups of size "
			<<m->first<<":\n";
		list<PPS>::const_iterator l;
		for(l=m->second.begin();l!=m->second.end();++l)
		{
			std::cout<<"  ";
			//print the anagram groups
			j=l->first; //begining of the anagram group
			k=l->second; //end of the anagram group
			for(;j!=k;++j)
				std::cout<<j->second<<" ";
			std::cout<<std::endl;
		}
	}
}
