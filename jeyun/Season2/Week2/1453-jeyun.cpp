#include <iostream>

using namespace std;

int main()
{
	int N, input, result = 0, computer[100] = {0};
	
  cin >> N;
  for (int i=0;i<N;i++)
  {
    cin >> input;
    if (computer[input - 1] == 0)
      computer[input- 1] = 1;
    else
      result++;
  }
  cout << result;
}
