#include <bits/stdc++.h>
#define Max 51

using namespace std;

int N, M;
int A[Max][Max], B[Max][Max];

void Calculate(int x, int y){
	for(int i = x; i < x + 3; i++){
		for(int j = y; j < y + 3; j++){
			(A[i][j] += 1) %= 2;
		}
	}
}

int main(void){
	
	char input;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> input;	
			A[i][j] = input - '0';
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> input;	
			B[i][j] = input - '0';
		}
	}
	
	if(N < 3 || M < 3){
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(A[i][j] != B[i][j]) {cout << "-1\n"; return 0;}
			}
		}	
		cout << "0\n"; return 0;
	}
	int flag = 1, answer = 0;
	for(int i = 0; i < N - 2; i++){
		for(int j = 0; j < M - 2; j++){
			if(A[i][j] == B[i][j]) continue;
			answer++;
			Calculate(i, j);
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(A[i][j] != B[i][j]) {flag = 0; break;}
		}
	}
	if(flag) cout << answer << "\n";
	else cout << "-1\n";
	
	return 0;
}