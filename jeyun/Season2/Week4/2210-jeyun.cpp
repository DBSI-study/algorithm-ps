#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int board[5][5];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
vector<string> result;
void dfs(int x, int y, int cnt, string s)
{
  if (x < 0 || x > 4 || y < 0 || y > 4) return;
  s = s + to_string(board[x][y]);
  if (cnt == 5)
  {
    if (find(result.begin(), result.end(), s) == result.end())
      result.push_back(s);
  }
  else
  {
    cnt++;
    for (int i = 0; i < 4; i++)
      dfs(x + dx[i], y + dy[i], cnt, s);
  }
}

int main()
{
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      cin >> board[i][j];

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      dfs(i, j, 0, "");
  
  cout << result.size();
}
