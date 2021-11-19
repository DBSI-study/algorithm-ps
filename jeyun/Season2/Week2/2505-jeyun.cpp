#include <iostream>
#include <algorithm>

using namespace std;

int N, board[10001], seriesCount = 0;
pair<int,int> series[10];

void reverse(int i, int j)
{
  int tmp;
  for (int k = 0; k <= (j - i) / 2; k++)
  {
    tmp = board[i + k];
    board[i + k] = board[j - k];
    board[j - k] = tmp;
  }
}
//series는 배열의 인덱스 정보
void seriesReverse(int i, int j)
{
  int tmp = series[i].first + series[j].second, swap;
  for (int k = i; k <= j; k++)
  {
    swap = series[k].first;
    series[k].first = tmp - series[k].second;
    series[k].second = tmp - swap;
  }
  sort(series, series + seriesCount);
}

bool check()
{
  for (int i = 0; i < N; i++)
    if (board[i] != i + 1)
      return false;

  return true;
}
int main()
{
  bool flag = false;
  int tmp;
  pair<int,int> result[2] = {{1,1},{1,1}};
  cin >> N;
  for (int i = 0; i < N;i++)
    cin >> board[i];

  tmp = 0;
  for (int i = 1; i < N; i++)
  {
    if (board[i-1] - board[i] == 1 || board[i-1] - board[i] == -1)
    {
      tmp = i;
    }
    else
    {
      series[seriesCount].first = seriesCount == 0 ? 0 : series[seriesCount - 1].second + 1;
      series[seriesCount].second = tmp;
      if ((tmp - series[seriesCount].first) == 1)
      {
        series[seriesCount].second = tmp - 1;
        series[seriesCount + 1].first = tmp;series[seriesCount + 1].second = tmp;
        seriesCount++;
      }
      tmp = i;
      seriesCount++;
    }
  }
  series[seriesCount].first = seriesCount == 0 ? 0 : series[seriesCount - 1].second + 1;
  series[seriesCount].second = N - 1;
  if ((N - 1 - series[seriesCount].first) == 1)
  {
    series[seriesCount].second = N - 2;
    series[seriesCount + 1].first = N - 1;
    series[seriesCount + 1].second = N - 1;
    seriesCount++;
  }
  seriesCount++;

  if (!check())
  {
    for (int i = 0; i < seriesCount; i++)
    {
      for (int j = i; j < seriesCount; j++)
      {
        reverse(series[i].first, series[j].second);
        seriesReverse(i, j);
        if (check())
        {
          seriesReverse(i, j);
          result[0].first = series[i].first + 1;
          result[0].second = series[j].second + 1;
          flag = true;
          break;
        }
        for (int k = 0; k < seriesCount; k++)
        {
          for (int l = k; l < seriesCount; l++)
          {
            if (i == k && j == k)
              continue;
            reverse(series[k].first, series[l].second);
            seriesReverse(k, l);
            if (check())
            {
              seriesReverse(k, l);
              result[1].first = series[k].first + 1;
              result[1].second = series[l].second + 1;

              seriesReverse(i, j);
              result[0].first = series[i].first + 1;
              result[0].second = series[j].second + 1;

              flag = true;
              break;
            }
            reverse(series[k].first, series[l].second);
            seriesReverse(k, l);
          }
          if (flag)
            break;
        }
        if (flag)
          break;
        reverse(series[i].first, series[j].second);
        seriesReverse(i, j);
      }
      if (flag)
        break;
    }
  }
  
  cout << result[0].first << " " << result[0].second << "\n";
  cout << result[1].first << " " << result[1].second;
}
