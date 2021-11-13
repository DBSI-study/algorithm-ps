#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 10001;

int main(void){
    int T, N, TC_CNT;
    ifstream myanswer, mixedArr;
    myanswer.open("myanswer.txt");
    mixedArr.open("tc.txt");
    int inputs[4];
    mixedArr >> T;
    TC_CNT = T;
    while(T--){
        int arr[MAX_LEN];
        int flag = 1;
        for(int i = 0; i < 4; i++){
            myanswer >> inputs[i];
            inputs[i]--;
        }
        
        mixedArr >> N;
        for(int i = 0; i < N; i++){
            mixedArr >> arr[i];
        }
        if(inputs[0] == -2) {
            cout << "TC #" << TC_CNT - T << " : " << "FailedToCal!!!\n";
            continue;
        }
        reverse(arr + inputs[0], arr + inputs[1] + 1);
        reverse(arr + inputs[2], arr + inputs[3] + 1);

        for(int i = 0; i < N; i++){
            if(arr[i] != i + 1) flag = 0;
        }
        cout << "\n";
        
        if(flag) {cout << "TC #" << TC_CNT - T << " : " << "Accepted\n"; }
        else {
            cout << "TC #" << TC_CNT - T << " : " << "Wrong!!!!!!!!\n"; 
            for(int i = 0; i < N; i++){
                if(arr[i] != i + 1) { 
                    if(i != 0) cout << arr[i - 1] << " ";
                    cout << arr[i] << " "; 
                    if(i != N - 1) cout << arr[i + 1] << " ";
                    if(i != 0) cout << i - 1 << " ";
                    cout << arr[i] << " "; 
                    if(i != N - 1) cout << i + 1 << " ";
                } 
                cout << "\n";
            }
        }

    }
    system("pause");
}