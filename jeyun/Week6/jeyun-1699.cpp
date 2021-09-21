#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N,term = 0;
    cin >> N;
    
    while (N > 0)
    {
        N -= (int)pow((int)sqrt((double)N), 2);
        term++;
    }
    cout << term;
}
