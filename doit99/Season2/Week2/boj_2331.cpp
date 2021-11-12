#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
 
vector<int> vec;
int a,p,start,ans;
 
void next_num(int num, int cnt) {
	vec.push_back(num);
 
    int n = num;
    int next = 0;
    while (true) {
        next += pow(n % 10, p);
        n /= 10;
        if (!n) break;
    }
 
    if (find(vec.begin(),vec.end(),next) != vec.end()) //중복되는 수가 이미 존재하면.
	{
        start = next;
        if (num == start)//연속으로 등장하는 경우
			ans=cnt-1;
        return;
    }
    next_num(next, cnt + 1);
    if (num == start)
    	ans=cnt-1;
	
}
 
int main() {
    cin >> a >> p;
    next_num(a, 1);
    cout << ans;
}