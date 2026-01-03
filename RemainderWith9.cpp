#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        n = n * (n + 1);
        n /= 2;
        cout << (n % 9) << "\n";
    }
    return 0;
}