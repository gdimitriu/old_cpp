#include "ThirdAnagram.h"
#include "ps.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <list>
#include <functional>
#include <algorithm>
using std::vector;
using std::map;
using std::list;

typedef vector<PS>::const_iterator PSi;
typedef pair<PSi,PSi> PPS;
typedef map<int,list<PPS>,std::greater<int>> map_1;
static FirstLess firstLess;
static FirstEqual firstEqual;

CThirdAnagram::CThirdAnagram(void)
{
}


CThirdAnagram::~CThirdAnagram(void)
{
}


void CThirdAnagram::run(void)
{
	std::cout<<"Anagram group finding program:\n"
		<<"finds all anagram groups in a dictionary.\n\n"
		<<std::flush;
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
	//copy words from dictionary file to a vector of PS objects
	std::cout<<"\nReading the dictionary ..."<<std::flush;
	typedef std::istream_iterator<string> string_input;
	vector<PS> word_pairs;
	copy(string_input(ifs),string_input(),std::back_inserter(word_pairs));
	std::cout<<"\nSearching "<<word_pairs.size()
		<<" words for anagram groups..."<<std::flush;
	//bring all anagram groups together
	sort(word_pairs.begin(),word_pairs.end(),firstLess);
	//set up the map from group sizes to lists of groups of that size
	map_1 groups;
	//find all of the groups and save their positins in the groups map
	std::cout<<"\n\nThe anagram groups are"<<std::endl;
	PSi j=word_pairs.begin(),finis=word_pairs.end(),k;
	while(true)
	{
		//advance j to the start of the next anagram group if any
		j=std::adjacent_find(j,finis,firstEqual);
		//test for completion
		if(j==finis) break;
		//find the end position,k, of the anagram group that begins at j
		k=std::find_if(j+1,finis,not1(bind1st(firstEqual,*j)));
		//store the pair j,k in the groups map
		if(k-j>1)
		{
			//save the positions j and k delimiting the anagram
			//group in the list of groups of size k-j
			groups[k-j].push_back(PPS(j,k));
		}
		j=k;
	}
	//output the anagram groups in descending order of size
	map_1::const_iterator m;
	for(m=groups.begin();m!=groups.end();++m)
	{
		std::cout<<"\nAnagram groups of size "<<m->first<<":\n";
		list<PPS>::const_iterator l;
		for(l=m->second.begin();l!=m->second.end();++l)
		{
			std::cout<<" ";
			j=l->first; //begining of the anagram group
			k=l->second;//end of the anagram group
			copy(j,k,std::ostream_iterator<string>(std::cout," "));
			std::cout<<std::endl;
		}
	}
}
