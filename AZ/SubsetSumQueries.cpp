#include <bits/stdc++.h>
using namespace std;
#define int long long
// DO NOT FORGET TO initialise DP array with -1
vector<int> a;
int n;
vector<vector<int>> dp;
bool rec(int level, int sumRem)
{
    // prunning
    if (sumRem < 0)
    {
        return 0;
    }
    // base case
    if (sumRem == 0)
    {
        return 1;
    }
    if (level == n && sumRem == 0)
    {
        return 1;
    }
    else if (level == n)
    {
        return 0;
    }
    // cache check
    if (dp[level][sumRem] != -1)
    {
        return dp[level][sumRem];
    }
    
        // transitions
        bool ans = rec(level + 1, sumRem - a[level]);
    ans |= rec(level + 1, sumRem);
    // save and return
    return dp[level][sumRem] = ans;
}
void solve()
{
    int q;
    cin >> n >> q;
    a.resize(n);
    dp.assign(101, vector<int>(100001, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (rec(0, x))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}