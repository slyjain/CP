#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[2*100100];
struct node{
  int sum,maxi,lsum,rsum;
  node(int sum_=0,int maxi_=0,int lsum_=0,int rsum_=0):sum(sum_),maxi(maxi_),lsum(lsum_),rsum(rsum_){}

};
node operator+(node &a,node &b){
    node temp;
    temp.lsum=max(a.lsum,a.sum+b.lsum);
    temp.rsum=max(b.rsum,b.sum+a.rsum);
    temp.sum=a.sum+b.sum;
    temp.maxi=max(max(a.maxi,b.maxi),a.rsum+b.lsum);
    return temp;
}
node t[4*2*100100];
void update(int id,int l,int r,int idx,int val){
    if(l==r&&l==idx){
        int xx=max(val,0*1LL);
        t[id]=node(val,xx,xx,xx);
        return ;
    }
    int mid=(l+r)/2;
    if(idx>=l&&idx<=mid){
        update(2*id,l,mid,idx,val);
    }
    else{
        update(2*id+1,mid+1,r,idx,val);
    }
    t[id]=t[id<<1]+t[id<<1|1];
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        update(1,1,n,i,arr[i]);
    }
    // build(1,1,n);
    while(q--){
        int pos,val;
        cin>>pos>>val;

        update(1,1,n,pos,val);
        cout<<t[1].maxi<<"\n";
    }


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}