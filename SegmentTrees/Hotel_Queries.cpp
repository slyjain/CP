#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200200];
int t[4*200200];
void build(int id,int l,int r){

    if(l==r){
        t[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    t[id]=t[2*id]+t[2*id+1];
}
void update(int id,int l,int r,int pos,int v){
    if(l>pos)return;
    if(r<pos)return;
    if(l==r){
        t[id]=v;
        return ;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,v);
    update(2*id+1,mid+1,r,pos,v);
    t[id]=t[2*id]+t[2*id+1];
}
int query(int id,int l,int r,int x){
    if(t[id]<x)return 1e18;
    if(l==r&&t[id]>=x){
        return l;
    }
    int mid=(l+r)/2;
    int ans=min(query(2*id,l,mid,x),query(2*id+1,mid+1,r,x));
    return ans;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        
    }
    build(1,1,n);
    while(m--){
        int x;
        cin>>x;
        int q=query(1,1,n,x);
        if(q==1e18){
            cout<<0<<" ";
        }
        else{

            cout<<q<<" ";
            a[q]=a[q]-x;
            update(1,1,n,q,a[q]);
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