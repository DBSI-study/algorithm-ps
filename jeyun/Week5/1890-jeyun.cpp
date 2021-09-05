#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,temp,d;
    vector<vector<long long>> board;
    vector<vector<long long>> dp;
    vector<long long> t1,t2;
    cin >> n;

    for (int i = 0; i<n;i++)
    {
        for (int j = 0; j<n; j++)
        {
            cin >> temp;
            t1.push_back(temp);
            t2.push_back(0);
        }
        board.push_back(t1);
        dp.push_back(t2);
        t1.clear();
        t2.clear();
    }
    dp[0][0] = 1;
    for (int i = 0; i<n;i++)
    {
        for (int j = 0; j<n; j++)
        {
            if (i == n-1 && j == n-1) break;
            d = board[i][j];
            if (i+d < n)
                dp[i+d][j] += dp[i][j];
            if (j+d < n)
                dp[i][j+d] += dp[i][j];
        }
    }
    cout << dp[n-1][n-1];
}
