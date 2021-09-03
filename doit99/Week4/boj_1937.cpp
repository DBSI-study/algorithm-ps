#include <iostream>
using namespace std;

int x_arr[]={0,1,0,-1};
int y_arr[]={1,0,-1,0};
int n,ans=0;
int map[501][501];
int dp[501][501];

int DFS(int y, int x)
{
	if (dp[y][x] != 0)
		return dp[y][x];
	
	dp[y][x]=1;
	for(int i=0;i<4;i++){
		int ny=y+y_arr[i];
		int nx=x+x_arr[i];
		
		if(map[ny][nx]>map[y][x] && nx>=0 && ny>=0 && nx<n && ny<n)
			dp[y][x]=max(dp[y][x],DFS(ny,nx)+1);
	}
	return dp[y][x];
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ans=max(ans,DFS(i,j));
	
	printf("%d",ans);
}