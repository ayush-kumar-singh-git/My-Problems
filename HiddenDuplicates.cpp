#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 2; i <= n; i++)
    {
        cout << "? 1 " << i << "\n"
             << flush;
        int reply;
        cin >> reply;
        if (reply == 0)
        {
            cout << "! 1 " << i << "\n"
                 << flush;
            break;
        }
        if (mp.find(reply) != mp.end())
        {
            cout << "! " << mp[reply] << " " << i << "\n"
                 << flush;
            break;
        }
        mp[reply] = i;
    }
    return 0;
}