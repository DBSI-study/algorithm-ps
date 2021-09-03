#include <iostream>
using namespace std;

int n,cnt=0;
int map[101][101];
int dp[101][101];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	
	int y=0,x=0;
	bool flag=false;
	while(y<n)
	{
		while(x<n)
		{
			printf("now y,x : (%d,%d)\n",y,x);
			x+=map[y][x];
			dp[y][x+map[y][x]]=1;
			if(map[y][x]==0){
				flag=true;
				break;
			}
		}
		if(flag) break;
		x=0;
		y+=map[y][x];
		dp[y+map[y][x]][x]++;
	}
	

	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%d ",dp[i][j]);
		printf("\n");
	}
	
	printf("%d",cnt);
	
	
	
}