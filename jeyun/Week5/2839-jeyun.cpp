#include <iostream>

using namespace std;

int main()
{
	int n, five = 0, three = 0;

	cin >> n;

	five = n / 5;
	three = n % 5;
	while (three % 3 != 0)
	{
		five -= 1;
		three += 5;
	}
	if (five < 0)
		cout << -1;
	else
	{
		three /= 3;
		cout << five + three;
	}
}
