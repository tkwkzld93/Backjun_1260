#include "Main.h"

using namespace std;
void Back_1205();
bool Binary_Search(vector<int> nums, int goal, int len);
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