#include <bits/stdc++.h>

using namespace std;

const int MAX_ARR = 250000;
int visited[MAX_ARR];

int getNow(int before, int P){
    int ret = 0;
    while(before){
        ret += pow((before % 10), P);
        before /= 10;
    }
    return ret;
}

int main(void){
    int A, P, before, notRepeatCnt;
    cin >> A >> P;
    before = A;
    visited[A] = 1;
    for(int i = 2; ; i++){
        int now = getNow(before, P);
        if(!visited[now]) visited[now] = i;
        else{
            notRepeatCnt = visited[now] - 1;
            break;
        }
        before = now;
    }
    cout << notRepeatCnt << "\n";
    return 0;
}