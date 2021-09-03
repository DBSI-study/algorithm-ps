// 점프
#include <bits/stdc++.h>
#define Max 101

using namespace std;

typedef long long ll;

ll dp[Max][Max];
int arr[Max][Max];

int main(void){
	int N;		
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(arr[i][j] == 0) continue;
			if(i + arr[i][j] < N) dp[i + arr[i][j]][j] += dp[i][j];	
			if(j + arr[i][j] < N) dp[i][j + arr[i][j]] += dp[i][j];	
		}
	}	
	cout << dp[N - 1][N - 1] << "\n";
	return 0;
}