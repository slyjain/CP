#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define print(a)          \
    for (auto i : a)      \
    {                     \
        cout << i << ' '; \
    }                     \
    cout << endl;
#define read(x) \
    int x;      \
    cin >> x;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mt make_tuple
#define eb emplace_back

typedef vector<int> vin;
typedef vector<string> vst;
typedef vector<char> vch;
// do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve()
{
    int n;
    cin >> n;
    vin a(n);
    vector<int> oneCount(60, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> a[i];
    }
    for (int j = 0; j < 60; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] & ((1LL) << j))
            {
                oneCount[j] = (oneCount[j] + 1) ;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < 60; j++)
    {
        ans = ((ans)%MOD + (((1 << j) % MOD) * ((((n - oneCount[j]) % MOD) * ((oneCount[j]) % MOD)) % MOD) % MOD) % MOD)%MOD;
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