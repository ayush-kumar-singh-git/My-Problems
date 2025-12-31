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
        long long l = 1, r = n;
        long long ans = 0;
        while (l <= r)
        {
            long long m = l + (r - l) / 2;
            if (m * (m + 1) <= 2 * n)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}