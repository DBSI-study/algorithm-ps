#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int r, c, k;
int row = 3, col = 3;
int arr[100][100]; 

int main() {
	
	cin >> r >> c >> k;
	int nowSecond = 0;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin>>arr[i][j];
	
	while(arr[r-1][c-1]!=k){
		nowSecond++; 
		if (nowSecond > 100) {
			cout << -1; 
			return 0;
		}
		
		vector<pair<int, int>> v[100];
		
		if (row >= col) { 
			for (int i = 0; i < row; i++) {
				int counting_sort[101] = { 0, }; 
				
				for (int j = 0; j < col; j++)
					counting_sort[arr[i][j]]++;
				
				for(int j=1; j<=100; j++) 
					if(counting_sort[j]) 
						v[i].push_back({ counting_sort[j], j });
			} 
			
			for (int i = 0; i < row; i++) 
				for (int j = 0; j < col; j++)
					arr[i][j] = 0; 
			
			for (int i = 0; i < row; i++)
				sort(v[i].begin(), v[i].end()); 
			
			for (int i = 0; i < row; i++) {
				int k = 0; 
				
				for (int j = 0; j < v[i].size(); j++) { 
					if (k == 100) break; 
					arr[i][k++] = v[i][j].second; 
					arr[i][k++] = v[i][j].first;
				} 
				col = col > k ? col : k;
			} 
		}
		
		else 
		{ 
			for (int i = 0; i < col; i++) {
				int counting_sort[101] = { 0, };
				
				for (int j = 0; j < row; j++) 
					counting_sort[arr[j][i]]++; 
				
				for (int j = 1; j <= 100; j++) 
					if (counting_sort[j]) 
						v[i].push_back({ counting_sort[j], j });
			} 
			
			for (int i = 0; i < row; i++) 
				for (int j = 0; j < col; j++) 
					arr[i][j] = 0; 
			
			for (int i = 0; i < col; i++) 
				sort(v[i].begin(), v[i].end());
			
			for (int i = 0; i < col; i++) { 
				int k = 0; 
				
				for (int j = 0; j < v[i].size(); j++) {
					if (k == 100) break;
					arr[k++][i] = v[i][j].second;
					arr[k++][i] = v[i][j].first; 
				} 
				row= row > k ? row : k;
			} 
		}
	} 
	cout << nowSecond;
}