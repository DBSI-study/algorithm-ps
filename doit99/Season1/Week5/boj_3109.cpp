#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int y_dir[3]={-1,0,1};
string map[10001];
bool visited[10001][501];
int r,c,cnt=0;
bool flag;

void DFS(int y, int x)
{
	if(flag) return;
	visited[y][x]=true;
	
	if(x==c-1){
		cnt++;
		flag=true;
		return;
	}
	
	for(int i=0;i<3;i++)
	{
		int ny=y+y_dir[i];
		if(x<c-1 && ny>=0 && ny<r){
			if(!visited[ny][x+1] && map[ny][x+1] =='.')
				DFS(ny,x+1);
		}
	}
}
int main()
{
	memset(visited,false,sizeof(visited));
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++)
		cin>>map[i];	
	
	for(int i=0;i<r;i++){
		visited[i][0]=true;
		flag=false;
		DFS(i,0);
	}
	printf("%d",cnt);
}