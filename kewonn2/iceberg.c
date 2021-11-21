icemelt.c
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int max(int a, int b){
	if(a<=b)
		return b;
	else
		return a;
}


int min(int a, int b){
	if(a>=b)
		return b;
	else
		return a;
}

void dfs(int a[1000][1000], int x, int y){
	int n, e, w, s;
	if(a[y][x]==0)
		return;
	a[y][x]=0;
	
	if(a[y+1][x]!=0)
		dfs(a, x, y+1);
	if(y-1>=0&&a[y-1][x]!=0)
		dfs(a, x, y-1);
	if(a[y][x+1]!=0)
		dfs(a, x+1, y);
	if(x-1>=0&&a[y][x-1]!=0)
		dfs(a, x-1, y);
	
	   return;
	   }
	


void check(int a[1000][1000], int x, int y, int b[1000][1000]){
	
	b[y][x]=a[y][x];
	if(a[y+1][x]==0)
		b[y][x]--;
	if(y-1>=0&&a[y-1][x]==0)
		b[y][x]--;
	if(a[y][x+1]==0)
		b[y][x]--;
	if(x-1>=0&&a[y][x-1]==0)
		b[y][x]--;
	if(b[y][x]<0)
		b[y][x]=0;
	   return;
	   }

int main(void){
	int n, m;
	int a[1000][1000]={};
	int b[1000][1000]={};
	scanf("%d %d", &n, &m);
	int row=n;
	int col=m;
	bool melt=true;
	bool allmelt=false;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			scanf("%d", &a[j][i]);
			b[j][i]=a[j][i];
		}
	}
	int year=0;
	bool melttrue=false;
	while(melt&&!allmelt){
		for(int i=0; i<row;i++){
			for(int j=0; j<col;j++){
				check(a, i, j, b);
				
				
			}
		}
		
		for(int i=0; i<row;i++){
			for(int j=0; j<col;j++){
				a[j][i]=b[j][i];
				
				
			}
		}
		int k=0;
		int out=0;
		for(int i=0; i<row;i++){
			for(int j=0; j<col;j++){
				if(b[j][i]!=0)
					{dfs(b, i, j);
					out=1;
					 break;
					}
				
			}
			if(out)
				break;
		}
	
		allmelt=false;
		for(int i=0; i<row;i++){
			for(int j=0; j<col;j++){
				
				if(b[j][i]!=0){
					
					melt=false;
					
				}
			}
		}
		int kkk=0;
		for(int i=0; i<row;i++){
			for(int j=0; j<col;j++){
				if(a[j][i]!=0)
					kkk=1;
			}
		}
		if(kkk==0)
			allmelt=true;
		year++;
		
	}
	for(int i=0; i<row;i++){
			for(int j=0; j<col;j++){
				if(a[j][i]!=0){
					
					melttrue=true;
					break;
				}
			}
		}
	if(!allmelt)
		printf("%d\n", year);
	else
		printf("0\n");
	
	return 0;
}