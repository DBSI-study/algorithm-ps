#include <bits/stdc++.h>
#define Max 1010

using namespace std;

int arr[Max], maxDp[Max], minDp[Max];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}	
	// get LIS
	for(int i = 0; i < N; i++){
		int save_max = 0;
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j]) save_max = max(save_max, maxDp[j]);
		}	
		maxDp[i] = save_max + 1;
	}
	// get LDS
	for(int i = N - 1; i >= 0; i--){
		int save_max = 0;
		for(int j = N - 1; j > i; j--){
			if(arr[i] > arr[j]) save_max = max(save_max, minDp[j]);
		}	
		minDp[i] = save_max + 1;
	}
	
	int answer = 0;
	for(int i = 0; i < N; i++){
		answer = max(answer, minDp[i] + maxDp[i] - 1);
	}
	cout << answer << "\n";
	return 0;
}