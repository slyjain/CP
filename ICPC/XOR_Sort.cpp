#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int arr[100010];
pair<int,int> ori[100010];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ori[i].first=arr[i];
        ori[i].second=i;
    }
    sort(ori,ori+n);
    vector<pair<int,int>>ans;
    int i=n-1,j=n-1;
    while(i>=0){
        if(arr[i]<ori[j].first){
            ans.push_back({i,ori[j].second});
            int temp=arr[i];
            arr[i]=ori[j].first;
            ori[temp].second=ori[j].second;
        }
        i--;
        j--;
    }
    cout<<ans.size()*3<<"\n";
    for(i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n"<<ans[i].second<<" "<<ans[i].first<<"\n"<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}