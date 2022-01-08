#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, M, idx1 = 0, idx2 = 0;
  cin >> N >> M;
  vector<int> A(N), B(M), result(N+M); 
  for (int i = 0; i < N; i++)
    cin >> A[i];
  for (int i = 0; i < M; i++)
    cin >> B[i];
  
  for (int i = 0; i < N + M; i++)
  {
    if (idx1 < N && idx2 < M)
    {
      if (A[idx1] < B[idx2])
        result[i] = A[idx1++];
      else
        result[i] = B[idx2++];
    }
    else if (idx1 == N)
      result[i] = B[idx2++];
    else if (idx2 == M)
      result[i] = A[idx1++];
  }

  for (int i = 0; i < M+N; i++)
    cout << result[i] << " ";
}
