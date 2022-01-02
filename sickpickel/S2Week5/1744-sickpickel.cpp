#include <bits/stdc++.h>
#define Max 51 

using namespace std;

int arr[Max];

bool compare(int a, int b){
	return a > b;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int N, pos = 0, neg = 0, zero = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		if(arr[i] > 0) pos++;
		else if(arr[i] < 0) neg++;
		else zero++;
	}
	
	sort(arr, arr + N, compare);
	int answer = 0;
	
	for(int i = 0; i + 1 < pos; i += 2){
		answer += max(arr[i] * arr[i + 1], arr[i] + arr[i + 1]);
	}
	if(pos % 2) answer += arr[pos - 1];
	
	for(int i = N - 1; i - 1 >= pos + zero; i -= 2){
		answer += arr[i] * arr[i - 1];
	}
	if(neg % 2 && zero == 0) answer += arr[pos + zero];
	
	cout << answer << "\n";
	return 0;
}