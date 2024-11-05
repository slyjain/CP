#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int arr[200200];
int t[800800];
void build(int id,int l,int r){
    if(l==r){
        t[id]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=min(t[2*id],t[2*id+1]);
    return;

}
void update(int id,int l,int r,int pos,int v){
    if(pos<l||pos>r)return;
    if(l==r){
        arr[pos]=v;
        t[id]=v;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,v);
    update(2*id+1,mid+1,r,pos,v);
    t[id]=min(t[2*id],t[2*id+1]);
    return;
}
int query(int id,int l,int r,int lq,int rq){
    if(rq<l)return 1e18;
    if(lq>r)return 1e18;
    if(l>=lq&&r<=rq){
        return t[id];
    }
    int mid=(l+r)/2;
    int ans=query(2*id,l,mid,lq,rq);
    ans=min(ans,query(2*id+1,mid+1,r,lq,rq));
    return ans;
}
void solve(){
    cin>>n>>q;
    // cout<<n<<" "<<q<<"\n";
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        // cout<<arr[i]<<" "<<i<<"\n";
    }
    //build
    build(1,1,n);
    // q++;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(1,1,n,l,r)<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}