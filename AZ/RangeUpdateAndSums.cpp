#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 200010

struct node {
    int sum;
    int lazy_increment;
    int lazy_set;
    node(int sum_ = 0, int lazy_increment_ = 0, int lazy_set_ = 0)
        : sum(sum_), lazy_increment(lazy_increment_), lazy_set(lazy_set_) {}
};

node t[4 * MAXN];
int a[MAXN];

void push(int id, int l, int r) {
    if (t[id].lazy_set) {
        t[id].sum = t[id].lazy_set * (r - l + 1);
        if (l != r) {
            t[id << 1].lazy_set = t[id].lazy_set;
            t[id << 1 | 1].lazy_set = t[id].lazy_set;
            t[id << 1].lazy_increment = 0;
            t[id << 1 | 1].lazy_increment = 0;
        }
        t[id].lazy_set = 0;
    }
    if (t[id].lazy_increment) {
        t[id].sum += t[id].lazy_increment * (r - l + 1);
        if (l != r) {
            if (t[id << 1].lazy_set) {
                t[id << 1].lazy_set += t[id].lazy_increment;
            } else {
                t[id << 1].lazy_increment += t[id].lazy_increment;
            }
            if (t[id << 1 | 1].lazy_set) {
                t[id << 1 | 1].lazy_set += t[id].lazy_increment;
            } else {
                t[id << 1 | 1].lazy_increment += t[id].lazy_increment;
            }
        }
        t[id].lazy_increment = 0;
    }
}

void build(int id, int l, int r) {
    if (l == r) {
        t[id] = node(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
}

void increVal(int id, int l, int r, int lq, int rq, int val) {
    push(id, l, r);
    if (l > rq || r < lq) return;
    if (l >= lq && r <= rq) {
        t[id].lazy_increment = val;
        push(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    increVal(id << 1, l, mid, lq, rq, val);
    increVal(id << 1 | 1, mid + 1, r, lq, rq, val);
    t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
}

void updateVal(int id, int l, int r, int lq, int rq, int setVal) {
    push(id, l, r);
    if (l > rq || r < lq) return;
    if (l >= lq && r <= rq) {
        t[id].lazy_set = setVal;
        push(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    updateVal(id << 1, l, mid, lq, rq, setVal);
    updateVal(id << 1 | 1, mid + 1, r, lq, rq, setVal);
    t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
}

int query(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if (l > rq || r < lq) return 0;
    if (l >= lq && r <= rq) return t[id].sum;
    int mid = (l + r) >> 1;
    return query(id << 1, l, mid, lq, rq) + query(id << 1 | 1, mid + 1, r, lq, rq);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) { // Increment
            int val;
            cin >> val;
            increVal(1, 1, n, l, r, val);
        } else if (type == 2) { // Set
            int setVal;
            cin >> setVal;
            updateVal(1, 1, n, l, r, setVal);
        } else { // Query
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
