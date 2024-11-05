#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, arr[1001];
vector<int>lis;
vector<int>print_lis;
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print_lis.resize(n);
    for(int i=0;i<n;i++){
        if(lis.empty()||lis.back()<arr[i]){
            lis.push_back(arr[i]);
            print_lis[i]=lis.size();

        }
        else{
            auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
            *it=arr[i];
            print_lis[i]=it-lis.begin()+1;
        }
    }
    int cnt=lis.size();
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        if(cnt==print_lis[i]){
            ans.push_back(arr[i]);
            cnt--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto v:ans){
        cout<<v<<" ";
    }
    cout<<"\n";
    cout<<lis.size();
     
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}