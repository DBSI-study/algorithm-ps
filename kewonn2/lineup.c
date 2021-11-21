lineup.c

#include <stdio.h>


int main(void){
	int taller[10]={};
	int line[10]={};
	int n;
	
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &taller[i]);
	
	for(int i=0;i<n;i++){
		int where=0;
		

		while(line[where]||taller[i]){
			if(line[where]==0)
				taller[i]--;
			where++;
			
		}
		line[where]=i+1;
		
	}
						   
						   
						   
	for(int i=0;i<n;i++)
	printf("%d ", line[i]);
						   printf("\n");
	return 0;
}