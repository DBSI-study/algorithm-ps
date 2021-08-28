#include <bits/stdc++.h>
#define pii pair<int, int>
#define Max 22 

using namespace std;
typedef int (*parr)[Max];

int N;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
pii startPoint[4], endPoint[4];

void printBoard(parr board){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

int isinbound(int a, int b){
	if(a < 1 || b < 1 || a > N || b > N) return 0;
	return 1;
}

int setMoveI(int direc){
	return (dy[(direc+2)%4] == 0 ? 1 : dy[(direc+2)%4]);
}
int setMoveJ(int direc){
	return (dx[(direc+2)%4] == 0 ? 1 : dx[(direc+2)%4]);
}

void moveBoard(parr board, parr visited, int direc){
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) visited[i][j] = 0;
	
	// 보드의 원소를 옮기는 순서에 따른 시작과 끝 위치
	int startI = startPoint[direc].first;
	int startJ = startPoint[direc].second;
	int endI = endPoint[direc].first;
	int endJ = endPoint[direc].second;
	
	//옮기려는 원소의 위치를 이동시키는 변수
	int moveI = setMoveI(direc);
	int moveJ = setMoveJ(direc);
	
	//해당 원소의 이동하는 방향과 크기
	int direcI = dy[direc];
	int direcJ = dx[direc];
	
	for(int i = startI; i != endI + moveI; i += moveI){
		for(int j = startJ; j != endJ + moveJ; j += moveJ){
			int nowI = i, nowJ = j;
			int nextI = nowI + direcI;
			int nextJ = nowJ + direcJ;
			
			while(isinbound(nextI, nextJ) && board[nextI][nextJ] == 0) {
				nextI += direcI;
				nextJ += direcJ;
			}
			if((isinbound(nextI, nextJ) && board[nextI][nextJ] == board[i][j]) && !visited[nextI][nextJ]){
				visited[nextI][nextJ] = 1;
				nextI += direcI;
				nextJ += direcJ;
			}
			nowI = nextI - direcI; nowJ = nextJ - direcJ;	
			if(nowI != i || nowJ != j) {
				board[nowI][nowJ] += board[i][j];
				board[i][j] = 0;
			}
		}
	}
}

void copyArr(parr copyArr, parr Arr){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			copyArr[i][j] = Arr[i][j];
		}	
	}	
}

int board_max_value(parr board){
	int ret = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			ret = max(ret, board[i][j]);
		}
	}	
	return ret;
}

void backtracking(int cnt, int * panswer, parr board, parr visited){
	if(cnt == 5){
		*panswer = max(*panswer, board_max_value(board));
		// printBoard(board);
		return;
	}	
	int copyBoard[Max][Max];
	for(int direc = 0; direc < 4; direc++){
		copyArr(copyBoard, board);
		moveBoard(board, visited, direc);
		backtracking(cnt + 1, panswer, board, visited);
		copyArr(board, copyBoard);
	}	
}

void setStartEndPoints(int N){
	pii startTemp[4] = { {1, 1}, {1, 1}, {1, N}, {N, 1} };
	pii endTemp[4] = { {N, N}, {N, N}, {N, 1}, {1, N} };
	
	for(int i = 0; i < 4; i++) { 
		startPoint[i] = startTemp[i];
		endPoint[i] = endTemp[i];
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int board[Max][Max];
	int visited[Max][Max];
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> board[i][j];
		}
	}
	setStartEndPoints(N);

	int answer = 0;	
	backtracking(0, &answer, board, visited);
	cout << answer << "\n";
	
	return 0;
}