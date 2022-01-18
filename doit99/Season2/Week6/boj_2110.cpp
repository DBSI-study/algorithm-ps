#include <iostream>
#include <algorithm>
using namespace std;
int arr[200001];

int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    int n,c;
	int l=1,r;
	int ans=0;
	cin>>n>>c;
	for(int i=0;i<n;i++) 
		cin>>arr[i];
    sort(arr,arr+n);
	
	r=arr[n-1];
    
	while(l<=r){
        int cnt = 1;
        int mid = (r+l)/2;
        int start = arr[0];
        for(int i=1;i<n;i++)
            if(arr[i]-start>=mid){
				start=arr[i];
				cnt++;
			}
        if(cnt>=c){
			ans=mid;
			l=mid+1;
		}
        else r=mid-1;
    }
    cout<<ans;
}