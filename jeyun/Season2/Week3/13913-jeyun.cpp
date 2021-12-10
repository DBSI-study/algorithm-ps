#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int from[300001], N, K;
void tracing(int node)
{
  int next = from[node];
  if (node != N)
    tracing(next);

  cout << node << " ";
}
int main()
{
  int visited[300001] = {}, flag = false;
  queue<int> q;

  cin >> N >> K;

  q.push(N);
  if (N == K)
    cout << 0 << "\n" << N;
  else
  {
    while (!q.empty())
    {
      if (flag)
        break;
      int node = q.front();
      
      q.pop();

      for (int i = 0; i < 3; i++)
      {
        int t = node + (i == 0 ? 1 : i == 1 ? -1 : node);

        if (t < 0 || t > 300001)
          continue;
        if (visited[t] > 0)
          continue;

        visited[t] = visited[node] + 1;
        from[t] = node;
        if (t == K)
        {
          cout << visited[t] << "\n";
          tracing(t);
          flag = true;
          break;
        }
        q.push(t);
      }
    }
  }
}
