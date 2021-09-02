#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int stu[1001][6];
	bool check[6];
	int n,x,cnt,max_count=0,captain;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			scanf("%d",&x);
			stu[i][j]=x;
		}
	}
	for(int i=n;i>=1;i--){
		cnt=0;
		memset(check,false,sizeof(check));
		
		for(int k=1;k<=n;k++){
			if(i==k) continue;
			for(int j=1;j<=5;j++)	
				if(stu[k][j]==stu[i][j])
					check[k]=true;
		}
		
		for(int j=1;j<=n;j++)
			if(check[j])
				cnt++;
		
		if(cnt>=max_count){
			max_count=cnt;
			captain=i;
		}
	}
	printf("%d",captain);
}