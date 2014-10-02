#include "stdafx.h"
#include "Palindrome_Partitioning_II.h"


Palindrome_Partitioning_II::Palindrome_Partitioning_II()
{
}


Palindrome_Partitioning_II::~Palindrome_Partitioning_II()
{
}

int Palindrome_Partitioning_II::minCut(string s) {
	//Check the parameters
	if (s.size() == 0 || s.size() == 1) {
		return 0;
	}
	int sSize = s.size();
	int* minCut = new int[sSize];
	minCut[0] = 0;
	int* paliMatrix = new int[sSize * sSize];
	paliMatrix[0] = 0;
	int i;
	for (i = 1; i < sSize; ++i) {
		//try to find palindrome in s with a[i];
		int j;
		for (j = i; j >= 0; --j) {
			int index = i * sSize + j;
			paliMatrix[index] = 1;

			if (j == i) {
				paliMatrix[index] = 0;
			}

			if ((j == i - 1) && s[j] == s[i]) {
				paliMatrix[index] = 0;
			}

			if ((j < i - 1) && s[j] == s[i] && paliMatrix[(i - 1) * sSize + j + 1] == 0) {
				paliMatrix[index] = 0;
			}
		}

		int iTemp = INT_MAX;
		for (j = 0; j <= i; ++j) {
			if (paliMatrix[i * sSize + j] == 0) {
				if (j == 0) {
					iTemp = 0;
				}
				else {
					iTemp = iTemp < (minCut[j - 1] + 1) ? iTemp : (minCut[j - 1] + 1);
				}
			}
		}
		minCut[i] = iTemp;

	}
	int cutNumber = minCut[i - 1];
	delete[] minCut;
	delete[] paliMatrix;
	return cutNumber;
}