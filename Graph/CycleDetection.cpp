#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
bool cycleExists = false;

void dfs(int node,int parent) {
    vis[node]=1;
    for (auto v : g[node]) {
        if (!vis[v]) {
            
            dfs(v,parent);
        } else if (v !=parent) {
            
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            
            dfs(i,-1);
        }
    }

    if (cycleExists) {
        cout << "Cycle exists in graph";
    } else {
        cout << "Cycle does not exist in graph";
    }

    return 0;
}
