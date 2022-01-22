#include <iostream>
#include <algorithm>
using namespace std;

int arr[40001];
int lis[40001];
int pointer=0;

int binary(int value){ // lis배열에서 원소 교체 가능한 적정 index를 return
	int l=0,r=pointer;
	int idx;
	
	while(l<=r){
		int mid=(l+r)/2;
		if(lis[mid]>=value){
			idx=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return idx;
}

int main()
{
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	lis[0]=arr[0];
	
	for(int i=1;i<n;i++){
		if(arr[i]>=lis[pointer]) // lis의 이전 원소보다 클 경우 추가해줌.
			lis[++pointer]=arr[i];
		else
			lis[binary(arr[i])]=arr[i];
	}
	cout<<pointer+1;	
}