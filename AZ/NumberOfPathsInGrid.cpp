#include <bits/stdc++.h>
using namespace std;
#define int long long
// do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
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
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<int>>> g(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
    vector<vector<int>> mp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    if (mp[1][1] == 1)
    {
        cout << "0\n";
    }
    else
    {
        g[1][1][0] = 1;
        // cout<<g[0][0][0]<<"\n";
        // for (int l = 1; l <= k; l++)
        // {
        //     (mp[0][l] != 1) ? g[0][l][l] = 1 : g[0][l][l] = 0;
        // }
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <=m; j++)
            {
                if (mp[i][j] == 0)
                {
                    
                        for (int l = 0; l <= k; l++)
                        {
                            g[i][j][0] = (g[i][j][0] + g[i - 1][j][l]) % MOD;
                        }

                        for (int l = 1; l <= k; l++)
                        {
                            g[i][j][l] = (g[i][j][l] + g[i][j - 1][l - 1]) % MOD;
                        }
                    
                }
                else
                {
                    for (int l = 0; l <= k; l++)
                    {
                        g[i][j][l] = 0;
                    }
                }
            }
        }
        int ans = 0;
        // for (int l = 0; l <= k; l++)
        // {
        //     for (int i = 0; i < n; i++)
        //     {
        //         for (int j = 0; j < m; j++)
        //         {
        //             cout <<g[i][j][l]<<" ";
        //         }
        //         cout<<"\n";
        //     }
        //     cout<<"\n";
        // }

        for (int i = 0; i <= k; i++)
        {
            ans = (ans + g[n ][m ][i]) % MOD;
        }
        cout << ans << "\n";
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