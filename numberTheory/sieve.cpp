#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> siever;
vector<int> aTob;

void sieve(int n, vector<int> &s) {
  s.resize(n + 1);
  s.assign(n + 1, 1);
  s[0] = s[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (s[i] == 1) {
      for (int j = i * i; j <= n; j += i) {
        s[j] = 0;
      }
    }
  }
}
inline bool check(int mid, int n) { return mid * mid >= n; }
int squareRoot(int n) {
  int lo = 0;
  int hi = n;
  int ans = hi;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid, n)) {
      hi = mid - 1;
      ans = mid;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}
signed main() {

  int a, b;
  cin >> a >> b;
  int sqrtb = squareRoot(b);
  sieve(b, siever);
  vector<int> segmentedSieve(b - a + 1, 1);
  for (int i = 0; i <= sqrtb; i++) {
    if (siever[i] == 1) {
      int currentMultiple = (i) * ((a + i - 1) / i);
      currentMultiple = max(i * i, currentMultiple);
      for (int j = currentMultiple; j <= b; j += i) {

        segmentedSieve[j - a] = 0;
      }
    }
  }
  if (a == 1) {
    segmentedSieve[a - 1] = 0;
  }
  for (int i = a; i <= b; i++) {
    if (segmentedSieve[i - a] == 1) {
      cout << i << " ";
    }
  }
  return 0;
}
