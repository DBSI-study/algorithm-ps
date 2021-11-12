#include <bits/stdc++.h>
#define Max 1001

using namespace std;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int N, P[Max], dp[Max] = {};
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cin >> P[i];
	}
	dp[0] = 0;
	dp[1] = P[1];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			dp[i] = max(dp[i], dp[i - j] + P[j]);
		}
	}	
	cout << dp[N] << "\n";
	return 0;
}