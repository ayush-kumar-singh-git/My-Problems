#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long total = ((long long)n * (n + 1)) / 2;
    cout << "! 2 " << n << "\n"
         << flush;
    long long query;
    cin >> query;
    long long missing = total - query;
    vector<int> arr;
    int sz = 0;
    while (sz != n)
    {
        arr.emplace_back(missing);
        missing++;
        sz++;
        if (missing > n)
            missing = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cout << i + 1 << "\n";
            break;
        }
    }
    return 0;
}