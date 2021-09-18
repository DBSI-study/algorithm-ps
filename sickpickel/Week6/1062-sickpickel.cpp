#include <bits/stdc++.h>

using namespace std;

int N, K, answer = 0;
vector<int> words;
vector<char> needtolearn;

int countPossibleWords(int picked){
	int ret = 0;
	for(int word : words){
		if((picked & word) == word) ret++;
	}	
	return ret;
}

void backtracking(int cnt, int idx, int mask){
	if(cnt == K){
		answer = max(answer, countPossibleWords(mask));
		return;
	}
	if(idx == needtolearn.size()) return;
	
	backtracking(cnt + 1, idx + 1, mask | 1 << needtolearn[idx] - 'a');
	backtracking(cnt, idx + 1, mask & ~(1 << needtolearn[idx] - 'a'));
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> K;
	string word;
	int alphabet = 0;
	for(int i = 0; i < N; i++){
		cin >> word;
		int temp = 0;
		for(char alpha : word){
			temp |= 1 << alpha - 'a';
		}
		alphabet |= temp;
		words.push_back(temp);
	}

	int defaultmask = (1 << 0) | (1 << 'c' - 'a') | (1 << 'n' - 'a') | (1 << 'i' - 'a') | (1 << 't' - 'a');
	
	for(int i = 0; i < 26; i++){
		if(defaultmask & (1 << i)) continue;
		if(alphabet & (1 << i)) needtolearn.push_back('a' + i);
	}
	if(K < 5) { cout << "0\n"; return 0; }
	if(needtolearn.size() + 5 <= K) {cout << N << "\n"; return 0;}

	backtracking(5, 0, defaultmask);

	cout << answer << "\n";	
	return 0;
}