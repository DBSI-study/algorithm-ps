#include <stdio.h>


int main(void){
	int n;
	int seat[101]={};
	int ref=0;
	int gues;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		
		
		scanf("%d",&gues);
		
		if(seat[gues])
			ref++;
		else
			seat[gues]=1;
	}
	
	
	printf("%d", ref);
	
	
	
	return 0;
}