#include <bits/stdc++.h>
using namespace std;
#define int long long

int dpWin[61][160][160][11][2];
int dpPos[61][160][11];
int r[] = {1, 2, 3, 4, 6, 0};

int rec2(int ballRem, int runRem, int wickRem) {
    if (ballRem == 0 || wickRem == 0 || runRem <= 0) {
        return (runRem <= 0);
    }
    if (dpPos[ballRem][runRem][wickRem] != -1) {
        return dpPos[ballRem][runRem][wickRem];
    }

    int ans = 0;
    for (int i = 0; i < 6; i++) {
        if (runRem >= r[i]) {
            ans += rec2(ballRem - 1, runRem - r[i], wickRem);
        }
    }
    ans += rec2(ballRem - 1, runRem, wickRem - 1);
    
    dpPos[ballRem][runRem][wickRem] = ans;
    return ans;
}

int rec1(int ballRem, int runRem, int vkRuns, int wickRem, int strike) {
    if (wickRem == 0 || ballRem == 0) {
        return (runRem <= 0 && vkRuns >= 100);
    }

    if (dpWin[ballRem][runRem][vkRuns][wickRem][strike] != -1) {
        return dpWin[ballRem][runRem][vkRuns][wickRem][strike];
    }

    int ans = 0;
    for (int i = 0; i < 6; i++) {
        int newRunRem = runRem - r[i];
        int newVkRuns = vkRuns + r[i];
        int newWickRem = (r[i] == 0) ? wickRem - 1 : wickRem;
        int newStrike = (r[i] % 2 == 1) ? 1 - strike : strike;

        if (newRunRem >= 0) {
            ans += rec1(ballRem - 1, newRunRem, newVkRuns, newWickRem, (ballRem % 6 == 0) ? 1 - strike : newStrike);
        }
    }

    dpWin[ballRem][runRem][vkRuns][wickRem][strike] = ans;
    return ans;
}

int N, b, w, x;

void solve() {
    memset(dpWin, -1, sizeof(dpWin));
    memset(dpPos, -1, sizeof(dpPos));
    cin >> N >> b >> w >> x;
    cout << rec1(b, N, 10 - w, x, 1) << " " << rec2(b, N, 10 - w) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
