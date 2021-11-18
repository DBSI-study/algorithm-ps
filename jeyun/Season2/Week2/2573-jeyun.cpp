#include <iostream>
#include <algorithm>

using namespace std;

bool noChunks = false, searched[300][300] = {};
int N, M, year = 0, iceberg[300][300];

int DFS(int i, int j, int D)
{
  int I,J;
  searched[i][j] = true;
  I = i + (D == 0 ? -1 : D == 2 ? 1 : 0);
  J = j + (D == 1 ? 1 : D == 3 ? -1 : 0);
  if (I >= 0 && I < N && J >= 0 && J < M)
  {
    if (!searched[I][J])
    {
      if (iceberg[I][J] == 0 && iceberg[i][j] > 0)
        iceberg[i][j]--;

      if (iceberg[I][J] != 0)
        for (int d = 0; d < 4; d++)
          DFS(I,J,d);
    }
  }
  return 0;
}

bool isEnd()
{
  bool chunkFind = false;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (!searched[i][j] && iceberg[i][j] != 0)
      {
        if (!chunkFind)
        {
          for (int d = 0; d < 4; d++)
            DFS(i,j,d);

          chunkFind = true;
        }
        else
          return true;
      }
    }
  }
  if (!chunkFind)
  {
    noChunks = true;
    return true;
  }
  
  year++;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      searched[i][j] = false;
  return false;
}

int main()
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> iceberg[i][j];

  while (!isEnd()){}
  if (noChunks)
    cout << 0;
  else
    cout << year;
}
