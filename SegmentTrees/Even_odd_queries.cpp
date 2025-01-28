#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>arr;

struct node{
    int cnt;
    node(int c=0){
        cnt=c;
    }
};
node merge(node a,node b){
    node ans(a.cnt+b.cnt);
    return ans;
}
vector<node>t;
void build(int id,int l,int r){
    if(l==r){
        t[id]=node(arr[l]%2);
        return ;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=merge(t[2*id],t[2*id+1]);
}
void update(int id,int l,int r,int pos,int val){
    if(pos>r||pos<l)return;
    if(l==r){
        arr[pos]=val;
        t[id]=node(arr[pos]%2);
        return ;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    t[id]=merge(t[2*id],t[2*id+1]);
}
node query(int id,int l,int r,int lq,int rq){
    if(l>rq||r<lq)return node(0);
    if(l>=lq&&r<=rq)return t[id];
    int mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}
void solve(){
    int n;
    cin>>n;
    arr.resize(n+1);
    t.resize(4*(n+1));
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    build(1,1,n);
    while(q--){
        int t;
        cin>>t;
        int l,r;
        cin>>l>>r;
        
        if(t==2){
            int cnt=query(1,1,n,l,r).cnt;
            cout<<cnt<<"\n";
            
        }else if(t==1){
            int cnt=query(1,1,n,l,r).cnt;
            cout<<(r-l+1)-cnt<<"\n";
        }else if(t==0){
            update(1,1,n,l,r);
        }

    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}