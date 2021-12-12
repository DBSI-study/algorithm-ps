#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
 
int main() {
	int time[100001];
	int from[100001]; //이전 위치를 저장하는 배열.
	bool visited[100001];
	queue<int> q;
	stack<int> route;
    int subin, bro;
    cin >> subin >> bro;
    time[subin] = 0;
    visited[subin] = true;

    q.push(subin);
 
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
 
		if (tmp - 1 >= 0 && !visited[tmp - 1]) {
            visited[tmp - 1] = true;
            time[tmp - 1] = time[tmp] + 1;
            from[tmp - 1] = tmp;
            q.push(tmp - 1);
        }
		
        if (tmp + 1 <= 100000 && !visited[tmp + 1]) {
            visited[tmp + 1] = true;
            time[tmp + 1] = time[tmp] + 1;
            from[tmp + 1] = tmp;
            q.push(tmp + 1);
        }
        
        if (tmp * 2 <= 100000 && !visited[tmp * 2]) {
            visited[tmp * 2] = true;
            time[tmp * 2] = time[tmp] + 1;
            from[tmp * 2] = tmp;
            q.push(tmp * 2);
        }
		if(tmp==bro) break;
    }
    cout << time[bro] << endl;
 
    int now = bro;
    route.push(bro);
    while (now != subin) {
        now = from[now];
        route.push(now);
    }
	
	while(!route.empty()){
		cout<<route.top()<<" ";
		route.pop();
	}
}
