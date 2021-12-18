#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main()
{
  char map[50][50];
  int visited[50][50], W, H, maximum = 0,
  dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
  queue<pair<int,int>> q;
  cin >> W >> H;
  for (int i = 0; i < W; i++)
    for (int j = 0; j < H; j++)
      cin >> map[i][j];
  for (int i = 0; i < 50; i++)
    memset(visited[i], -1, sizeof(int) * 50);

  for (int i = 0; i < W; i++)
  {
    for (int j = 0; j < H; j++)
    {
      if (map[i][j] == 'L')
      {
        visited[i][j] = 0;
        q.push({i,j});
        int x, y;
        while (!q.empty())
        {
          pair<int,int> tmp = q.front();
          q.pop();
          x = tmp.first;
          y = tmp.second;
          for (int i = 0; i < 4; i++)
          {
            if (x + dx[i] >= 0 && x + dx[i] < W && y + dy[i] >= 0 && y + dy[i] < H)
            {
              if (map[x + dx[i]][y + dy[i]] == 'L' && visited[x + dx[i]][y + dy[i]] == -1)
              {
                visited[x + dx[i]][y + dy[i]] = visited[x][y] + 1;
                q.push({x + dx[i], y + dy[i]});
              }
            }
          }
        }
        maximum = max(visited[x][y], maximum);
        for (int i = 0; i < 50; i++)
          memset(visited[i], -1, sizeof(int) * 50);
      }

    }
  }
  cout << maximum;
}
