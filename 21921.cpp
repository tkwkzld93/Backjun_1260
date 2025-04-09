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
	int N, X, cnt = 1;
	cin >> N >> X;
	vector<int> visitors(N, 0);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> visitors[i];
		if (i < X)
			sum += visitors[i];
	}
	int maxSum = sum;

	for (int i = X; i < N; i++) 
	{
		sum = sum - visitors[i - X] + visitors[i];

		if (sum > maxSum) {
			maxSum = sum;
			cnt = 1;
		}
		else if (sum == maxSum) {
			cnt++;
		}
	}

	if (maxSum == 0)
		cout << "SAD";
	else
		cout << maxSum << "\n" << cnt;
	return 0;
}

