#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T, N, t1, t2, result, min;
	vector<pair<int, int>> temp_v;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> t1 >> t2;
			temp_v.push_back({ t1,t2 });
		}
		sort(temp_v.begin(), temp_v.end());

		result = 1;
		min = temp_v[0].second;
		for (int j = 0; j < temp_v.size(); j++)
		{
			if (temp_v[j].second < min)
			{
				result++;
				min = temp_v[j].second;
			}
		}
		temp_v.clear();
		cout << result << "\n";
	}
}
