#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, arr[1010];
int dp[1010];
int rec(int level) {
  // base case
  if (level == -1) {
    return 0;
  }

  // cache check
  if (dp[level] != -1) {
    return dp[level];
  }
  // compute
  int ans = -1e9;
  int cnt = 0;
  for (int i = level - 1; i >= -1; i--) {
    if (arr[i] < arr[level]) {

      ans = max(ans, 1 + rec(i));
    }
  }
  // save and return
  return dp[level] = ans;
}
int dp2[1001];
int clis(int level) {
  // base case
  if (level == -1) {
    return 1;
  }
  // cache check
  if (dp2[level] != -1) {
    return dp2[level];
  }
  // compute
  int ans = 0;
  for (int i = level - 1; i >= -1; i--) {
    if (rec(level) == 1 + rec(i)&&arr[level]>arr[i]) {
      ans += clis(i);
    }
  }
  //save and return
  return dp2[level] = ans;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  memset(dp, -1, sizeof(dp));
  memset(dp2, -1, sizeof(dp2));
  // cout<<rec(n-1)<<"\n";
  int mx = 0;
  for (int i = n - 1; i >= 0; i--) {
    mx = max(mx, rec(i));
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    // cout<<clis(i)<<" ";
    if (rec(i) == mx) {
      cnt += clis(i);
    }
  }
  cout << cnt << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
