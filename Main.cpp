#include "Main.h"

using namespace std;
void Back_1205();
void Back_1253();
bool Binary_Search(vector<int> nums, int goal, int len);


bool IsCheckRoot(int goal, int root, vector<vector<int>> arr)
{
	vector<int> mArr = arr[root];
	for (int i = 0; i < mArr.size(); i++)
	{
		if (mArr[i] == 1 && i + 1 == goal)
			return true;
		if (mArr[i] == 1)
			IsCheckRoot(goal, i, arr);
	}
	return false;
}
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
void Back_21921()
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
}