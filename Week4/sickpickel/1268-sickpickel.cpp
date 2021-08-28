#include <bits/stdc++.h>
#define Max 1001

using namespace std;

int table[Max][6];
bool relation[Max][Max];
vector<int> vec[5][10];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 5; j++)	{
			cin >> table[i][j];
			vec[j][table[i][j]].push_back(i);
		}
	}	
	
	for(int i = 0; i < 5; i++){
		for(int j = 1; j < 10; j++){
			for(int k = 0, lim = vec[i][j].size(); k < lim - 1; k++){
				for(int p = k + 1; p < lim; p++){
					relation[vec[i][j][k]][vec[i][j][p]] = 1;
					relation[vec[i][j][p]][vec[i][j][k]] = 1;
				}
			}	
		}
	}

	int ans = 0, max_val = 0;	
	for(int i = 0; i < N; i++){
		int temp = 0;
		for(int j = 0; j < N; j++){
			temp += relation[i][j];	
		}
		if(max_val < temp) {
			max_val = temp;
			ans = i;	
		}
	}	
	cout << ans + 1 << "\n";
	return 0;
}