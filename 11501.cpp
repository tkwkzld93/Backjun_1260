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

bool IsCheck_Word(string s1, string s2);
int main()
{
	int n, cnt = 0;
	cin >> n;
	vector<string> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (IsCheck_Word(arr[0], arr[i]))
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}
bool IsCheck_Word(string s1, string s2)
{
	int word[26] = { 0, };
	int pCnt = 0, mCnt = 0;
	for (auto c : s1)
	{
		word[c - 'A']++;
	}
	for (auto c : s2)
	{
		word[c - 'A']--;
	}

	for (int i = 0; i < 26; i++)
	{
		if (word[i] > 0)
			pCnt += word[i];
		else
			mCnt -= word[i];
	}

	if ((pCnt == 1 || pCnt == 0) && (mCnt == 0 || mCnt == 1))
		return true;
	return false;
}
