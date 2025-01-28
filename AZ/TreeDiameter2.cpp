#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>g;
vector<int>depth,parent;
void dfs(int node,int par,int dep){
    parent[node]=par;
    depth[node]=dep;
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node,dep+1);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    g.clear();
    g.resize(n+1,vector<int>());
    depth.clear();
    depth.resize(n+1,0);
    parent.resize(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    int maxDep=-1e9,leaf;
    for(int i=1;i<=n;i++){
        if(depth[i]>maxDep){
            maxDep=depth[i];
            leaf=i;
        }
        // cout<<depth[i]<<" ";
    }
    // cout<<"\n"<<leaf<<"\n";
    // depth.clear();
    // depth.resize(n+1,0);
    dfs(leaf,0,0);
    int diaLeaf=0;
    maxDep=-1e9;
    for(int i=1;i<=n;i++){
        if(depth[i]>maxDep){
            maxDep=depth[i];
            diaLeaf=i;
        }
        // cout<<depth[i]<<" ";
    }
    // cout<<"\n";
    if(maxDep%2==1){
        // cout<<"HERE\n";
        //2 centre case
        int center1,center2;
        int curr=diaLeaf;
        int currDep=0;
        while(curr!=leaf){
            if(currDep==maxDep/2){
                center1=curr;
            }
            if(currDep==(maxDep/2)+1){
                center2=curr;
            }
            curr=parent[curr];
            currDep++;
        }
        // cout<<center1<<" "<<center2<<"\n";
        depth.clear();
        depth.resize(n+1,0);
        dfs(center1,center2,0);
        int c1=0,c2=0;
        for(int i=1;i<=n;i++){
            if(depth[i]==maxDep/2){
                c1++;
            }
        }
        depth.clear();
        depth.resize(n+1,0);

        dfs(center2,center1,0);
        for(int i=1;i<=n;i++){
            if(depth[i]==maxDep/2){
                c2++;
            }
        }
        cout<<c1*c2<<"\n";

    }else{
        //one centre case
        int center1;
        int curr=diaLeaf;
        int currDep=0;
        while(curr!=leaf){
            if(currDep==maxDep/2){
                center1=curr;
            }
            curr=parent[curr];
            currDep++;
        }
        // cout<<center1<<" "<<maxDep<<"\n";
        vector<int>diameterNo(g[center1].size(),0);
        int nodeNo=0;
        for(auto v:g[center1]){
            // cout<<v<<" :";
            depth.clear();
            depth.resize(n+1,0);
            dfs(v,center1,1);
            
            for(int i=1;i<=n;i++){
                if(depth[i]==maxDep/2){
                    // cout<<v<<" ";
                    diameterNo[nodeNo]++;
                }
                // cout<<depth[i]<<" ";
            }
            nodeNo++;
            // cout<<'\n';
        }
        // cout<<"\n";
        int sum=0,sumOfSquare=0;
        for(int i=0;i<diameterNo.size();i++){
            // cout<<diameterNo[i]<<"\n";
            sum+=diameterNo[i];
            sumOfSquare+=(diameterNo[i]*diameterNo[i]);
        }
        cout<<(sum*sum-sumOfSquare)/2;

    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}