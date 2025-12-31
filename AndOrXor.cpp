#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long a, b;
        cin >> a >> b;
        if ((a & b) != a)
            cout << -1 << "\n";
        else
            cout << (a ^ b) << "\n";
    }
    return 0;
}