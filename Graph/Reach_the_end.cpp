#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,r1,r2;
const int inf=1e18;
vector<vector<int>>g;
vector<int>prime;
void seive(){
    prime[0]=prime[1]=0;
    for(int i=2;i<n;i++){
        if(prime[i]==1&&i*i<=n){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        prime[i]+=prime[i-1];
    }
}
bool special(int r){
    int p=prime[r];
    int np=n-p;
    return r2*p>=r1*r;
}
vector<int>dis;
void bfs(int s){
    queue<int>q;
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int node=q.front();
        q.pop();
       for(int v :g[node]){
            if(dis[v]==inf){
                dis[v]=dis[node]+1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>x>>r1>>r2;
    prime.resize(n+1,1);
    seive();
    // for(int i=0;i<=n;i++){
    //     cout<<i<<" "<<prime[i]<<" "<<special(i)<<"\n";
    // }
    
    dis.resize(n+1,inf);
    g.resize(n+1);
    for(int i=1;i<=n;i++){
        g[i].push_back(i+1);
        if(special(i)&&(i+x)<=n){
            g[i].push_back(i+x);
        }
    }
    bfs(1);
    cout<<dis[n];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}