#include "stdafx.h"
#include "Distinct_Subsequences.h"


Distinct_Subsequences::Distinct_Subsequences()
{
}


Distinct_Subsequences::~Distinct_Subsequences()
{
}

int Distinct_Subsequences::numDistinct(string S, string T) {
	int sSize = S.size();
	int tSize = T.size();
	int* combinedMatrix = new int[tSize * sSize];

	//need check parameters
	if (sSize == 0) {
		return 0;
	}
	//buildup combinedMatrix;
	int i, j;
	for (i = 0; i < tSize; ++i) {
		for (j = 0; j < sSize; ++j) {
			if (T[i] == S[j]) {
				if (i == 0) {
					if (j == 0) {
						combinedMatrix[i*sSize + j] = 1;
					}
					else {
						combinedMatrix[i*sSize + j] = combinedMatrix[(i*sSize + j - 1)] + 1;
					}
				}
				else {
					if (j == 0) {
						combinedMatrix[i*sSize + j] = 0;
					}
					else {
						combinedMatrix[i*sSize + j] = combinedMatrix[(i*sSize + j - 1)] + combinedMatrix[(i - 1) * sSize + j - 1];
					}
				}
			}
			else {
				if (i == 0) {
					if (j == 0) {
						combinedMatrix[i*sSize + j] = 0;
					}
					else {
						combinedMatrix[i*sSize + j] = combinedMatrix[(i*sSize + j - 1)];
					}
				}
				else {
					if (j == 0) {
						combinedMatrix[i*sSize + j] = 0;
					}
					else {
						combinedMatrix[i*sSize + j] = combinedMatrix[(i*sSize + j - 1)];
					}
				}
			}
		}
	}
	return combinedMatrix[tSize * sSize - 1];
}