#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> grid;
vector<vector<int>> vis;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int n, k;
void bringItDown()
{
    for (int i = 0; i < 10; i++)
    {   vector<int>l;
        for(int j=n-1;j>=0;j--){
            if(grid[j][i]!=0){
                l.push_back(grid[j][i]);
            }
        }
        for(int j=n-1;j>=0;j--){
            grid[j][i]=0;
        }
        
        for(int o=0,j=n-1;o<l.size();o++,j--){
            grid[j][i]=l[o];
            // j--;
        }
    }
}
vector<pair<int, int>> neigh(int r, int c)
{
    vector<pair<int, int>> ne;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < 10 && grid[nr][nc] == grid[r][c] )
        {
            ne.push_back({nr, nc});
        }
    }
    return ne;
}
vector<pair<int, int>> b;
void dfs(int r, int c)
{   b.push_back({r, c});
    vis[r][c] = 1;
    vector<pair<int, int>> ne = neigh(r, c);
    for (auto x : neigh(r, c))
    {
        if(vis[x.first][x.second]==0){
            dfs(x.first, x.second);
        }
        
    }
}
void solve()
{

    cin >> n >> k;
    grid.assign(n, vector<int>(10, 0));
    vis.assign(n,vector<int>(10,0));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = (s[j] - '0');
        }
    }
    bool fata = true;
    while (fata)
    {
        bringItDown();
        fata = false;
        vis.assign(n, vector<int>(10, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] != 0)
                {
                    b.clear();
                    dfs(i, j);
                    if (b.size() >= k)
                    {
                        for (auto &[x, y] : b)
                        {
                            grid[x][y] = 0;
                        }
                        fata = true;
                        // bringItDown();
                        // break;
                    }
                }
            }
            // if(fata==true){
            //     break;
            // }
            
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
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