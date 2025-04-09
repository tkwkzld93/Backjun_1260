#include "Main.h"

using namespace std;
void Back_1205();
void Back_1253();
bool Binary_Search(vector<int> nums, int goal, int len);
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

bool Binary_Search(vector<int> nums, int goal, int len)
{
	int low = 0, high = len - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (mid == goal)
			return true;
		if (goal < nums[mid])
		{
			high = mid - 1;
		}
		else if (goal > nums[mid])
		{
			low = mid + 1;
		}
	}
	return false;
}
void Back_1205()
{
	int N, score, P;
	int mRank = -1;
	cin >> N >> score >> P;

	if (N == 0)
	{
		cout << "1\n";
		return;
	}


	vector<int> rank(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> rank[i];
	}
	sort(rank.begin(), rank.end(), greater<int>());

	for (int i = N - 1; i >= 0; i--)
	{
		if (score >= rank[i])
		{
			if (score > rank[i] && i == P - 1)
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
}
void Back_1253()
{
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
}