#include <bits/stdc++.h>
#define Max 100001

using namespace std;

int arr[Max];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, maxInput = -1001;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		maxInput = max(maxInput, arr[i]);
	}
	int sum = 0, answer = arr[0];
	for(int i = 0; i < N; i++){
		sum = max(0, sum + arr[i]);
		answer = max(answer, sum);
	}
	if(maxInput < 0) cout << maxInput << "\n";
	else cout << answer << "\n";	
	return 0;
}