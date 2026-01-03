#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    set<int> st;
    int currXor = 0;
    st.insert((currXor ^ x));
    for (int i = 0; i < n - 1; i++)
    {
        int b;
        cin >> b;
        currXor ^= b;
        st.insert((currXor ^ x));
    }
    cout << st.size() << "\n";
    return 0;
}