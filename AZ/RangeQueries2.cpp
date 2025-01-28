#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int arr[2*100100];
int t[4*2*100100]{};
void build(int id,int l,int r){
    if(l==r){
        t[id]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(id<<1,l,mid);
    build((id<<1)|1,mid+1,r);
    // t[id]=merge(t[id<<1],t[(id<<1)|1]);
}
void update(int id,int l,int r,int lq,int rq,int x){
    if(lq>r||rq<l){
        return ;
    }
    if(l>=lq&&r<=rq){
        t[id]+=x;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,lq,rq,x);
    update(2*id+1,mid+1,r,lq,rq,x);
}
int query(int id,int l,int r,int pos){
    if(pos<l||pos>r){
        return 0;
    }
    if(l==r&&l==pos){
        return t[id];
    }
    int mid=(l+r)/2;
    int ans=t[id];
    if(pos<=mid&&pos>=l)ans+=query(2*id,l,mid,pos);
    if(pos>=mid+1&&pos<=r)ans+=query(2*id+1,mid+1,r,pos);
    return ans;
}
void solve(){
     int n,q;
     cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        update(1,1,n,i,i,arr[i]);
    }
    // build(1,1,n);
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int lu,ru,x;
            cin>>lu>>ru>>x;
            update(1,1,n,lu,ru,x);
        }else if(ch==2){
            int idx;
            cin>>idx;
            int adder=query(1,1,n,idx);
            cout<<adder<<"\n";
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