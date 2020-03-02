#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "wordwrap.h"
#include "Game.h"

using namespace std;

//In this case maxLength should be a global variable from globals.h
string word_wrap(const char* wrapString, int maxLength) {
	int line_start = 0;

	while (line_start < wrapString.size())
	{
		int ideal_end = line_start + maxLength;
		unsigned line_end = ideal_end <= wrapString.size() ? ideal_end : wrapString.size()-1;

		//if we are at the end
		if (line_end == wrapString.size() - 1)
		{
			line_end++;
		}
		//a space is found->insert newline
		else if (isspace(wrapString[line_end]))
		{
			wrapString[line_end] = '\n';
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
				end--;
			}

			//reset end of line to current tracker position
			if (end != line_start)
			{
				line_end = end;
				wrapString[line_end++] = '\n';
			}
			//
			else
			{
				wrapString.insert(line_end++, 1, '\n');
			}
		}

		//start again from current point
		line_start = line_end;
	}

	return wrapString;
}