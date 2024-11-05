#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
#define ll long long
using state=pair<ll,ll>;
using dis=pair<state,ll>;
vector<string>maze;
vector<vector<ll>>distancesM;
vector<vector<ll>>distancesP;
queue<dis>q;
ll n,m;
ll dy[]={0,0,-1,1};
ll dx[]={1,-1,0,0};
vector<state> neighbors(state src,vector<vector<ll>>&distances){
  ll x=src.first;
  ll y=src.second;
  vector<state> neighbor;
  for(ll i=0;i<4;i++){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx<n&&nx>=0&&ny<m&&ny>=0&&distances[nx][ny]==INF&&maze[nx][ny]!='#'){
      neighbor.push_back({nx,ny});
    }
  }
  return neighbor;
}
void dfs(vector<vector<ll>>&distances){
  while(!q.empty()){
    auto temp=q.front();
    q.pop();
    state src=temp.first;
    ll d=temp.second;
    for(auto nodes:neighbors(src,distances)){
      if(distances[nodes.first][nodes.second]>d+1){
        distances[nodes.first][nodes.second]=d+1;
        q.push({nodes,d+1});
      }
        
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n>>m;
  // cout<<n<<"\t"<<m<<"\n";
  distancesM.assign(n,vector<ll>(m,INF));
  distancesP.assign(n,vector<ll>(m,INF));
  for(ll i=0;i<n;i++){
    string x;

    cin>>x;
    // cout<<i<<"\t"<<x<<"\n";
    maze.push_back(x);
  }
  // cout<<n<<" strings were read";
  state person;
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
        if(maze[i][j]=='M'){
            q.push({{i,j},1});
            distancesM[i][j]=1;
        }
        else if(maze[i][j]=='A'){
            person={i,j};
            distancesP[i][j]=1;
        }
    }
  }
  dfs(distancesM);
  q.push({person,1});
  dfs(distancesP);
  ll mn=INF;
  bool isEscapePossible=false;
  for(ll i=0;i<n;i++){
    if(distancesM[i][0]>distancesP[i][0]){
      isEscapePossible=true;
      mn=min(mn,distancesP[i][0]);
    }
  }
  for(ll i=0;i<n;i++){
    if(distancesM[i][m-1]>distancesP[i][m-1]){
      isEscapePossible=true;
      mn=min(mn,distancesP[i][m-1]);
    }
  }
  
  for(ll i=0;i<m;i++){
    if(distancesM[0][i]>distancesP[0][i]){
      isEscapePossible=true;
      mn=min(mn,distancesP[0][i]);
    }
  }
  for(ll i=0;i<m;i++){
    if(distancesM[n-1][i]>distancesP[n-1][i]){
      isEscapePossible=true;
      mn=min(mn,distancesP[n-1][i]);
    }
  }
  if(isEscapePossible){
    cout<<"The min distance is "<<mn;
  }
  else{
    cout<<"Not possible";
  }
    return 0;
}