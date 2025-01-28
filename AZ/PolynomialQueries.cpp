#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 200010

struct node {
    int sum;
    int lazy_start;
    // int lazy_set;
    node(int sum_ = 0, int lazy_start_= 0)
        : sum(sum_), lazy_start(lazy_start_) {}
};

node t[4 * MAXN];
int a[MAXN];

void push(int id, int l, int r) {
    if (t[id].lazy_start) {
        int val=t[id].lazy_start;
        int incre=r-l;
        int increSum = (((val + incre) * (val + incre + 1)) / 2 )- (val * (val - 1)) / 2;

        // increSum=((val+incre)*(val+incre+1))/2-(val*(val-1)/2);
        t[id].sum += increSum;
        if (l != r) {
            int mid=(l+r)/2;
            t[id *2].lazy_start += t[id].lazy_start;
            t[id * 2 + 1].lazy_start += t[id].lazy_start+(mid-l+1);
            // t[id << 1].lazy_increment = 0;
            // t[id << 1 | 1].lazy_increment = 0;
        }
        t[id].lazy_start = 0;
    }
    
}

void build(int id, int l, int r) {
    if (l == r) {
        t[id] = node(a[l],0);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
}

void updateVal(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if (l > rq || r < lq) return;
    if (l >= lq && r <= rq) {
        t[id].lazy_start = l-lq+1;
        push(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    updateVal(id << 1, l, mid, lq, rq);
    updateVal(id << 1 | 1, mid + 1, r, lq, rq);
    t[id].sum = t[id << 1].sum + t[id << 1 | 1].sum;
}

int query(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if (l > rq || r < lq) return 0;
    if (l >= lq && r <= rq) {
        push(id,l,r);
        return t[id].sum;}
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
        if (type == 1) { 
            
            updateVal(1, 1, n, l, r);
        } else if (type == 2) { // query
            
            cout<<query(1, 1, n, l, r)<<"\n";
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
