#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;
void pibonachi(int value)
{
	vector<pair<int, int>> pibo;
	int i = 2;
	pibo.push_back({ 1, 0 });
	pibo.push_back({ 0, 1 });
	while (i <= value)
	{
		pibo.push_back({ (pibo[i - 1].first + pibo[i - 2].first), (pibo[i - 1].second + pibo[i - 2].second) });
		i++;
	}
	cout << pibo.back().first << " " << pibo.back().second << endl;
}
int main()
{
	int T;
	vector<int> tCase;
	cin >> T;
	tCase.resize(T);
	for (int i = 0; i < T; i++)
	{
		cin >> tCase[i];
	}
	for (int i = 0; i < T; i++)
	{
		if (tCase[i] == 0)
		{
			cout << "1 0" << endl;
			continue;
		}
		else if (tCase[i] == 1)
		{
			cout << "0 1" << endl;
			continue;
		}
		pibonachi(tCase[i]);
	}
	return 0;
}