#include <iostream>
#include <set>

using namespace std;

int main() {
  int N, result = 0, t1, t2;
  multiset<int> ms;
  multiset<int>::iterator iter;

  cin >> N;


  for (int i = 0; i <N;i++)
  {
    cin >> t1;
    ms.insert(t1);
  }
  while (ms.size() > 1)
  {
    iter = ms.begin();
    t1 = *(iter++);
    t2 = *iter;
    result += t1 + t2;
    ms.erase(ms.begin());
    ms.erase(iter);
    ms.insert(t1+t2);
  }
  cout << result;
} 
