// 설탕배달
#include <bits/stdc++.h>

using namespace std;

int main(void){
	int N; cin >> N;
	for(int cnt5kg = N / 5; cnt5kg >= 0; cnt5kg--){
		int left = N - cnt5kg * 5;
		if(left % 3 == 0) {cout << cnt5kg + left / 3 << "\n"; return 0;}
	}
	cout << "-1\n";
	return 0;
}