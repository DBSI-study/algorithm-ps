#include <bits/stdc++.h>
#define Max 100001
#define INF 2000000001l

using namespace std;

typedef long long ll;

ll solution[Max];

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> solution[i];
	}
	
	sort(solution, solution + N);
	
	int left = 0, right = N - 1;	
	ll saveMin = INF;
	int saveLeft = left, saveRight = right;
	
	while(left < right){
		ll newSolution = solution[left] + solution[right];
		if(newSolution == 0)	{
			cout << solution[left] << " " << solution[right] << "\n";
			return 0;
		}
		else{
			// 저장
			if(abs(newSolution) < saveMin) {
				saveMin = abs(newSolution);
				saveLeft = left, saveRight = right;
			}
			if(newSolution < 0) left++;
			else right--;
		}
	}	
	cout << solution[saveLeft] << " " << solution[saveRight] << "\n";
	return 0;
}