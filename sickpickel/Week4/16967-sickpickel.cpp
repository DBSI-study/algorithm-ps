#include <bits/stdc++.h>
#define BMax 610
#define AMax 310

using namespace std;

int B[BMax][BMax];
int A[AMax][AMax];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int H, W, X, Y;
	cin >> H >> W >> X >> Y;
	for(int i = 0; i < H + X; i++){
		for(int j = 0; j < W + Y; j++){
			cin >> B[i][j];	
		}
	}
	
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(i >= X && j >= Y) cout << (A[i][j] = B[i][j] - A[i - X][j - Y]);
			else cout << (A[i][j] = B[i][j]);
			cout << " ";
		}	
		cout << "\n";
	}	
	
	return 0;
}