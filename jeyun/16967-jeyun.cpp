#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    int h,w,x,y,temp = 0;
    vector<vector<int>> A, B;
    vector<int> temp_v;
    
    cin >> h >> w >> x >> y;
    for (int i=0; i<h+x;i++)
    {
        for (int j=0;j<w+y;j++)
        {
            cin >> temp;
            temp_v.push_back(temp);
        }
        B.push_back(temp_v);
        temp_v.clear();
    }

    // A로 그대로 가져오는 부분
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<w;j++)
            temp_v.push_back(B[i][j]);

        A.push_back(temp_v);
        temp_v.clear();
    }
    // 일부는 A, 일부는 뺄셈
    for (int i=x;i<h;i++)
    {
        for (int j=0;j<y;j++)
            temp_v.push_back(B[i][j]);
        for (int j=y;j<w;j++)
            temp_v.push_back(B[i][j] - A[i-x][j-y]);

        A.push_back(temp_v);
        temp_v.clear();
    }
    
    for (int i=0;i<h;i++)
    {
        for (int j=0;j<w;j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}
