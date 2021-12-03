#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool visited[29][29];
int N, 
dx[] = {1, -1, 0, 0}, 
dy[] = {0, 0, -1, 1};
double rate[4], result = 0, td;

void dfs(int x, int y, int d, int move_count, vector<int> moving)
{
  // 이미 방문한 곳이라면 단순하지 않은 이동으로 처리
  if (visited[x][y])
    return;

  visited[x][y] = true;
  moving.push_back(d);

  if (++move_count == N)
  {
    // 끝까지 왔다면 단순한 이동임.
    td = rate[moving[0]];
    for (int i = 1; i < N; i++)
      td *= rate[moving[i]];
    
    result += td;

    visited[x][y] = false;
    return;
  }

  for (int i = 0; i < 4; i++)
    dfs(x + dx[i],y + dy[i], i, move_count, moving);

  visited[x][y] = false; // 찍고 나오면서 visited falst로 리셋
}

void init()
{
  for (int i = 0; i < 29; i++)
    memset(visited[i], false, sizeof(bool) * 29);
  
  visited[14][14] = true;
}

int main()
{
  cout.precision(10);

  int temp;
  vector<int> moving;

  cin >> N;
  for (int i = 0; i < 4; i++)
  {
    cin >> temp;
    rate[i] = (double)temp / 100;
  }

  for (int i = 0; i < 4; i++)
  {
    init();
    dfs(14 + dx[i],14 + dy[i], i, 0, moving);
  }

  cout << result;
}
