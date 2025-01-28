#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int>> g;
vector<int> topo;
vector<int> indegree;
void Kahn()
{

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            pq.push(-i);
        }
    }
    while (!pq.empty())
    {
        int curr = -pq.top();
        pq.pop();
        topo.push_back(curr);
        for (auto v : g[curr])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                pq.push(-v);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    indegree.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        indegree[y]++;
    }
    Kahn();
    if (topo.size() != n)
    {
        cout << "-1";
    }
    else
    {
        for (auto x : topo)
        {
            cout << x << " ";
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