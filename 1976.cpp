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

int my_Map[201];

int Find(int x);
void Union(int x, int y);
int main()
{
	int N, M, tRoot;
	
	bool isPossibe = true;
	cin >> N >> M;
	vector<int> visited(M);

	for (int i = 1; i <= N; i++)
	{
		my_Map[i] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int root;
			cin >> root;
			if (root == 1)
				Union(i, j);
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> visited[i];
	}
	tRoot = Find(visited[0]);
	for (int i = 0; i < M; i++)
	{
		if (Find(visited[i]) != tRoot)
		{
			isPossibe = false;
			break;
		}
	}

	string res = isPossibe ? "YES" : "NO";
	cout << res << "\n";

	return 0;
}

int Find(int x)
{
	if (x == my_Map[x])
		return x;
	return my_Map[x] = Find(my_Map[x]);
}
void Union(int x, int y)
{
	int px = Find(x);
	int py = Find(y);
	if (px != py)
		my_Map[px] = py;
}

