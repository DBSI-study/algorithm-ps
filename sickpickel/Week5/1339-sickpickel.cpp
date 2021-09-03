#include <bits/stdc++.h>

using namespace std;

int main(void){
	
	int N;
	cin >> N;
	int cntAlpha[26] = {};
	vector<string> words(N);
	
	for(int i = 0; i < N; i++){
		cin >> words[i];
		
		for(int j = 0; j < words[i].size(); j++){
			cntAlpha[words[i][j] - 'A'] += pow(10, (words[i].size() - j - 1));
		}
	}
	vector<int> sorted;
	for(int i = 0; i < 26; i++){
		if(cntAlpha[i]) sorted.push_back(cntAlpha[i]);
	}
	sort(sorted.begin(), sorted.end(), greater<int>());
	int number = 9;
	int answer = 0;
	for(int elem: sorted){
		answer += number * elem;
		number--;
	}
	cout << answer << "\n";
	return 0;
}