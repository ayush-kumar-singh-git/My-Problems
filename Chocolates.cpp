#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    long long totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        totalSum += v[i];
        v[i] = -1 * v[i];
    }
    long long currSum = 0, maxSum = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum = max(currSum, 0LL);
        currSum += v[i];
        maxSum = max(maxSum, currSum);
    }
    int len = n;
    // cout << maxSum << "\n";
    map<long long, int> mp;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (mp.count(sum - maxSum) != 0)
        {
            len = min(len, i - mp[sum - maxSum]);
        }
        mp[sum] = i;
    }
    if (maxSum <= 0)
    {
        cout << n << " " << totalSum << "\n";
    }
    else if (len == n)
    {
        int tgt = min(v[0], v[n - 1]);
        int cnt1 = 0, cnt2 = 0;
        long long tot = 0;
        for (int i = 0; i < n; i++)
        {
            if (tot + v[i] <= tgt)
            {
                tot += v[i];
                cnt1++;
            }
            else
            {
                break;
            }
        }
        tot = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (tot + v[i] <= tgt)
            {
                tot += v[i];
                cnt2++;
            }
            else
            {
                break;
            }
        }
        cout << max(cnt1, cnt2) << " " << -1 * tgt << "\n";
    }
    else
    {
        cout << n - len << " " << totalSum + maxSum << "\n";
    }

    return 0;
}