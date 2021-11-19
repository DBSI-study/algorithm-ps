#include <iostream>
#include <algorithm>
#include<string.h>

using namespace std;

int main()
{
  int r, c, k, prevIdx, curIdx, Pcount, curR = 3, nxtRC, curC = 3, A[101][101] = {}, S[101] = {0}, converted[101] = {0}, sec = 0, arrayType = 0;
  pair<int,int> P[101] = {};
  cin >> r >> c >> k;

  for (int i = 1;i<=3;i++)
    for (int j = 1;j<=3;j++)
      cin >> A[i][j];
  
  while (A[r][c] != k)
  {
    sec++;
    if (sec == 101)
    {
      sec = -1;
      break;
    }
    if (curR >= curC)
      arrayType = 0; // 행정렬
    else
      arrayType = 1; // 열정렬
    for (int i = 1; i <= (arrayType == 0 ? curR : curC); i++)
    {
      memset(S, 0, sizeof(S));
      for (int a = 1; a <= 100; a++)
      {
        P[a].first = 0;
        P[a].second = 0;
      }
      memset(converted, 0, sizeof(converted));

      for (int j = 1; j <= (arrayType == 0 ? curC : curR); j++)
        S[j] = A[(arrayType == 0 ? i : j)][(arrayType == 0 ? j : i)];

      sort(S+1,S+((arrayType == 0 ? curC : curR))+1);
      prevIdx = 0;
      curIdx = 1;
      
      for (int j = 1; j <= (arrayType == 0 ? curC : curR); j++)
      {
        if (j + 1 > (arrayType == 0 ? curC : curR))
        {
          if (S[j] != 0)
          {
            P[curIdx].first = j - prevIdx;
            P[curIdx].second = S[j];
            curIdx++;
          }
        }
        else
        {
          if (S[j+1] != S[j])
          {
            if (S[j] != 0)
            {            
              P[curIdx].first = j - prevIdx;
              P[curIdx].second = S[j];
              prevIdx = j;
              curIdx++;
            }
            else
              prevIdx = j;
          }
        }
      }
      sort(P+1, P+curIdx); // curIdx는 idx (0부터셈)
      Pcount = curIdx - 1;
      curIdx = 1;
      for (int j = 1; j <= Pcount; j++)
      {
        if (curIdx < 101)
        {
          converted[curIdx] = P[j].second;
          converted[curIdx + 1] = P[j].first;
          curIdx += 2;
        }
      }
      // curIdx가 curC보다 클경우 curC갱신
      nxtRC = max(nxtRC, curIdx - 1);

      for (int j = 1; j <= 100; j++)
        A[(arrayType == 0 ? i : j)][(arrayType == 0 ? j : i)] = 0;

      for (int j = 1; j <= nxtRC; j++)
        A[(arrayType == 0 ? i : j)][(arrayType == 0 ? j : i)] = converted[j];
    }
    if (arrayType == 0)
      curC = nxtRC;
    else
      curR = nxtRC;

    nxtRC = 0;
  }
  cout << sec;
}
