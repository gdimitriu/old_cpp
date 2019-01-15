#pragma once
#include <map>
#include <string>
using std::map;
using std::string;

class Chistorgram
{
public:
	Chistorgram(void);
	~Chistorgram(void);
protected:
	map<string,int> histogram;
public:
	void record(const string s);
	void run(void);
	friend void external_run(Chistorgram *hist);
};

