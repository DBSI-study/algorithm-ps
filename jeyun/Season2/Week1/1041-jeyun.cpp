#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long N, result = 0, dice[6], least[3];
	cin >> N;
	for (int i = 0; i < 6; i++)
		cin >> dice[i];

	if (N == 1)
	{
		sort(dice, dice + 6);
		result = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (dice[i] > dice[5 - i])
				least[i] = dice[5 - i];
			else
				least[i] = dice[i];
		}

		// Sort
		sort(least, least + 3);

		// 상단 사각 꼭지점
		result = least[0] + least[1] + least[2];
		result *= 4;
		// 상단 모서리 + 측면 모서리
		result += (least[0] + least[1]) * (2 * N - 3) * 4;
		// 상단 면 + 측면 면
		result += (least[0] * (5 * N - 6) * (N - 2));
	}
	cout << result;
}
