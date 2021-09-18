#include <bits/stdc++.h>
#define Max 100001
#define INF 987654321

using namespace std;

int dp[Max];

int main(void){
	int N;
	cin >> N;
	
	dp[0] = 0;
	for(int i = 1; i <= N; i++){
		dp[i] = INF;
	}
	
	for(int i = 1; i * i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(i * i > j) continue;
			dp[j] = min(dp[j], dp[j - i * i] + 1);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}