#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    vector<ll> ps(n + 1, 0);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ps[i + 1] = ps[i] + b[i];
        mp[b[i]] = i;
    }
    while (m--)
    {

        ll S;
        cin >> S;
        bool found = false;
        // checking if any array elements satisfy
        for (ll x : a)
        {
            ll idx = mp[x];
            ll score = 0;
            score += (1LL * (2 * idx + 1 - n)) * x - ps[idx] + ps[n] - ps[idx + 1];
            if (score == S)
            {
                cout << x << "\n";
                found = true;
                break;
            }
        }
        if (found)
            continue;
        // cheking if any integer < minm satisfies
        if ((ps[n] - S) % n == 0)
        {
            ll k = (ps[n] - S) / n;
            if (k < b[0])
            {
                cout << k << "\n";
                found = true;
            }
        }
        if (found)
            continue;
        // checking if any integer > maxm satisfies
        if ((ps[n] + S) % n == 0)
        {
            ll k = (ps[n] + S) / n;
            if (k > b[n - 1])
            {
                cout << k << "\n";
                found = true;
            }
        }
        if (found)
            continue;
        // checking remaining numbers
        for (ll i = 0; i < n - 1; i++)
        {
            ll num = S + ps[i + 1] - (ps[n] - ps[i + 1]);
            ll den = 2 * (i + 1) - n;

            if (den == 0)
                continue;
            if (num % den == 0)
            {
                ll k = num / den;
                if (b[i] < k && k < b[i + 1])
                {
                    cout << k << "\n";
                    found = true;
                    break;
                }
            }
        }
        if (found)
            continue;
        cout << "NO SOLUTION\n";
    }
    return 0;
}