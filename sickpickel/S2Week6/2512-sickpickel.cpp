#include <bits/stdc++.h>
#define Max 10001

using namespace std;
typedef long long ll;

int arr[Max], N;

ll getSum(ll limit){
	ll ret = 0;
	for(int i = 0; i < N; i++){
		ret += min(limit, (ll)arr[i]);
	}
	return ret;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	ll M, total_request;
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		total_request += arr[i];
	}
	sort(arr, arr + N);
	cin >> M;	
	
	ll left = 0, right = M, answer = 0;
	while(left <= right){
		ll mid = (left + right) / 2;
		ll curSum = getSum(mid);
		if(curSum > M){
			right = mid - 1;	
		}
		else {
			answer = min((ll)arr[N - 1], mid);
			left = mid + 1;	
		}
	}
	cout << answer << "\n";
	return 0;
}