#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	int arr[100];
	int sum=0;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			for (int k = j + 1; k < n; k++) {
				int num = arr[i] + arr[j] + arr[k];

				if (abs(m - num) <= abs(m - sum) && num<=m)
					sum = num;
			}
		}
		
	}
	cout << sum;
	return 0;
}