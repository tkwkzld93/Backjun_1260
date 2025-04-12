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
	int N, M;
	cin >> N >> M;
	vector<vector<int>> maps(N, vector<int>(M));
	vector<vector<int>> visit(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maps[i][j];
		}
	}	

	visit[0][0] = maps[0][0];

	for (int i = 1; i < M; i++)
	{
		visit[0][i] = visit[0][i - 1] + maps[0][i];
	}

	for (int i = 1; i < N; i++)
	{
		vector<int> left(M), right(M);
		left[0] = visit[i - 1][0] + maps[i][0];
		right[M - 1] = visit[i - 1][M - 1] + maps[i][M - 1];
		for (int j = 1; j < M; j++)
		{
			left[j] = max(left[j - 1], visit[i - 1][j]) + maps[i][j];
		}

		for(int j = M - 2; j >= 0 ; j--)
		{
			right[j] = max(right[j + 1], visit[i - 1][j]) + maps[i][j];
		}

		for (int j = 0; j < M; j++)
		{
			visit[i][j] = max(left[j], right[j]);
		}

	}
	cout << visit[N - 1][M - 1] << "\n";
	return 0;
}

