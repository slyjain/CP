#include <bits/stdc++.h>
using namespace std;
#define int long long
// do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
const int INF = 1e18;
int n, k;
string s;
unordered_map<char, char> rps;
unordered_map<char, int> moveNum;
// vector<vector<vector<int>>>dp;
int dp[1010][1010][3];
char arr[] = {'P', 'R', 'S'};
int rec(int level, int krem, char move)
{
    // Prunning
    if (krem < 0)
    {
        return -INF;
    }
    // base case
    if (level == n)
    {
        return 0;
    }
    // cache check
    if (dp[level][krem][moveNum[move]] != -1)
    {
        return dp[level][krem][moveNum[move]];
    }
    // compute
    char vMove = s[level];
    int ans = (rps[vMove] == move);
    int curr = rec(level + 1, krem, move);
    if (move != 'R')
    {
        curr = max(curr, rec(level + 1, krem - 1, 'R'));
    }
    if (move != 'S')
    {
        curr = max(curr, rec(level + 1, krem - 1, 'S'));
    }
    if (move != 'P')
    {
        curr = max(curr, rec(level + 1, krem - 1, 'P'));
    }
    // save and return
    return dp[level][krem][moveNum[move]] = curr + ans;
}
vector<char> mvs;
void generate(int level, int krem, char move)
{
    if (level == n)
    {
        return;
    }
    mvs.push_back(move);
    int ans = rec(level, krem, move);

    char vMove = s[level];
    int win = (rps[vMove] == move);
    ans -= win;

    int nk;
    char nc;
    for (auto x : arr)
    {
        if (x == move && ans == rec(level + 1, krem, move))
        {
            nk = krem;
            nc = move;
            break;
        }
        else if (ans == rec(level + 1, krem - 1, x))
        {
            nk = krem - 1;
            nc = x;
            break;
        }
    }
    generate(level + 1, nk, nc);
}

void solve()
{
    cin >> n >> k;
    cin >> s;
    //  dp.clear();
    mvs.clear();
    memset(dp, -1, sizeof(dp));
    //  dp.assign(n,vector<vector<int>>(k+1,vector<int>(3,-1)));
    int ans = 0;
    rps['R'] = 'P';
    moveNum['R'] = 1;
    rps['S'] = 'R';
    moveNum['S'] = 2;
    rps['P'] = 'S';
    moveNum['P'] = 0;
    ans = max(ans, rec(0, k, 'R'));
    ans = max(ans, rec(0, k, 'P'));
    ans = max(ans, rec(0, k, 'S'));
    cout << ans << "\n";
    int nk;
    char nc;
    for (auto x : arr)
    {
        if (ans == rec(0, k, x))
        {
            nk = k;
            nc = x;
            break;
        }
    }
    generate(0, nk, nc);
    for (auto x : mvs)
    {
        cout << x;
    }
    cout << "\n";
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