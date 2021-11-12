#include <bits/stdc++.h>
#define Max 101

using namespace std;

int arr[Max];

int main(void){
	int N, input, ans = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> input;
		if(arr[input] != 0) ans++;
		else arr[input] = 1;
	}
	cout << ans << "\n";
	return 0;
}