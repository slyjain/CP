#include <bits/stdc++.h>
using namespace std;
#define int long long

int josephus(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    int ans = (k + josephus(n - 1, k)) % n;
    return ans;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) + 1 << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}