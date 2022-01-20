#include <bits/stdc++.h>
#define Max 200001

using namespace std;

int N, C, arr[Max];

int countRouter(int distance){
	int ret = 1;
	long long between = 0;
	for(int i = 1; i < N; i++){
		between += arr[i] - arr[i - 1];
		if(between >= distance){
			between = 0;
			if(++ret > C) return ret;
		}
	}	
	return ret;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr + N);
	
	int left = 0, right = arr[N - 1] - arr[0], answer = 0;
	while(left <= right){
		int distance = (left + right) / 2;	
		int used_router = countRouter(distance);
		if(used_router < C){
			right = distance - 1;
		}
		else {
			answer = distance;
			left = distance + 1;	
		}	
	}
	cout << answer << "\n";	
	return 0;
}