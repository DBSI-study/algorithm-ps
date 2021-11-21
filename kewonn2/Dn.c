Dn.c

#include <stdio.h>
#include <math.h>


int cal(int num, int p){
	int sum=0;
	while(num>0){
		sum+=pow(num%10, p);
		num/=10;
		
	}
	return sum;
}

int main(void){
	int a, p;
	int dn[295000];
	
	scanf("%d %d", &a, &p);
	
	
	int cnt=0;
	int cnt2;
	int i=a;
	do{
		dn[i]++;
		if(dn[i]==1)
			cnt2++;
		if(dn[i]==2)
		{cnt++;}
		
		i=cal(i, p);
		
		
		}
	while(dn[i]<3);
	
	printf("%d\n", cnt2-cnt);
	return 0;
}