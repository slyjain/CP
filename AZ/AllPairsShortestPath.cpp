#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int dis[n][n];
    const int INF = 1000000000;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dis[i][j];
            // cout<<dis[i][j]<<" ";
        }
        // cout<<"\n";
    }
    vector<int> apsp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        apsp.push_back(x);
        // cout<<x<<" ";
    }
    reverse(apsp.begin(), apsp.end());
    vector<int> ans;
    // int dis[n][n];
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         dis[i][j] =INF;
    //     }
    // }
    vector<int> free;
    for (auto x : apsp)
    {
        int temp = 0;
        free.push_back(x);
        for (int i =0;i<n;i++)
        {
            for (int j =0;j<n;j++)
            {
                dis[i ][j ] = min(dis[i ][j ], dis[i ][x -1] + dis[x - 1][j ]);
            }
        }
        
        for (int i : free)
        {
            for (int j : free)
            {
                
                    temp += dis[i - 1][j - 1];
                
            }
        }
        ans.push_back(temp);
    }

    // reverse(ans.begin(),ans.end());
    for (int i = n - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
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