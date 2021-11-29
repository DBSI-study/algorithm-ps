#include <iostream> 
#include <queue> 
using namespace std;

int arr[101][101];
bool visited[101]={1,};
queue<int> q;

int main(){
	int pc_cnt,couple_cnt,res=0;
	cin >> pc_cnt >> couple_cnt; 
	for(int i=0;i<couple_cnt;i++) {
		int x,y; 
		cin >> x >> y; 
		arr[x][y]=arr[y][x]=1;
	} 
	
	q.push(1);
	visited[1]=true;
	
	while(!q.empty()) {
		int top = q.front();
		q.pop();
		
		for(int i=1;i<=pc_cnt;i++) {
			if(arr[top][i]==1 && visited[i]==false) { 
				q.push(i); 
				visited[i]=true;
				res++; 
			} 
		} 
	}
	cout << res; 
}