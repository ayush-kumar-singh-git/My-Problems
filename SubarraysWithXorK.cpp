#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, K;
        cin >> n >> K;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<int, int> mp;
        mp[0] = 1;
        int currXor = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            currXor ^= v[i];
            ans += mp[currXor ^ K];
            mp[currXor]++;
        }
        cout << ans << "\n";
    }
    return 0;
}