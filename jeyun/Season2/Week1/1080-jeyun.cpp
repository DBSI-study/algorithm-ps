#include <iostream>

using namespace std;

int main() {
  int N,M, result = 0, curMatrix[50][50], destMatrix[50][50];

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      scanf("%1d", &curMatrix[i][j]);

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      scanf("%1d", &destMatrix[i][j]);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (curMatrix[i][j] != destMatrix[i][j])
      {
        if (i >= N - 2 || j >= M - 2)
        {
          // 즉시 종료
          cout << -1;
          return 0;
        }
        else
        {
          result++;
          for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
              curMatrix[i + a][j + b] = !curMatrix[i + a][j + b];
        }
      }
    }
  }
  cout << result;
} 
