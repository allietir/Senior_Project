#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "wordwrap.h"
#include "Game.h"

using namespace std;

//In this case maxLength should be a global variable from globals.h
string word_wrap (string wrapString, int maxLength) {
	int line_begin = 0;

	while (i < wrapString.size())
	{
		int ideal_end = line_begin + maxLength;
		unsigned line_end = ideal_end <= text.size() ? ideal_end : wrapString.size()-1;

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
			unsigned end = line_end

			//backtrack to a space character
			while (end > line_begin && !isspace(text[end]))
			{
				end--;
			}

			//reset start of line to current end of line
			if (end != line_begin)
			{
				line_end = end;
				text[line_end++] = '\n';
			}
			//
			else
			{
				wrapString.insert(line_end++, 1, '\n');
			}
		}

		line_begin = line_end;
	}

	return wrapString;
}