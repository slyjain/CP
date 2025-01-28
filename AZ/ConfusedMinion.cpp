#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,l;
    cin>>n>>l;
    vector<pair<int,int>>mv;
    for(int i=0;i<l;i++){
        int time,dir;
        cin>>time>>dir;
        mv.push_back({time,dir});
    }
    sort(mv.begin(),mv.end());
    int pre=0,currDir=0;
    int curX=0,curY=0;
    for(auto curr:mv){
        int timeSpent=curr.first-pre;
        pre=curr.first;
        if(currDir==0){
            curX+=timeSpent;
        }else if(currDir==1){
            curY-=timeSpent;
        }else if(currDir==2){
            curX-=timeSpent;
        }else{
            curY+=timeSpent;
        }
        if(curr.second==0){
            currDir=(currDir-1+4)%4;
        }else if(curr.second==1){
            // cout<<"Main aya";
            currDir=(currDir+1)%4;
        }
        // cout<<curX<<" "<<curY<<" "<<currDir<<"\n";
    }
    if(pre<n){
        int timeSpent=n-pre;
      if(currDir==0){
            curX+=timeSpent;
        }else if(currDir==1){
            curY-=timeSpent;
        }else if(currDir==2){
            curX-=timeSpent;
        }else{
            curY+=timeSpent;
        }  
        // cout<<curX<<" "<<curY<<" "<<currDir<<"\n";
    }
    cout<<curX+curY;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}