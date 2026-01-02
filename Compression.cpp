#include <bits/stdc++.h>
using namespace std;

bool ok(vector<int> &a, int n, int k)
{
    vector<vector<bool>> dp(201, vector<bool>(201, false));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int len = j - i + 1;

            if (len % 2 == 1)
                continue;
            if (abs(a[i] - a[j]) < k)
            {
                if (len == 2 || dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    continue;
                }
            }
            for (int m = i; m < j; m++)
            {
                if ((m - i + 1) % 2 == 0)
                {
                    if (dp[i][m] && dp[m + 1][j])
                    {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n % 2 == 1)
    {
        cout << -1 << "\n";
        return 0;
    }
    int l = 1, r = INT_MAX;
    int ans = 0;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (ok(v, n, m))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}