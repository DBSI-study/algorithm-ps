
#include <stdio.h>
void swap(int* a, int* b){
	
	int k;
	k=*b;
	
	*b=*a;
	*a=k;

	return;
}

void flip(int* playboard, int* playboardcpy, int i, int j){
	
	for(i;i<j;i++){
		swap(playboardcpy+playboard[i-1], playboardcpy+playboard[j-1]);

		swap(playboard+i-1,playboard+j-1);
		
		j--;
	}

	
}


int main(void){
	
	int n;
	int playboard[10000];
	int playboard2[10000];
	int playboardcpy[10001];
	int playboardcpy2[10001];
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		
		scanf("%d", playboard+i);
		playboard2[i]=playboard[i];
		playboardcpy[playboard[i]]=i+1;
		playboardcpy2[playboard[i]]=i+1;
	}
	int a,b;
	int arr[4]={1,1,1,1};
	int k;
	for(int j=0;j<2;j++){
	for(k=0;k<n;k++){
		if(playboard[k]==k+1){
	
			continue;
		}
		
		arr[j*2]=k+1;
		arr[j*2+1]=playboardcpy[k+1];
		flip(playboard, playboardcpy, arr[j*2], arr[j*2+1]);
		
		break;
	}
	
	}
	for(int i=0;i<n;i++)
		if(playboard[i]!=i+1)
		{	arr[0]=1;
		arr[1]=1;
		arr[2]=1;
		arr[3]=1;
			// printf("wrong!\n");
			for(int j=0;j<2;j++){
			for(k=n-1;k>=0;k--){
				if(playboard2[k]==k+1){
					continue;
				}
				arr[j*2]=k+1;
				arr[j*2+1]=playboardcpy2[k+1];
				if(arr[j*2]>arr[j*2+1]){
					swap(arr+j*2, arr+j*2+1);
				}
				flip(playboard2, playboardcpy2, arr[j*2], arr[j*2+1]);
				break;
			}}
			break;
		}
		printf("%d %d\n", arr[0], arr[1]);
		printf("%d %d\n", arr[2], arr[3]);
	return 0;
}