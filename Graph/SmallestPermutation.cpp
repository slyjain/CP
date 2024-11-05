#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int>indegree;
vector<int>topo;
vector<vector<int>>g;
void bfs(){
    priority_queue<int>pq;
    for(int i=1;i<=n;i++){
      if(indegree[i]==0){
        pq.push(-1*i);
        // cout<<i<<" ";
      }
    }
    // cout<<"\n";   
    while(pq.empty()==false){
      int cur=-1*pq.top();
      // cout<<cur<<" ";
      pq.pop();
      topo.push_back(cur);
      for(auto v:g[cur]){
        indegree[v]--;
        if(indegree[v]==0){
          pq.push(-1*v);
        }
      }
    }
    
}
signed main() {
  cin>>n>>m;
  g.resize(n+1);
  indegree.assign(n+1,0);

  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    indegree[y]++;

  }

  bfs();
  // reverse(topo.begin(),topo.end());
  if(topo.size()==n){
for(auto v:topo){
    cout<<v<<" ";
  }
  }
  else{
    cout<<-1;
  }
  


    return 0;
}