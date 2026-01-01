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
    int st = 0, end = 0;
    int smallestLen = n;
    for (int i = 0; i < n; i++)
    {
        long long one = currSum + v[i];
        long long two = v[i];
        currSum = max(one, two);
        if (currSum == one)
        {
            end = i;
        }
        else
        {
            st = i;
            end = i;
        }
        if (currSum > maxSum)
        {
            maxSum = currSum;
            smallestLen = end - st + 1;
        }
        else if (currSum == maxSum)
        {
            smallestLen = min(smallestLen, end - st + 1);
        }
        if (currSum < 0)
        {
            currSum = 0;
            st = i + 1;
            end = i + 1;
        }
    }
    // cout << maxSum << " " << smallestLen << "\n";
    if (maxSum <= 0)
    {
        cout << n << " " << totalSum << "\n";
    }
    else if (smallestLen == n)
    {
        cout << 1 << " " << -1 * min(v[0], v[n - 1]) << "\n";
    }
    else
    {
        cout << n - smallestLen << " " << totalSum + maxSum << "\n";
    }

    return 0;
}