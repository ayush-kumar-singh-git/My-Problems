#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        vector<long long> ps(n + 1, 0);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            ps[i + 1] = ps[i] + b[i];
            mp[b[i]] = i;
        }
        for (int x : a)
        {
            int idx = mp[x];
            long long score = 0;
            score += (1LL * (2 * idx + 1 - n)) * x - ps[idx] + ps[n] - ps[idx + 1];
            cout << score << " ";
        }
        cout << "\n";
    }
    return 0;
}