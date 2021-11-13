#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int getDigitNum(int num, int p)
{
  int result = 0;
  while (num >= 1)
  {
    result += pow(num % 10, p);
    num /= 10;
  }
  return result;
}
int main()
{
  int A, P, cur, idx = 1, D[1000000] = {};

  cin >> A >> P;

  cur = A;

  D[A] = idx++;

  while (1)
  {
    cur = getDigitNum(cur, P);
    if (D[cur] > 0)
      break;
    else
      D[cur] = idx++;
    
  }
  cout << (D[cur] - 1);
}
