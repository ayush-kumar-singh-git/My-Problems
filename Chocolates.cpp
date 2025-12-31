#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<long long> ps(n), ss(n);
    ps[0] = v[0];
    ss[n - 1] = v[n - 1];

    for (int i = 1; i < n; i++)
        ps[i] = ps[i - 1] + v[i];

    for (int i = n - 2; i >= 0; i--)
        ss[i] = ss[i + 1] + v[i];

    vector<long long> maxSS(n);
    long long maxSuffixSum = LLONG_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        maxSuffixSum = max(maxSuffixSum, ss[i]);
        maxSS[i] = maxSuffixSum;
    }
    long long maxHappiness = LLONG_MIN;
    int chosenI = -1;
    maxHappiness = maxSS[0];
    chosenI = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long long happiness = ps[i] + maxSS[i + 1];
        if (happiness > maxHappiness)
        {
            maxHappiness = happiness;
            chosenI = i;
        }
    }
    if (chosenI == -1)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
            if (ss[i] == maxSS[0])
                j = i;
        cout << n - j << " " << maxHappiness << "\n";
    }
    else
    {
        int j = n;
        for (int i = n - 1; i > chosenI; i--)
            if (ss[i] == maxSS[chosenI + 1])
                j = i;

        cout << (chosenI + 1 + n - j) << " " << maxHappiness << "\n";
    }

    return 0;
}