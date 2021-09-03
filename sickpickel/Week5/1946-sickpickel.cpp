// 신입 사원
#include <bits/stdc++.h>
#define pii pair<int, int>
#define Max 100001

using namespace std;

int arr[Max];

void solve(){
	int N, paper, interview;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> paper >> interview;
		arr[paper] = interview;
	}
	int beforeVal = arr[1];
	int answer = 1;
	for(int i = 2; i <= N; i++){
		if(beforeVal > arr[i]) answer++;
		beforeVal = min(beforeVal, arr[i]);
	}
	cout << answer << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) solve();
	return 0;
}