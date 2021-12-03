#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool visited[10001];
int maximum = 0, hack[10001];
vector<int> computers[10001];

int dfs(int c)
{
  int cnt = 1;
  visited[c] = true;

  for (int i = 0; i < computers[c].size(); i++)
  {
    if (!visited[computers[c][i]])
      cnt += dfs(computers[c][i]);
  }
  return cnt;
}

int main()
{
  int N, M, input1, input2;

  cin >> N >> M;
  for (int i=0; i<M;i++)
  {
      cin >> input1 >> input2;
      computers[input2].push_back(input1);
  }

  for (int i = 1; i <= N; i++)
  {
    memset(visited, false, sizeof(visited));

    hack[i] = dfs(i);
    if (hack[i] > maximum)
      maximum = hack[i];
  }

  for (int i = 1; i <= N; i++)
    if (maximum == hack[i])
      cout << i << " ";
}
