#include <iostream>
using namespace std;

int main()
{
	int n;
	int map[101][101];
	long long dp[100][100];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d",&map[i][j]);
	dp[0][0] = 1;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]==0) continue;
			
			if(dp[i][j]!=0){
				if(i+map[i][j]<n)
					dp[i+map[i][j]][j]+=dp[i][j];
				if(j+map[i][j]<n)
					dp[i][j+map[i][j]]+=dp[i][j];
			}
		}
	}
	printf("%lld",dp[n-1][n-1]);
	return 0;
}