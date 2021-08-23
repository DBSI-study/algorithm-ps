// with_using_stack
#include <bits/stdc++.h>
#define Max 500001
#define INF 987654321

using namespace std;

typedef long long ll;

int N;
ll tower[Max], dp[Max];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> tower[i];
	}
	tower[0] = INF;	
	dp[0] = 0;
	
	for(int i = 1; i <= N; i++){
		if(tower[i - 1] > tower[i])	{
			dp[i] = i - 1;
		}
		else{
			int idx = i - 1;
			while(tower[dp[idx]] < tower[i]){
				idx = dp[idx];
			}
			dp[i] = dp[idx];
		}
	}	
	
	for(int i = 1; i <= N; i++){
		cout << dp[i] << " ";
	}	
	return 0;
}