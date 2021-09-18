#include <bits/stdc++.h>

using namespace std;

int dividAdd(int num){
	int ret = num;
	while(num){
		ret += num % 10;
		num /= 10;
	}
	return ret;
}

int main(void){
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		if(dividAdd(i) == N) { cout << i << "\n"; return 0; }
	}
	cout << "0\n";
	return 0;
}