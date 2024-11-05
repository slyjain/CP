#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first 
#define S second
using state=pair<int,int>;
int n,m;
char a[1001][1001];
state parent[1001][1001];
int dist[1001][1001];
char path[1001][1001];
state start ,finish;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char p[]={'D','U','R','L'};
bool isValid(int ny,int nx){
    if(ny>=0&&ny<n&&nx>=0&&nx<m&&a[ny][nx]!='#'){
        return true;
    }
    return false;
}
vector<pair<state,char>> neigh(state node){
    vector<pair<state,char>>ne;
    for(int i=0;i<4;i++){
        int ny=node.F+dy[i];
        int nx=node.S+dx[i];
        if(isValid(ny,nx)){
            ne.push_back({{ny,nx},p[i]});
        }
    }
    return ne;
}
void bfs(state start){
    queue<state>q;
    q.push(start);
    dist[start.F][start.S]=0;
    while(!q.empty()){
        state node=q.front();
        q.pop();
        for(auto x : neigh(node)){
            state v= x.F;
            if(dist[v.F][v.S]==1e9){
                 dist[v.F][v.S]=1+dist[node.F][node.S];
                 q.push(v);
                 parent[v.F][v.S]=node;
                 path[v.F][v.S]=x.S;
            }
        }
        
    }
}
void solve(){
    cin>>n>>m;
    state A,B;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            dist[i][j]=1e9;
            if(a[i][j]=='A'){
                A={i,j};
            }
            if(a[i][j]=='B'){
                B={i,j};
            }
        }
    }
    bfs(A);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<path[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    if(dist[B.F][B.S]!=1e9){
        cout<<"YES\n";
        cout<<dist[B.F][B.S];
        cout<<"\n";
        state node=B;
        vector<char>drul;
        while(node!=A){
            drul.push_back(path[node.F][node.S]);
            node=parent[node.F][node.S];
        }
        reverse(drul.begin(),drul.end());
        for(auto c:drul){
            cout<<c;
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