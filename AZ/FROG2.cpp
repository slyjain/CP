#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<int> h;
vector<int> dp;
int rec(int level)
{
    // basre case
    if (level < 0)
    {
        return 0;
    }
    if (level == 0)
    {
        return 0;
    }
    // cache check
    if (dp[level] != -1)
    {
        return dp[level];
    }
    // transisitioons
    int ans = 1e9;
    for (int i = 1; i <= k; i++)
    {
        if (level - i >= 0)
        {
            ans = min(ans, abs(h[level] - h[level - i]) + rec(level - i));
        }
    }
    // save and return
    return dp[level] = ans;
}
void solve()
{
    // int n;
    cin >> n >> k;
    h.resize(n);
    dp.assign(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    cout << rec(n - 1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}