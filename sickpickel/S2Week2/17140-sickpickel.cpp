#include <bits/stdc++.h>
#define Max 101

using namespace std;

int matrix[Max][Max];
int row_size = 3, col_size = 3;

int newSort(int * count){
	vector<pair<int, int>> tosort;
	for(int i = 1; i < Max; i++){
		if(count[i]) tosort.push_back({count[i], i});
		count[i] = 0;
	}	
	sort(tosort.begin(), tosort.end());
	for(int i = 0; i < tosort.size() && 2 * i < 100; i++){
		count[2 * i] = tosort[i].second;
		count[2 * i + 1] = tosort[i].first; 
	}
	return tosort.size() * 2;
}

void calculateC(){
	int new_row_size = 0, max_row_size = 0;
	for(int i = 0; i < col_size; i++){
		int count[Max] = {};
		for(int j = 0; j < row_size; j++){
			count[matrix[j][i]]++;
			matrix[j][i] = 0;
		}
		new_row_size = min(100, newSort(count));
		for(int j = 0; j < new_row_size; j++){
			matrix[j][i] = count[j];
		}
		max_row_size = max(max_row_size, new_row_size);
	}
	row_size = max_row_size;
}

void calculateR(){
	int new_col_size = 0, max_col_size = 0;
	for(int i = 0; i < row_size; i++){
		int count[Max] = {};
		for(int j = 0; j < col_size; j++){
			count[matrix[i][j]]++;	
			matrix[i][j] = 0;
		}
		new_col_size = min(100, newSort(count));
		for(int j = 0; j < new_col_size; j++){
			matrix[i][j] = count[j];	
		}
		max_col_size = max(max_col_size, new_col_size);
	}
	col_size = max_col_size;
}

void printMatrix(){
	for(int i = 0; i < row_size; i++){
		for(int j = 0; j < col_size; j++){
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(void){
	int r, c, k, answer, flag = 0;
	cin >> r >> c >> k;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> matrix[i][j];
		}
	}
	r--; c--;	
	for(answer = 0; answer <= 100; answer++){
		if(matrix[r][c] == k) {flag = 1; break;}
		if(row_size >= col_size){
			calculateR();
		}	
		else calculateC();
		// printMatrix();
	}
	if(flag) cout << answer << "\n";
	else cout << "-1\n";

	return 0;
}