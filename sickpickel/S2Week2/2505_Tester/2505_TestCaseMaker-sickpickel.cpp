#include <bits/stdc++.h>

using namespace std;

const int TC_CNT = 10000;
const int MAX_N_LEN = 10000;

int main(void){
    srand(time(NULL));
    int T = TC_CNT;
    ofstream tc_file, answer_file;
    tc_file.open("tc.txt");
    tc_file << T << "\n";
    while(T--){
        int N = rand() % (MAX_N_LEN - 5) + 5;
        tc_file << N << "\n";
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            arr[i] = i + 1;
        }
        int begin1 = rand() % N;
        int end1 = rand() % (N - begin1) + begin1;
        reverse(arr.begin() + begin1, arr.begin() + end1 + 1);
        
        int begin2 = rand() % N;
        int end2 = rand() % (N - begin2) + begin2;
        reverse(arr.begin() + begin2, arr.begin() + end2 + 1);
        for(int i = 0; i < N; i++){
            tc_file << arr[i] << " ";
        }
        tc_file << "\n";
    }
}