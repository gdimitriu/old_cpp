#include "StdAfx.h"
#include "StripComment.h"

using std::basic_string;

StripComment::StripComment(void)
{
	isStarComment=false;
}


StripComment::~StripComment(void)
{
}


int StripComment::ParseLine(string& Line)
{
	StripLineEndStar(Line,FindLineStartStar(Line,Line.begin()));
	return 0;
}


bool StripComment::StripLineEndStar(string& Line , string::iterator position)
{
	bool endOfLine=true;
	if(isStarComment==true)
	{
		basic_string <char>::size_type endPosition=Line.find("*/",position-Line.begin());
		if(endPosition<string::npos)
		{			
			isStarComment=false;
			endOfLine=false;
		}
		Line.erase(position,position+endPosition);
	}
	return endOfLine;
}


string::iterator StripComment::FindLineStartStar(string& Line, string::iterator position)
{
	if(isStarComment==false)
	{
		basic_string <char>::size_type endPosition=Line.find("/*",position-Line.begin());
		if(endPosition<string::npos)
		{			
			isStarComment=true;
			return Line.begin()+endPosition;
		}
	}
	return Line.begin();
}
