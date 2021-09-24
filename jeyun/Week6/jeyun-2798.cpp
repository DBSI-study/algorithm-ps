#include <iostream>

using namespace std;

int main()
{
    bool exit = false;
    int N,M,result = 0,arr[100];
    
    cin >> N >> M;
    for (int i=0;i<N;i++)
        cin >> arr[i];

    for (int i=0;i<N;i++)
    {
        for (int j=i+1;j<N;j++)
        {
            for (int k=j+1;k<N;k++)
            {
                if (arr[i] + arr[j] + arr[k] <= M && arr[i] + arr[j] + arr[k] > result)
                    result = arr[i] + arr[j] + arr[k];
                if (result == M)
                {
                    exit = true;
                    break;
                }
            }
            if (exit)
                break;
        }
        if (exit)
            break;
    }
    cout << result;
}
