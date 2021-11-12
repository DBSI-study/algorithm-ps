#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int N,t1,t2;
	
	vector<pair<int, int>> v;
	multiset<int> classList;
  multiset<int>::iterator iter;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> t1 >> t2;

		v.push_back({ t1,t2 });
	}

	sort(v.begin(), v.end());
  classList.insert(v[0].second);

	for (int j = 1; j < N; j++)
	{
    iter = classList.begin();
		if (v[j].first >= *iter)
		{
			classList.erase(classList.begin());
      classList.insert(v[j].second);
		}
		else
		{
			classList.insert(v[j].second);
		}
	}
	cout << classList.size();
}
