#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
vector<int>rnk,par;
int find(int x){
    if(x==par[x]){
        return x;
    }
    else{
        return par[x]=find(par[x]);
    }
}
void merge(int a,int b){
    int p1=find(a),p2=find(b);
    if(p1==p2){
        return;
    }
    if(rnk[p1]>rnk[p2]){
        rnk[p1]+=rnk[p2];
        par[p2]=p1;
    }else{
        rnk[p2]+=rnk[p1];
        par[p1]=p2;
    }
}
void solve(){
    cin>>n>>q;
    rnk.assign(n,1);
    par.resize(n);
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    while(q--){
        int c;
        cin>>c;
        if(c==0){
            int a,b;cin>>a>>b;
            merge(a,b);
        }else{
            int a,b;cin>>a>>b;
            cout<<(find(a)==find(b))<<"\n";
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