matrix.c

#include <stdio.h>
#include <math.h>



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

int main(void){
	int r, c, k;
	int arr[1000][1000]={};
	scanf("%d %d %d", &r, &c, &k);
	int row=3;
	int col=3;
	

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%d", &arr[j][i]);
			
		}
	}
	

	int cnt[101]={};
	int howmany=0;
	int rowmax=0, colmax=0;
	int kk=0;
	while(arr[c-1][r-1]!=k&&kk<=100){
		
		
	if(row>=col){
	
		for(int i=0;i<=row-1;i++){
			for(int j=0;j<col;j++){
				if(arr[j][i])
				cnt[arr[j][i]]++;
				
				
				
				
			}
			
			for(int j=0;j<1000;j++){
				arr[j][i]=0;
				
				
				
				
			}
			for(int num=1;num<=100;num++){
					
					for(int cntnum=1;cntnum<=100;cntnum++){
						if(cnt[cntnum]==num){
							
							arr[2*howmany][i]=cntnum;
							arr[2*howmany+1][i]=num;
							
							howmany++;
							
						}
						
					}
					
			}
			
	
	
			
			for(int ii=0;ii<=100;ii++){
				cnt[ii]=0;
			}
			
		
			if(howmany*2>colmax)
				colmax=howmany*2;
			
			howmany=0;
			
		}
		int coll=min(colmax, 100);
		col=max(col, coll);
		colmax=0;
		
	}
	else{
		
		
		for(int j=0;j<=col-1;j++){
		for(int i=0;i<row;i++){
			if(arr[j][i])
				cnt[arr[j][i]]++;
				
				
				
				
			}
			for(int i=999;i>=0;i--){
			
				arr[j][i]=0;
				
				
				
				
			}
			for(int num=1;num<=100;num++){
					
					for(int cntnum=1;cntnum<=100;cntnum++){
						if(cnt[cntnum]==num){
							arr[j][2*howmany]=cntnum;
							arr[j][2*howmany+1]=num;
							
							
							howmany++;
							
						}
						
					}
				
					
			}
			for(int ii=0;ii<=100;ii++){
				cnt[ii]=0;
			}
			
			if(howmany*2>rowmax)
				rowmax=howmany*2;
				
			
			howmany=0;
			
			
		}
		int roww=min(rowmax, 100);
		row=max(row, roww);
		
		rowmax=0;
		
		
	}
		
		kk++;
		
		
	}
		
	if(kk==101&&arr[c-1][r-1]!=k)
		printf("-1");
	else
	printf("%d\n", kk);
	return 0;
}