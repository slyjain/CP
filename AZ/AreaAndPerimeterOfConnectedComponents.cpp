peri += 4 - nb.size();
for (auto x : nb) {
  if (vis[x.first][x.second == false]) {
    dfs(x.first, x.second);
  }
}
}
void solve() {
  // int n;
  cin >> n;
  a.resize(n, vector<char>(n));
  vis.resize(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '#' && vis[i][j] == false) {
        area = 0;
        peri = 0;
        dfs(i, j);
        if (area > mxArea) {
          mxArea = area;
          minPeri = peri;
        } else if (area == mxArea) {
          minPeri = min(minPeri, peri);
        }
      }
    }
  }
  cout << mxArea << " " << minPeri;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
