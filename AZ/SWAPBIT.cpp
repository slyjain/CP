#include <bits/stdc++.h>
using namespace std;
#define int long long
// do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int ob, eb;
void init()
{
    ob = 0, eb = 0;
    for (int i = 0; i < 32; i = i + 2)
    {
        ob |= (1 << i);
    }
    for (int i = 1; i < 32; i = i + 2)
    {
        eb |= (1 << i);
    }
}
void solve()
{
    int n;
    cin >> n;
    int o = n & ob;
    int e = n & eb;
    o <<= 1;
    e >>= 1;
    int ans = o | e;
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}