#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[2*10010],t[8*10010];
void build(int id,int l,int r){
    if(l==r){
        t[id]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
}
int query(int id,int l,int r,int lq,int rq){
    if(rq<l||lq>r){
        return 0;
    }
    if(lq<=l&&r<=rq){
        return 
    }
}
void solve(){
int n,q;
cin>>n>>q;
memset(t,0,sizeof(t));
for(int i=0;i<n;i++){
    cin>>arr[i];
}
build(1,1,n-1);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}