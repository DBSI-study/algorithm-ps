#include <bits/stdc++.h>
#define Max 1001
#define mod 10007

using namespace std;

typedef long long ll;

ll dp[Max][10];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	for(int i = 0; i < 10; i++){
		dp[0][i] = 1;
	}	
	for(int i = 1; i < N; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k <= j; k++){
				(dp[i][j] += dp[i - 1][k]) %= mod;
			}
		}
	}	
	ll ans = 0l;
	for(int i = 0; i < 10; i++){
		(ans += dp[N - 1][i]) %= mod;
	}	
	cout << ans << "\n";
	return 0;
}