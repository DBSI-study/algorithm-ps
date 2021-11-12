#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	ll x;
	ll result=0;
	priority_queue<ll, vector<ll>, greater<ll>> numbers;

	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		numbers.push(x);
	}

	while(numbers.size()!=1){
		ll sum_tmp=0;
		
		for(int i=0;i<2;i++){
			sum_tmp+=numbers.top();
			numbers.pop();
		}

		result+=sum_tmp;
		numbers.push(sum_tmp);
	}
	cout<<result;
}

