#include <iostream>
#include <string>

using namespace std;
int jarisuHap(int n)
{
    int result = 0;
    string str = to_string(n);

    for (int i=0;i<str.size();i++)
        result += str[i] - '0';
    return result;
}

int main()
{
    bool found = false;
    int N,size,result;
    string Nstring;

    cin >> N;
    Nstring = to_string(N);
    size = Nstring.size();
    if (size > 1)
        size -= 1;

    while (size > 0)
    {
        result = N;
        result -= 9*(size);
        for (int i=result;i<N;i++)
        {
            if (i + jarisuHap(i) == N)
            {
                found  = true;
                cout << i;
                break;
            }
        }
        if (!found)
        {
            if (size == Nstring.size())
            {
                cout << 0;
                break;
            }
            size++;
        }
        else
            break;
    }
}
