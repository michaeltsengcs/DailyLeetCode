#include "stdafx.h"
#include "Word_Break.h"


Word_Break::Word_Break()
{
}


Word_Break::~Word_Break()
{
}

//bool Word_Break::wordBreak(string s, unordered_set<string> &dict) {
//	// check the parameters 
//	int canBeSegmented = 1;
//	if (!s.empty() && !dict.empty())
//	{
//		size_t lenth = s.length();
//		int *possible = new int[lenth + 1];
//		for (int i = 0; i < lenth + 1; ++i) {
//			possible[i] = -1;
//		}
//		possible[0] = 0;
//		canBeSegmented = wordBreakHelper(s, dict, possible);
//		delete[]possible;
//	}
//	if (canBeSegmented == 1) {
//		return false;
//	}
//	else {
//		return true;
//	}
//}
//
//int Word_Break::wordBreakHelper(string s, unordered_set<string> &dict, int possible[]) {
//	int canBeSegmented = 1;
//	for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter) {
//		string sTemp = *iter;
//		size_t sSize = sTemp.size();
//		if (s.size() >= sSize && s.substr(s.size() - sSize, sSize).compare(sTemp) == 0) {
//			if ((s.size() - sSize) == 0) {
//				canBeSegmented = 0;
//			}
//			else {
//				string sTemp1 = s.substr(0, s.size() - sSize);
//				if (possible[sTemp1.size()] == 0) {
//					canBeSegmented = 0;
//				}
//				else if (possible[sTemp1.size()] == 1) {
//					canBeSegmented = 1;
//				}
//				else if (possible[sTemp1.size()] == -1) {
//					canBeSegmented = wordBreakHelper(sTemp1, dict, possible);
//				}
//			}
//		}
//	}
//	if (canBeSegmented == 0) {
//		possible[s.size()] = 0;
//	}
//	else {
//		possible[s.size()] = 1;
//	}
//	return canBeSegmented;
//}


/*
This is the forwarding method.
*/
bool Word_Break::wordBreak(string s, unordered_set<string> &dict) {
	size_t sSize = s.length();
	size_t dSize = dict.size();
	if (sSize == 0) {
		return true;
	}

	if (dSize == 0) {
		return false;
	}

	bool *t = new bool[sSize + 1](); //This is the best way to zero-initialzed the dynamic allocate boolarray.
	t[0] = true;
	for (int i = 0; i < (sSize + 1); ++i) { // You are looking forward. Therefore, i should start at 0;
		if (t[i] == true) {
			for (string sTemp : dict) {
				if ((i + sTemp.length()) <= sSize &&  s.substr(i, sTemp.length()).compare(sTemp) == 0) { // I should think a better way to solve this problem.
					t[i + sTemp.length()] = true;
				}
			}
		}
	}

	bool result = t[sSize];
	delete[] t;
	return result;
}

/*
This is the backward method.
*/
bool Word_Break::wordBreak(string s, unordered_set<string> &dict) {

}