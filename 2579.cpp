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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	vector<int> stair;
	vector<int> res;
	cin >> T;
	stair.resize(T + 1);
	res.resize(T + 1);

	for (int i = 1; i <= T; i++)
	{
		cin >> stair[i];
	}

	res[1] = stair[1];
	if (T >= 2)
	{
		res[2] = stair[1] + stair[2];
	}

	for (int i = 3; i <= T; i++)
	{
		res[i] = max(res[i - 2] + stair[i], res[i - 3] + stair[i] + stair[i - 1]);
	}

	cout << res[T] << endl;
	
	return 0;
}