#include <bits/stdc++.h>
using namespace std;
#define int long long
int par[10010];
int sz[10010];
int setSize;
int find(int x) {
  if (par[x] == x) {

    return x;
  }
  par[x] = find(par[x]);
  return par[x];
}
void merge(int x, int y) {
  int xpar = find(x);
  int ypar = find(y);
  if (ypar == xpar) {
    return;
  }
  if (sz[xpar] >= sz[ypar]) {

    sz[xpar] += sz[ypar];
    par[ypar] = xpar;
  } else {
    sz[ypar] += sz[xpar];
    par[xpar] = ypar;
  }
  setSize--;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, q;
  cin >> n >> q;

  // par.assign(n, 0);
  for (int i = 0; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }

  // sz.assign(n+1, 1);
  setSize = n;

  // cin >> q;
  while (q--) {
    int c;
    int a, b;
    cin >> c;

    cin >> a >> b;
    // a--;b--;
    if (c == 0) {
      merge(a, b);
    } else {
      int a = find(a);
      int b = find(b);
      cout << (a == b) << "\n";
    }
    //      cout << setSize << "\n";
  }

  return 0;
}
