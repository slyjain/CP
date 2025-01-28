#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
// do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n, m, k;
vector<vector<int>> g;
vector<vector<vector<int>>> dp;
int rec(int r, int c, int kRem)
{ 
    // cout<<r<<" "<<c<<" "<<k<<"--\n";
    // prunning
    if (r > n-1 || c > m-1)
        return 0;
    // base case
    if (r == n-1 && c == m-1&& kRem>=0)
    {
        return 1;
    }
    //  cout<<r<<" "<<c<<" "<<k<<"--\n";
    // cache check
    if (dp[r][c][kRem] != -1)
    {
        return dp[r][c][kRem];
    }
    // transitions
    int ans = 0;
    
    //  cout<<r<<" "<<c<<" "<<k<<"--\n";
        if (r + 1 <= n-1 && (kRem - (g[r +1][c] == 1?1:0)) >= 0)
        {
            // cout<<r<<" "<<c<<"->"<<r+1<<" "<<c<<"\n";
            ans = rec(r + 1, c, kRem - (g[r + 1][c] == 1?1:0));
        }

        if (c + 1 <= m-1 && (kRem - (g[r][c + 1] == 1?1:0)) >= 0)
        {  
            //  cout<<r<<" "<<c<<"->"<<r<<" "<<c+1<<"\n";
            ans =(ans+ rec(r, c + 1, kRem - (g[r][c + 1] == 1?1:0)))%mod;
        }


    // save and return
    return dp[r][c][kRem] = ans;
}
void solve()
{
    cin >> n >> m >> k;

    g.assign(n, vector<int>(m, 0));
    dp.assign(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            // cout << g[i][j] << " ";
        }
        // cout << "\n";
    }
    int ans = 0;
    if(g[0][0]==1&&k-1>=0){
        ans=rec(0,0,k-1);
    }
    if(g[0][0]==0){
        ans=rec(0,0,k);
    }
    cout << ans << "\n";
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