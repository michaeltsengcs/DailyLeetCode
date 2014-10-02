#include "stdafx.h"
#include "Reverse_Words_in_a_String.h"
#include <vector>


Reverse_Words_in_a_String::Reverse_Words_in_a_String()
{
}


Reverse_Words_in_a_String::~Reverse_Words_in_a_String()
{
}

void Reverse_Words_in_a_String::reverseWords(string &s) {
	//To clear the spaces in string
	unsigned i = 0;
	vector<string> strVect;

	//Put all the word into the strVect; 
	if (!s.empty()) {
		while (i < s.size()) {
			if (s.substr(i, 1) != " ") {
				unsigned uTemp = s.size() - i;
				unsigned j = 1;
				while (j < uTemp && s.substr(i + j, 1) != " ") {
					++j;
				}

				strVect.push_back(s.substr(i, j));
				i = i + j + 1;
			}
			else {
				++i;
			}
		}

		s.clear();
		if (!strVect.empty()) {
			s = strVect.back();
			strVect.pop_back();
			while (!strVect.empty()) {
				s = s + " " + strVect.back();
				strVect.pop_back();
			}
		}
	}
}
