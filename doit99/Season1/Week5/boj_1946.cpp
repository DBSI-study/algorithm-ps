#include <iostream>
#include <algorithm>
using namespace std;

int t,n,cnt,check;
pair<int,int> p[100000];
int main() {
	scanf("%d",&t);
	
	for (int i = 0; i < t; i++) {
		cnt=0;
		scanf("%d",&n);
		for (int j = 0; j < n; j++) 
			scanf("%d %d",&p[j].first,&p[j].second);
		
		sort(p, p + n); 
		check = p[0].second;
		
		for (int i = 0; i < n; i++) {
			if (p[i].second <= check) {
				cnt++;
				check = p[i].second;
			}
		}
		
		printf("%d\n",cnt);
	}
	return 0;
} 