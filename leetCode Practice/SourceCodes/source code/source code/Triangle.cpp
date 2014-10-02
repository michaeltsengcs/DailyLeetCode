#include "stdafx.h"
#include "Triangle.h"


Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}

int Triangle::minimumTotal(vector<vector<int> > &triangle) {
	vector<int> minPath(triangle.back());
	for (int i = triangle.size() - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			int iTemp = minPath.at(j) < minPath.at(j + 1) ? minPath.at(j) : minPath.at(j + 1);
			minPath.at(j) = triangle.at(i).at(j) + iTemp;
		}
	}
	return minPath.at(0);
}