#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> nextG(n), prevG(n);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && v[stk.top()] < v[i])
        {
            stk.pop();
        }
        if (stk.empty())
            prevG[i] = -1;
        else
            prevG[i] = stk.top();
        stk.push(i);
    }

    while (!stk.empty())
    {
        stk.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && v[stk.top()] <= v[i])
        {
            stk.pop();
        }
        if (stk.empty())
            nextG[i] = n;
        else
            nextG[i] = stk.top();
        stk.push(i);
    }
    int mostPowerful, maxPower = 0;
    for (int i = 0; i < n; i++)
    {
        int L = prevG[i] + 1;
        int R = nextG[i] - 1;
        L = i - L + 1;
        R = R - i + 1;
        long long power = 1LL * L * R;
        if (power > maxPower)
        {
            maxPower = power;
            mostPowerful = v[i];
        }
    }
    cout << mostPowerful << " " << maxPower << "\n";
    return 0;
}