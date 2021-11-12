#include <iostream>
using namespace std;
  
int main() {
	int n;
	int arr[100001];
    scanf("%d",&n);
    
    for(int i = 1; i <= n; i++)
        arr[i] = i;
    
    for(int i = 2; i <= n; i++)
        for(int j = 2; j*j <= i; j++)
			arr[i]= (arr[i] <= arr[i-j*j]+1) ? arr[i] : arr[i-j*j]+1;
         
	printf("%d",arr[n]);
    return 0;
}