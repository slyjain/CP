#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int st_size;
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
    st_size--;
}
void solve(){
    cin>>n>>m;
     rnk.assign(n,1);
    st_size=n;
    par.resize(n);
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    priority_queue<pair<int,pair<int,int>>>edgeList;
    for(int i=0;i<m;i++){
        int u,v,w;
        
        cin>>u>>v>>w;
        u--,v--;
        edgeList.push(make_pair(-w,make_pair(u,v)));
    }
    int ans=0;
    for(int i =0;i<m;i++){
        auto front=edgeList.top();
        edgeList.pop();
        int x=front.second.first;
        int y=front.second.second;
        if(find(x)!=find(y)){
            merge(x,y);
            // cout<<x<<" "<<y<<" "<<-front.first<<"\n";
            ans+=(-front.first);
        }
    }
    bool allAreConnected=true;
    int sabkaNeta=find(0);
    for(int i=1;i<n;i++){
        if(find(i)!=sabkaNeta){
            allAreConnected=false;
        }
    }
    if(allAreConnected){
        cout<<ans;
    }else{
        cout<<"IMPOSSIBLE";
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}