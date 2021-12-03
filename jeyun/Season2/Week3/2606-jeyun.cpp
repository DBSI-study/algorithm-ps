#include <iostream>

using namespace std;

bool visited[100];
int N,M,result = 0; // N:컴수 M:컴쌍수
pair<int,int> edge[100000];

void DFS(int prev, int cur)
{
  if (!visited[cur])
  {
    if (cur != 1) result++;
    visited[cur] = true;
    for (int i = 0; i < M; i++)
    {
      if (edge[i].first == cur && edge[i].second != prev)
      {
        DFS(cur, edge[i].second);
      }
      else if (edge[i].second == cur && edge[i].first != prev)
      {
        DFS(cur, edge[i].first);
      }
    }
  }
}

int main()
{
  cin >> N >> M;

  for (int i = 0; i<M;i++)
  {
    cin >> edge[i].first >> edge[i].second;
  }

  DFS(0, 1);
  cout << result;
}
