#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

bool flag = false;
int K, V, E, first, second, combination[20001];
vector<int> vi[20001];
queue<pair<int,int>> q;
void bfs()
{
    while (!q.empty())
    {
      if (flag)
        break;

      pair<int,int> node = q.front();
      q.pop();
      if (combination[node.first] == 0)
      {
        combination[node.first] = node.second + 1;
        
        for (int j = 0; j < vi[node.first].size(); j++)
          q.push({vi[node.first][j], 1 - node.second});
      }
      else if (combination[node.first] != node.second + 1)
        flag = true;
    }
}
int main()
{
  cin >> K;
  for (int i = 0; i < K; i++)
  {
    flag = false;
    memset(combination, 0, sizeof(combination));
    for (int j = 0; j < 20001; j++)
      vi[j].clear();
    while (!q.empty())
      q.pop();
    cin >> V >> E;
    
    for (int j = 0; j < E; j++)
    {
      cin >> first >> second;
      vi[first].push_back(second);
      vi[second].push_back(first);
    }
    q.push({1,0});
    bfs();
    for (int j = 2; j < V; j++)
    {
      if (combination[j] == 0)
      {
        q.push({j,0});
        bfs();
      }
    }
    cout << (flag ? "NO" : "YES") << "\n";
  }    
}
