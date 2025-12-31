#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> ps(n + 1, 0), pG(n), nG(n);
    int prevG = -1;
    for (int i = 0; i < n; i++)
    {
        ps[i + 1] = ps[i] + (s[i] == 'B');
        if (s[i] == 'G')
            prevG = i;
        pG[i] = prevG;
    }
    int nextG = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'G')
            nextG = i;
        nG[i] = nextG;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int i = nG[l], j = pG[r];
        if (i == -1 || j == -1 || i >= j)
        {
            cout << 0 << "\n";
            continue;
        }
        cout << ps[j] - ps[i + 1] << "\n";
    }
    return 0;
}