#include <bits/stdc++.h>

using namespace std;

vector<string> street;

int main(void){
	int R, C;
	cin >> R >> C;
	string input;
	for(int i = 0; i < R; i++){
		getline(cin, input);
		street.push_back(input);
	}
	
	int answer = 0;	
	for(int i = 0; i < R; i++){
		int nowI = i;
		int nowJ = 0;
		while(nowI < R && nowJ < C){
			if(street[nowI][nowJ + 1] != 'x') {
				street[nowI][nowJ + 1] = 'x';
				nowJ++;
				continue;
			}	
			if(nowI + 1 < R && street[nowI + 1][nowJ + 1] != 'x'){
				street[nowI + 1][nowJ + 1] = 'x';
				nowI++; nowJ++;
				continue;
			}
			break;
		}	
		if(nowJ == C - 1){
			answer++;
		}
	}
	cout << answer << "\n";	
	return 0;
}