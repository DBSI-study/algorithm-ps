#include<iostream>
using namespace std;

int main()
{
    int n, result = 0;
    int v[1000][5];
    int count[1000]{};
    
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<5; j++)
            cin >> v[i][j];

    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            for (int k=0; k<5;k++)
            {
                if (v[i][k] == v[j][k])
                {
                    count[i]++;
                    count[j]++;
                    break;
                }
            }
        }
    }

    for (int i=0; i<n; i++)
        if (count[result] < count[i])
            result = i;

    cout << (result + 1);
}