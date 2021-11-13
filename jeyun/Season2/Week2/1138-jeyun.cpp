#include <iostream>

using namespace std;

int main()
{
  int N, idx = 0, cnt = 0,input[10], arr[10] = {};
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> input[i];

  for (int i = 0; i < N; i++)
  {
    idx = 0;
    cnt = 0;
    while (1)
    {
      if (arr[idx] == 0)
      {
        if (cnt == input[i])
        {
          arr[idx] = i + 1;
          break;
        }
        cnt++;
      }
      idx++;
    }
  }

  for (int i = 0; i < N; i++)
    cout << arr[i] << " ";
}
