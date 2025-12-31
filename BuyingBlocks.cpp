#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        long long M;
        cin >> n >> k >> M;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long currWinSum = 0;
        int l = 0;
        for (int r = 0; r < k; r++)
        {
            currWinSum += v[r];
        }
        long long minm = currWinSum;
        for (int r = k; r < n; r++)
        {
            currWinSum -= v[l];
            l++;
            currWinSum += v[r];
            minm = min(currWinSum, minm);
        }
        if (minm >= M)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}