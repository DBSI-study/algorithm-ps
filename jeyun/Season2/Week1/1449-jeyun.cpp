#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, L, leak[1001], tape = 0, attached = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> leak[i];
  
	sort(leak, leak+N);
  
	for (int i = 0; i < N; i++)
	{
		if (attached < leak[i])
		{
			tape++;
			attached = leak[i] + L - 1;
		}
	}
	cout << tape;
}
