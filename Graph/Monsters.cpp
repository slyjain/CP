#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first 
#define S second
using state=pair<int,int>;
int n,m;
char a[1001][1001];
state parent[1001][1001];
int ad[1001][1001];
int md[1001][1001];
char mp[1001][1001];
char ap[1001][1001];
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
void mbfs(queue<state>q){
    
    
    
    while(!q.empty()){
        state node=q.front();
        q.pop();
        for(auto x : neigh(node)){
            state v= x.F;
            if(md[v.F][v.S]==1e9){
                 md[v.F][v.S]=1+md[node.F][node.S];
                 q.push(v);
                //  parent[v.F][v.S]=node;
                 mp[v.F][v.S]=x.S;
            }
        }
        
    }
}
void bfs(queue<state>q){
    
    start=q.front();
    ad[start.F][start.S]=0;
    while(!q.empty()){
        state node=q.front();
        q.pop();
        for(auto x : neigh(node)){
            state v= x.F;
            if(ad[v.F][v.S]==1e9){
                 ad[v.F][v.S]=1+ad[node.F][node.S];
                 q.push(v);
                 parent[v.F][v.S]=node;
                 ap[v.F][v.S]=x.S;
            }
        }
        
    }
}
void solve(){
    cin>>n>>m;
    state A,B;
    queue<state>mq,aq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            md[i][j]=1e9;
            ad[i][j]=1e9;
            if(a[i][j]=='A'){
                aq.push({i,j});
            }
            if(a[i][j]=='M'){
                mq.push({i,j});
                md[i][j]=0;
            }
        }
    }
    mbfs(mq);
    bfs(aq);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<ad[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }
    bool marega=true;
    bool once=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0||i==n-1||j==m-1){
                if(md[i][j]>ad[i][j]&&a[i][j]!='#'){
                    once=false;
                marega=false;
        cout<<"YES\n";
        // cout<<i<<" "<<j;
        cout<<ad[i][j];
        cout<<"\n";
        state node={i,j};
        vector<char>drul;
        while(node!=A){
            drul.push_back(ap[node.F][node.S]);
            node=parent[node.F][node.S];
        }
        reverse(drul.begin(),drul.end());
        for(int c=1;c<drul.size();c++){
            cout<<drul[c];
        }
    }
            }
            if(once==false){
                break;
            }
            
    
        }
        if(once==false){
                break;
            }
    }
    if(marega){
        cout<<"NO";
    }
    
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}