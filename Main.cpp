#include "Main.h"





int my_Map[201];//1976
int Find(int x);//1976
void Union(int x, int y);//1976
void Back_1205();
void Back_1253();
bool Binary_Search(vector<int> nums, int goal, int len);

bool IsCheck_Word(string s1, string s2);
string SortS(string s);
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
string SortS(string s)
{
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	return s;
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
void Back_1976()
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
}
void Back_2169()
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

		for (int j = M - 2; j >= 0; j--)
		{
			right[j] = max(right[j + 1], visit[i - 1][j]) + maps[i][j];
		}

		for (int j = 0; j < M; j++)
		{
			visit[i][j] = max(left[j], right[j]);
		}

	}
	cout << visit[N - 1][M - 1] << "\n";
}