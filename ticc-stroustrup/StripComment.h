#pragma once
#include <string>
using std::string;

class StripComment
{
public:
	StripComment(void);
	~StripComment(void);
	int ParseLine(string& Line);
private:
	bool isStarComment;
	bool StripLineEndStar(string& Line , string::iterator position);
	string::iterator FindLineStartStar(string& Line, string::iterator position);
};

