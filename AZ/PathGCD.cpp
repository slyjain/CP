#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define print(a)          \
    for (auto i : a)      \
    {                     \
        cout << i << ' '; \
    }                     \
    cout << endl;
#define read(x) \
    int x;      \
    cin >> x;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mt make_tuple
#define eb emplace_back

typedef vector<int> vin;
typedef vector<string> vst;
typedef vector<char> vch;
// do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
vector<vector<int>> g, dp;
vin val, depth;
vector<vector<int>> parent;

void dfs(int node, int par, int dep)
{
    depth[node] = dep;
    parent[node][0] = par;
    dp[node][0] = val[node];
    for (int i = 1; i < 20; i++)
    {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
        dp[node][i] = __gcd(dp[node][i - 1], dp[parent[node][i - 1]][i - 1]);
    }
    for (auto ne : g[node])
    {
        if (ne != par)
        {
            dfs(ne, node, dep + 1);
        }
    }
}
int pathGCD(int u, int v)
{
    if (depth[v] > depth[u])
    {
        swap(u, v);
    }
    int ans = 0;
    for (int i = 19; i >= 0; i--)
    {
        if ((depth[u] - depth[v]) & (1 << i))
        {
            ans = __gcd(ans, dp[u][i]);
            u = parent[u][i];
        }
    }
    if (u == v)
        return __gcd(val[u], ans);
    for (int i = 20; i >= 0; i--)
    {
        if (parent[v][i] != parent[u][i])
        {
            ans = __gcd(ans, dp[v][i]);
            v = parent[v][i];
            ans = __gcd(ans, dp[u][i]);
            u = parent[u][i];
        }
    }
    return __gcd(val[u],__gcd(val[v],__gcd(ans, val[parent[u][0]])));
}
void solve()
{
    int n;
    cin >> n;
    val.clear();
    depth.clear();
    dp.clear();
    g.clear();
    parent.clear();
    val.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(21, 0));
    parent.assign(n + 1, vector<int>(21, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> val[i + 1];
    }
    g.resize(n + 1, vector<int>(0));
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // for(int i=1;i<=n;i++){
    //     for(auto x:g[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<"\n";
    // }
    dfs(1, 0, 0);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << depth[i] << " " << parent[i][0] << "\n";
    // }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout<<pathGCD(u,v)<<"\n";
    }
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