#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100010
int freq[MAXN]{};
int t[4*MAXN]{};
void build(int id,int l,int r){
    if(l==r){
        t[id]=freq[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=t[id<<1]+t[id<<1|1];
}
int query(int id,int l,int r,int k){
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(t[id<<1|1]>=k){
       return  query(id<<1|1,mid+1,r,k);
    }else{
       return query(id<<1,l,mid,k-t[id<<1|1]);
    }

}
void remove(int id,int l,int r,int idx){
    if(idx<l||idx>r){
        return;
    }
    if(l==r&&l==idx){
        freq[l]=0;
        t[id]=0;
        return ;
    }
    int mid=(l+r)>>1;
    remove(id<<1,l,mid,idx);
    remove(id<<1|1,mid+1,r,idx);
    t[id]=t[id<<1]+t[id<<1|1];
}
void solve(){
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        // cin>>heights[i];
        int x;
        cin>>x;
        freq[x]++;
        mp[x]=i;
    }
    build(1,1,n);
    int ans[n];
    int nthLargestFromBack[n];
    for(int i=0;i<n;i++){
        cin>>nthLargestFromBack[i];
    }
    int idx;
    for(int i=n-1;i>=0;i--){
        // cout<<nthLargestFromBack[i]+1<<" ";
        idx=query(1,1,n,nthLargestFromBack[i]+1);
        // cout<<idx<<" "<<mp[idx]<<"\n";
        remove(1,1,n,idx);
        ans[i]=mp[idx];
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}