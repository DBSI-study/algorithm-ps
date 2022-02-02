#include <bits/stdc++.h>
#define Max 102

using namespace std;

vector<string> s;
int dp[Max][Max][Max];

void getLCSlen(string word1, string word2, string word3){
	int len1 = word1.length(), len2 = word2.length(), len3 = word3.length();	
	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			for(int k = 1; k <= len3; k++){
				dp[i][j][k] = max(dp[i][j][k - 1], max(dp[i][j - 1][k], dp[i - 1][j][k]));
				if(word1[i] == word2[j] && word2[j] == word3[k])  
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int len[3] = {};
	string input;
	for(int i = 0; i < 3; i++){
		cin >> input;
		len[i] = input.length();
		s.push_back('_' + input);
	}
	
	getLCSlen(s[0], s[1], s[2]);

	cout << dp[len[0]][len[1]][len[2]] << "\n";
	return 0;
}