#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
 
#define endl "\n"
#define MAX 1500
using namespace std;
 
int R, C;
bool Find;
char MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
queue<pair<int, int>> Swan_Q, Swan_NQ, Q, NQ;
pair<int, int> Swan_Pos;
 
void Input()
{
    Find = false;
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] != 'X') Q.push(make_pair(i, j));
            if (MAP[i][j] == 'L')
            {
                Swan_Pos.first = i;
                Swan_Pos.second = j;
            }
        }
    }
}
 
void Swan_BFS()
{
    while (Swan_Q.empty() == 0 && Find == false)
    {
        int x = Swan_Q.front().first;
        int y = Swan_Q.front().second;
        Swan_Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < R && ny < C)
            {
                if (Visit[nx][ny] == false)
                {
                    if (MAP[nx][ny] == '.')
                    {
                        Visit[nx][ny] = true;
                        Swan_Q.push(make_pair(nx, ny));
                    }
                    else if (MAP[nx][ny] == 'L')
                    {
                        Visit[nx][ny] = true;
                        Find = true;
                        break;
                    }
                    else if (MAP[nx][ny] == 'X')
                    {
                        Visit[nx][ny] = true;
                        Swan_NQ.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}
 
void Water_BFS()
{
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < R && ny < C)
            {
                if (MAP[nx][ny] == 'X')
                {
                    MAP[nx][ny] = '.';
                    NQ.push(make_pair(nx, ny));
                }
            }
        }
    }
}
 
void Solution()
{
    int Day = 0;
    Swan_Q.push(make_pair(Swan_Pos.first, Swan_Pos.second));
    Visit[Swan_Pos.first][Swan_Pos.second] = true;
 
    while (Find == false)
    {
        Swan_BFS();
 
        if (Find == false)
        {
            Water_BFS();
            Q = NQ;
            Swan_Q = Swan_NQ;
 
            while (NQ.empty() == 0) NQ.pop();
            while (Swan_NQ.empty() == 0) Swan_NQ.pop();
            Day++;
        }
    }
    cout << Day << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}