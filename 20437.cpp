#include "Header.h"

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		vector<vector<int>> pos;
		string s;
		int n;
		int minIdx = 10001;
		int maxIdx = -1;
		cin >> s >> n;
		if (n == 1)
		{
			cout << "1 1\n";
			continue;
		}
		pos.resize(26);

		for (int i = 0; i < s.size(); i++)
		{
			pos[s[i] - 'a'].push_back(i);
		}

		for (int i = 0; i < pos.size(); i++)
		{
			if (pos[i].size() < n)
				continue;

			for (int j = 0; j <= pos[i].size() - n; j++)
			{
				int idx = pos[i][j + n - 1] - pos[i][j] + 1;
				maxIdx = max(maxIdx, idx);
				minIdx = min(minIdx, idx);
			}
		}

		if (maxIdx == -1)
			cout << "-1\n";
		else
			cout << minIdx << " " << maxIdx << endl;
	}
		
	return 0;
}