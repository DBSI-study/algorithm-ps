#include <bits/stdc++.h>
#define Max 1010

using namespace std;

int main(void){
	
	int N, L, input;
	bool arr[Max] = {};
	cin >> N >> L;
	for(int i = 0; i < N; i++){
		cin >> input;
		arr[input] = 1;
	}
	int answer = 0;	
	for(int i = 1; i < Max; i++){
		if(arr[i] == 0) continue;
		answer++;
		i += (L - 1);	
	}
	cout << answer << "\n";
	return 0;
}