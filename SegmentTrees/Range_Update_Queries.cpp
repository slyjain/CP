#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int arr[200200],t[800800];
void update(int id,int l,int r,int lq,int rq,int adder){
    if(rq<l)return ;
    if(lq>r)return;
    if(rq>=r&&lq<=l){
        // cout<<l<<" "<<r<<" "<<lq<<" "<<rq<<"\n";
        t[id]+=adder;
        return ;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,lq,rq,adder);
    update(2*id+1,mid+1,r,lq,rq,adder);
}
int query(int id,int l ,int r,int k){
    if(k<l||k>r)return 0;
    
    if(l==r&&l==k){
        return t[id];
    }
    int mid=(l+r)/2;
    int ans=t[id];
    // cout<<id<<" "<<l<<" "<<r<<" "<<k<<" "<<ans<<"\n";
    ans+=query(2*id,l,mid,k);
    ans+=query(2*id+1,mid+1,r,k);
    
    return ans;

}
void solve(){
cin>>n>>q;
for(int i=1;i<=n;i++){
    cin>>arr[i];
}
while(q--){
    int x;
    cin>>x;
    if(x==1){
        int lq,rq,u;
        cin>>lq>>rq>>u;
        update(1,1,n,lq,rq,u);
        // for(int i=lq;i<=rq;i++){
        //     // cout<<arr[i]<<" ";
        // }
        // cout<<"\n";
    }
    else if(x==2){
        int k;
        cin>>k;
        query(1,1,n,k);
        // cout<<arr[k]<<"\n";
        // cout<<arr[k]+query(1,1,n,k)<<"\n";
        cout<<arr[k]+query(1,1,n,k)<<"\n";
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