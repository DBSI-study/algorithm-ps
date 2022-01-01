#include <iostream>
using namespace std;

int main(){
	int n;
	int arr[5001];
	scanf("%d",&n);
	arr[n]=-1;
	
	for(int i=0;i<=n;i+=5){
		for(int j=0;j<=n;j+=3){
			if(i+j>n) break;
			arr[i+j]=i/5+j/3;
		}
	}
	printf("%d",arr[n]);
}