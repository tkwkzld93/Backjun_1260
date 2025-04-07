#include "Header.h"

//v1 .정답이지만 시간 복잡도가  O(N²)이라 시간 초과

//vector<int> heights;
//void LeftCal(int center, vector<int>& sight)
//{
//	int left = heights[center];
//	for (int i = center - 1; i >= 0; i--)
//	{
//		if (heights[i] > left)//현재 보이고있는 건물보다 다음 건물의 높이가 크면
//		{
//			left = heights[i];//높이 변경
//			sight.push_back(i);//위치 저장
//		}
//	}
//}
//void RightCal(int center, vector<int>& sight)
//{
//	int right = heights[center];
//	for (int i = center; i < heights.size() ; i++)
//	{
//		if (heights[i] > right)//현재 보이고있는 건물보다 다음 건물의 높이가 크면
//		{
//			right = heights[i];//높이 변경
//			sight.push_back(i);//위치 저장
//		}
//	}
//}
//int MinMile(int center, vector<int> sight)
//{
//	int minIdx = 100001;
//	int pos = 100001;
//	for (int i = 0; i < sight.size(); i++)
//	{
//		int distance = abs(sight[i] - center);
//		if (minIdx > distance)
//		{
//			minIdx = distance;
//			pos = sight[i] + 1;
//		}
//	}
//
//	return pos;
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int N;
//	vector<vector<int>> sight;
//	cin >> N;
//	heights.resize(N);
//	sight.resize(N);
//
//	for (int i = 0; i < N; i++)
//	{
//		cin >> heights[i];
//	}
//	for (int i = 0; i < N; i++)
//	{
//		int left = heights[i];
//		int right = heights[i];
//		if (i == 0)
//		{
//			RightCal(i, sight[i]);
//		}
//		else if (i == N - 1)
//		{
//			LeftCal(i, sight[i]);
//		}
//		else
//		{
//			LeftCal(i, sight[i]);
//			RightCal(i, sight[i]);
//		}
//	}
//	for (int i = 0; i < sight.size(); i++)
//	{
//		if (sight[i].empty())
//			cout << "0\n";
//		else
//		{
//			cout << sight[i].size() << " " << MinMile(i, sight[i]) << endl;
//		}
//	}
//	return 0;
//}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

    vector<int> heights(N + 1);
    vector<vector<int>> sight(N + 1);
    vector<int> minPos(N + 1, 0);
    vector<int> count(N + 1, 0);

    stack<pair<int, int>> st1, st2;

    for (int i = 1; i <= N; i++)
        cin >> heights[i];

    //정방향
    for (int i = 1; i <= N; i++)
    {
        while (!st1.empty() && st1.top().first <= heights[i])
            st1.pop();

        count[i] += st1.size();

        if (!st1.empty() && minPos[i] == 0)
            minPos[i] = st1.top().second;

        st1.push({ heights[i], i });
    }

    //역돌격
    for (int i = N; i >= 1; i--)
    {
        while (!st2.empty() && st2.top().first <= heights[i])
            st2.pop();

        count[i] += st2.size();

        if (!st2.empty())
        {
            int candidate = st2.top().second;

            if (minPos[i] == 0)
                minPos[i] = candidate;
            else
            {
                int prevDist = abs(i - minPos[i]);
                int newDist = abs(i - candidate);

                if (newDist < prevDist || (newDist == prevDist && candidate < minPos[i]))
                    minPos[i] = candidate;
            }
        }

        st2.push({ heights[i], i });
    }

    for (int i = 1; i <= N; i++)
    {
        if (count[i] == 0)
            cout << 0 << '\n';
        else
            cout << count[i] << ' ' << minPos[i] << '\n';
    }
	return 0;
}