#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q;
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
    cin>>n>>m>>q;
    rnk.assign(n,1);
    st_size=n;
    par.resize(n);
    for(int i=0;i<n;i++){
        par[i]=i;
    }
    
    // map<pair<int,int>,int>mp;
    vector<pair<int,int>>edgeList;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        // cout<<a<<" "<<b<<'\n';
        if(a>b)swap(a,b);
        // mp[{a,b}]=i;
        edgeList.push_back({a,b});
    }
    
    vector<pair<int,int>>queries;
    set<int>st;
    for(int i=0;i<m;i++){
        st.insert(i);
    }
    while(q--){
        int c;
        cin>>c;

        if(c==1){
            int x;
            cin>>x;
            x-=1;
            st.erase(x);
            queries.push_back({c,x});
            // cout<<c<<" "<<x<<"\n";
            
        }else{
            queries.push_back({c,0});
        }
    }
// cout<<"here :";
    for(auto x:st){
        // cout<<x<<" ";
        merge(edgeList[x].first,edgeList[x].second);
    }
    // cout<<'\n';
    vector<int>ans;
    reverse(queries.begin(),queries.end());
    for(auto x:queries){
        if(x.first==1){
            merge(edgeList[x.second].first,edgeList[x.second].second);
        }else{
            // cout<<st_size<<"\n";
            ans.push_back(st_size);
        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}