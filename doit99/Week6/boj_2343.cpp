#include <iostream>
#include<algorithm>
using namespace std;

int a[100001], n;

int count(int s){
	int cnt=1, sum=0;
	for(int i=1; i<=n; i++){
		if(sum+a[i]>s){
			cnt++;
			sum=a[i];
		}
		else sum=sum+a[i];
	}
	return cnt;
}

int main(){
	int m, l=1, r=0;
	int mid, res, maxx=0;
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		r+=a[i];
		if(a[i]>maxx)
			maxx=a[i];
	}
	
	while(l<=r){
		mid=(l+r)/2; // mid : 블루레이의 크기
		if(mid>=maxx && count(mid)<=m){	// mid 값이 항상 가장 긴 영상보다는 커야함
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d", res);
}