#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100010

vector<vector<int>> g;
vector<int> indegree;
vector<int> topo;
int mod = 1e9 + 7;
int n, m;
void kahn()
{
    queue<int> q;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            dp[i] = 1;
            // cout<<i<<" ";
        }
    }
    // cout<<"\n";
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int x : g[curr])
        {
            indegree[x] = (indegree[x] - 1 + mod) % mod;
            if (indegree[x] == 0)
            {
                // cout<<x<<" ";

                q.push(x);
            }
            dp[x] = (dp[x] + dp[curr]) % mod;
        }
    }
    // int mx = 0;
    // dp[n]
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    cout << dp[n];
}
void solve()
{

    cin >> n >> m;
    g.resize(n + 1);
    indegree.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        indegree[y] = (indegree[y] + 1) % mod;
    }
    kahn();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}