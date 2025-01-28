#include <bits/stdc++.h>
using namespace std;
#define int long long
// do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve()
{
    int n;
    cin >> n;

    int a[32] = {0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < 32; j++)
        {
            if ((x >> j) & 1)
            {
                a[j]++;
            }
        }
    }
    bool khtm = true;
    int sum = 0;
    while (khtm)
    {
        khtm = false;
        int x = 0;
        for (int i = 0; i < 32; i++)
        {
            if (a[i] > 0)
            {
                x += (1 << i);
                a[i]--;
                khtm = true;
            }
        }
        sum += (x * x);
    }
    cout << sum << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}