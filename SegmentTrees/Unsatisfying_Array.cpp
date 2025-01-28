#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
vector<int> arr(2020), t(8080), ans(2020);
set<int> rem;

// Function to build the segment tree and determine final `ans`
void build(int id, int l, int r, vector<int> mins) {
    if (l == r) {
        auto it = rem.begin();
        if (mi != *it) {
            ans[l] = *it;
        } else {
            advance(it, 1);
            ans[l] = *it;
        }
        rem.erase(it); // Remove used element from the set
        return;
    }

    int mid = (l + r) / 2;
    vector<int >temp=mins;
    temp.push_back(t[2*])
    build(2 * id, l, mid, );
    build(2 * id + 1, mid + 1, r, min(mi, t[2 * id + 1]));
}

// Function to perform range updates
void update(int id, int l, int r, int lq, int rq, int mi) {
    if (lq > r || rq < l) return; // No overlap
    if (lq <= l && r <= rq) {     // Total overlap
        t[id] = min(mi, t[id]);
        return;
    }

    // Partial overlap
    int mid = (l + r) / 2;
    update(2 * id, l, mid, lq, rq, mi);
    update(2 * id + 1, mid + 1, r, lq, rq, mi);
}

// Solve function for each test case
void solve() {
    cin >> n >> k;

    // Initialize the segment tree and `rem` set
    for (int i = 1; i <= 4 * n; i++) {
        t[i] = n + 1;
    }
    rem.clear();
    for (int i = 1; i <= n + 1; i++) {
        rem.insert(i);
    }

    // Process updates
    while (k--) {
        int lq, rq, mi;
        cin >> lq >> rq >> mi;
        update(1, 1, n, lq, rq, mi);
    }

    // Build the answer array
    build(1, 1, n, n + 1);

    // Output the results
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
