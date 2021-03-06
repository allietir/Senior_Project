#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "wordwrap.h"
#include "Game.h"

using namespace std;

//In this case maxLength will be a global variable from globals.h
//This is a C++ implementation of what is here:
//http://www.cplusplus.com/forum/beginner/132223/
string word_wrap(string wrapString, int maxLength) {
	unsigned int line_start = 0;

	const string color = "\033[";

	while (line_start < wrapString.size())
	{
	//	printf("parsing %c\n", wrapString[line_start]);
		unsigned int ideal_end = line_start + maxLength;

		//take into account extra characters from embedded ascii colors
		size_t hasColor = wrapString.find(color, line_start);
		if ((hasColor != string::npos) && (hasColor <= ideal_end))
		{
			ideal_end = ideal_end + 11;
		}

		unsigned line_end = ideal_end <= wrapString.size() ? ideal_end : wrapString.size()-1;

		size_t hasNewLine = wrapString.find('\n', line_start);
		if ((hasNewLine != string::npos) && (hasNewLine <= line_end))
		{
			line_start = hasNewLine + 1;
			continue;
		}

		//if we are at the end
		if (line_end == wrapString.size() - 1)
		{
			line_end++;
		}
		//a space is found->insert newline
		else if (isspace(wrapString[line_end]))
		{
		
			wrapString[line_end] = '\n';
	//		wrapString[line_end] = '!';
			line_end++;
		}
		//avoid inserting newline in middle of word
		else
		{
			//create new tracker variable to backtrace
			unsigned end = line_end;

			//backtrace to a space character
			while (end > line_start && !isspace(wrapString[end]))
			{
				//printf("----backtracing----");
				end--;
			}

			//reset end of line to current tracker position
			if (end != line_start)
			{
				line_end = end;
				wrapString[line_end++] = '\n';
				//wrapString[line_end++] = '<';
			}
			//
			else
			{
				wrapString.insert(line_end++, 1, '\n');
				//wrapString.insert(line_end++, 1, '>');
			}
		}

		//start again from current point
		line_start = line_end;
	}

	return wrapString;
}