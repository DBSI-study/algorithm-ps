// DDR
#include <bits/stdc++.h>
#define Max 100000

using namespace std;

int N;
int sequence[Max];
int dp[Max][5][5];

int getdistance(int A, int B){
	if(A == B) return 1;
	if(A == 0 || B == 0) return 2;
	if(abs(A - B) == 2) return 4;
	return 3;	
}

void swap(int * a, int * b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int getMinForce(int left, int right, int now){
	if(now == N) {
		return 0;
	}
	if(left > right) swap(&left, &right);
	
	int &ref = dp[now][left][right];
	if(ref != 0) return ref;

	int leftmin = getMinForce(sequence[now], right, now + 1) + getdistance(left, sequence[now]);
	int rightmin = getMinForce(left, sequence[now], now + 1) + getdistance(right, sequence[now]);
	
	ref = min(leftmin, rightmin);
	return ref;	
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int input;
	for(N = 0; ; N++){
		cin >> input;	
		if(input == 0) break;
		sequence[N] = input;
	}
	
	cout << getMinForce(0, 0, 0) << "\n";
	return 0;
}