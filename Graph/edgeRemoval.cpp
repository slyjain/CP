#include <bits/stdc++.h>
using namespace std;
#define int long long

struct query {
  int type, edge;
};
vector<int> par;
vector<int> sz;
int find(int x) {
  if (x == par[x]) {
    return x;
  }
  return par[x] = find(par[x]);
}
int setSize;
void merge(int a, int b) {
  int xpar = find(a);
  int ypar = find(b);
  if (xpar == ypar) {
    return;
  }
  if (sz[xpar] >= sz[ypar]) {
    par[ypar] = xpar;
    sz[xpar] += sz[ypar];
  } else {
    par[xpar] = ypar;
    sz[ypar] += sz[xpar];
  }
  setSize--;
}
signed main() {
  int n, m, q;
  cin >> n >> m >> q;
  cout << "\n" << n << " " << m << " " << q;
  vector<pair<int, int>> uv;
  setSize = n;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    cout << "\n" << u << " " << v;
    uv.push_back({u, v});
  }
  vector<query> qu;
  map<int, int> edgeList;
  for (int i = 0; i < q; i++) {
    int t, e;
    cin >> t;
    cout << "\n" << t << " ";
    query temp;
    if (t == 2) {

      temp.type = 2;
    } else {

      temp.type = 1;
      cin >> e;
      cout << " " << e;
      temp.edge = e;
      edgeList[e] = 1;
    }
    qu.push_back(temp);
  }

  for (int i = 0; i < m; i++) {
    if (edgeList[i + 1] == 1) {
      continue;
    }
    merge(uv[i].first, uv[i].second);
  }
  vector<int> answers;
  for (int i = qu.size() - 1; i >= 0; i--) {
    if (qu[i].type == 2) {
      answers.push_back(setSize);
    } else {
      cout << "\n"
           << uv[qu[i].edge - 1].first << " " << uv[qu[i].edge - 1].second;
      merge(uv[qu[i].edge - 1].first, uv[qu[i].edge - 1].second);
    }
  }
  reverse(answers.begin(), answers.end());
  for (auto v : answers) {
    cout << v << "\n";
  }
}
