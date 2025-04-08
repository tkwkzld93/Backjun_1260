#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>


using namespace std;
int main()
{
	int N, score, P;
	int mRank = -1;
	cin >> N >> score >> P;

	if (N == 0)
	{
		cout << "1\n";
		return 0;
	}
		

	vector<int> rank(N, 0);
	for (int i = 0 ; i < N ; i++)
	{
		cin >> rank[i];	
	}
	sort(rank.begin(), rank.end(), greater<int>());

	for (int i = N - 1; i >= 0 ; i--)
	{
		if (score >= rank[i])
		{
			if(score > rank[i] && i == P - 1)
				continue;
			if (i < P - 1)
				mRank = i + 1;
			else
				break;
		}
		else
		{
			if (i < P - 1)
				mRank = i + 2;
			break;		
		}
			
	}
	cout << mRank << "\n";

	return 0;
}
