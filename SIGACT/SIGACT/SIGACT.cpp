// SIGACT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iomanip>
using std::map;
using std::multiset;
using std::string;

typedef map<string,string> data_map;
//<define a function object to compare persons based on date of the Ph.D>
struct earlier: std::binary_function<string,string,bool>
{
	bool operator()(const string& name1,const string& name2) const{ return dates[name1]<dates[name2];}
	static data_map dates; //dates[name] holds year in which Pd.d degree was granted to name
	static data_map places; //places[name] holds institution that granted Ph.D
};

data_map earlier::dates;
data_map earlier::places;

//<define multiset containing strings ordered by dates>
typedef multiset<string,earlier> date_ordered_mset;
//<define a map from strings to date_ordered_msets>
typedef map<string,date_ordered_mset> relation_map;
//<function to output a single branch of the tree, rooted at name>
void output_tree(const string& name,relation_map& students,data_map& places,data_map& dates,int identation_level=0)
{
	//<<ident the line according to the identation level>
	for(int k=0;k!=identation_level;++k)
		std::cout<<"     ";
	//<print the students's Ph.D degree information>
	std::cout<<name<<" ("<<places[name]<<" "<<dates[name]<<")"<<std::endl;
	//<print this person's students, indented one additional level>
	date_ordered_mset& L=students[name];
	date_ordered_mset::const_iterator j;
	for(j=L.begin();j!=L.end();++j)
		output_tree(*j,students,places,dates,identation_level+1);
}
//<function to get a string of all the characters up to next terminator>
void get_chunk(std::istream& in,string& s,char terminator='\t')
{
	s.erase(s.begin(),s.end());
	s.reserve(20);
	string::value_type ch;
	while(in.get(ch) && ch!=terminator)
		s.insert(s.end(),ch);
}


int _tmain(int argc, _TCHAR* argv[])
{
	std::cout<<"Displaying the SIGACT "
		<<"Theoretical Computer Science Genealogy"<<std::endl;
	//<scan the theory database file and build the maps
		//<get the genealogy file name, and prepare to read it in>
	std::cout<<"First, enter the name of the file containing\n"
		<<"the genealogy data: "<<std::flush;
	string file_name;
	std::cin>>file_name;
	std::ifstream ifs(file_name.c_str());
	if(!ifs.is_open())
	{
		std::cout<<"Eh? Could not open file named "<<file_name<<std::endl;
		exit(1);
	}
	relation_map advisors,students;
	string name,advisor,place,date;
	while(true)
	{
		//ignore comments
		if(ifs.peek()=='#')
		{
			get_chunk(ifs,name,'\n');
			continue;
		}
		//<read a line of data, terminate on end of file>
		get_chunk(ifs,name);
		if(!ifs) break;
		get_chunk(ifs,advisor);
		get_chunk(ifs,place);
		get_chunk(ifs,date,'\n');
		earlier::places[name]=place;
		earlier::dates[name]=date;
		if(advisor=="?")
			advisor="---";
		students[advisor].insert(name);
		advisors[name].insert(advisor);
	}
	//<find persons with unknown advisor and add a root entry for each>
		//<<initialize the set of tree roots to the students of --->
		date_ordered_mset& roots=students["---"];
	relation_map::iterator i;
	date_ordered_mset::iterator j;
	bool any_advisor;
	for(i=advisors.begin();i!=advisors.end();++i)
	{
		//<check if this person has an advisor in the database>
		any_advisor=false;
		for(j=i->second.begin();j!=i->second.end();++j)
		{
			if(*j==string("---") || advisors.find(*j)!=advisors.end())
				any_advisor=true;
		}
		//<if not, add an entry to the set of roots>
		if(!any_advisor)
		{
			string first_advisor=*(i->second.begin());
			//check if it is already there: must do a linear search with generic find
			//since multiset is ordered based on dates rather than names(but the
			//multiset size is not big enough for this to be a problem).
			if(std::find(roots.begin(),roots.end(),first_advisor)==roots.end())
				roots.insert(first_advisor);
		}
	}
	//<output all the trees rooted at --->
	for(j=roots.begin();j!=roots.end();++j)
		output_tree(*j,students,earlier::places,earlier::dates);
	return 0;
}

