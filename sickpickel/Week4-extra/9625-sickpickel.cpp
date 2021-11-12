#include <bits/stdc++.h>

using namespace std;

int main(void){
	int Acnt = 1, Bcnt = 0;
	int K;
	cin >> K;
	for(int i = 0; i < K; i++){
		int beforeA = Acnt, beforeB = Bcnt;
		Acnt = beforeB;
		Bcnt = beforeA + beforeB;
	}
	cout << Acnt << " " << Bcnt << "\n";
	return 0;
}