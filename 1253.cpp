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
	//Back_1205();
	int N, cnt = 0;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	for (int i = 0; i < N; i++)
	{
		int goal = nums[i];
		int left = 0, right = N - 1;
		while (left < right)
		{
			int sum = 0;
			if (left == i)
			{
				left++;
				continue;
			}
			if (right == i)
			{
				right--;
				continue;
			}
			sum = nums[left] + nums[right];
			if (sum == goal)
			{
				cnt++;
				break;
			}
			else if (sum < goal)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}

	cout << cnt;
	return 0;
}
