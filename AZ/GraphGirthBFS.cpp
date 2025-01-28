#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int>> g;
vector<int> dis;
int minCyc = LLONG_MAX;
void bfs(int sc)
{
    queue<pair<int, int>> q;
    dis[sc] = 0;
    q.push({sc, -1});
    while (!q.empty())
    {
        int curr = q.front().first;
        int par = q.front().second;
        q.pop();
        for (int next : g[curr])
        {
            if (dis[next] == LLONG_MAX)
            {
                dis[next] = 1 + dis[curr];
                q.push({next, curr});
            }
            else if (next != par)
            {
                minCyc = min(minCyc, dis[next] + dis[curr] + 1);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        dis.assign(n + 1, LLONG_MAX);
        bfs(i);
    }
    if (minCyc == LLONG_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << minCyc;
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