#include <stdio.h>


int main(void){
	int n;
	int seat[100]={};
	int ref=0;
	int gues;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		
		
		scanf("%d",&gues);
		
		if(!seat[gues])
			ref++;
		
	}
	
	
	printf("%d", ref);
	
	
	
	return 0;
}