#pragma once
/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include <string>
using namespace std;

class Palindrome_Partitioning_II
{
public:
	Palindrome_Partitioning_II();
	~Palindrome_Partitioning_II();
	int minCut(string s);
};

