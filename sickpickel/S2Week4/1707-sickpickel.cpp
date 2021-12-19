#include <bits/stdc++.h>
#define pii pair<int, int>
#define Max 20001

using namespace std;
vector<int> graph[Max];

int bfs(int* visited, int start){
    queue<pii>q;
    q.push({start, 1});
    visited[start] = 1;
    while(!q.empty()){
        int now = q.front().first;
        int group = q.front().second;
        q.pop();

        for(int next : graph[now]){
            if(visited[next] != 0) {
                if(visited[next] == group) return 0;
                continue;
            }
            visited[next] = group * -1;
            q.push({next, group * -1});
        }
    }
    return 1;
}

void solve(){
    int visited[Max] = {};
    int V, E, u, v;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int flag = 1;
    for(int i = 1; i <= V; i++){
        if(visited[i]) continue;
        if(!bfs(visited, i)) {flag = 0; break;}
    }
    for(int i = 1; i <= V; i++){
        graph[i].clear();
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int K; cin >> K;
    while(K--) solve();
    return 0;
}