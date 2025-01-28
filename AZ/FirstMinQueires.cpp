#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e9;
int arr[2*100100];
struct node{
    int val,idx;
    node(int val_=0,int idx_=0){
        val=val_,idx=idx_;
    }
    
};
node merge(node a,node b){
        node ans=node(max(a.val,b.val),0);
        return ans;
    }
node t[4*2*100100];
void build(int id,int l,int r){
    if(l==r){
        t[id]=node(arr[l],l);
        return;
    }
    int mid=(l+r)/2;
    build(id<<1,l,mid);
    build((id<<1)|1,mid+1,r);
    t[id]=merge(t[id<<1],t[(id<<1)|1]);
}
int query(int id, int l, int r, int val) {
    if (t[id].val < val) {  // If no value in this range satisfies the condition
        return INF;
    }
    if (l == r) {  // Leaf node, return the index
        return l;
    }
    int mid = (l + r) / 2;
    int leftAns = query(2 * id, l, mid, val);
    if (leftAns != INF) {  // If a valid answer is found in the left subtree, return it
        return leftAns;
    }
    return query(2 * id + 1, mid + 1, r, val);  // Otherwise, check the right subtree
}

void update(int id,int l,int r,int pos,int val){
    if(pos<l||pos>r){
        return;
    }
    if(l==r&&l==pos){

     t[id]=node(val,l);
     arr[l]=val;
     return;
    }
    int mid=(l+r)/2;
    update(2*id,l, mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    t[id]=merge(t[2*id],t[2*id+1]);
}
void solve(){
    int n,q;
    cin>>n>>q;
    // vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(1,1,n);
    while(q--){
        int x;
        cin>>x;
        int idx_=query(1,1,n,x);
        cout<<(idx_==INF?0:idx_)<<" ";
        // cout<<arr[idx_]-x<<"\n";
        if(idx_!=INF){update(1,1,n,idx_,arr[idx_]-x);}
        
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}