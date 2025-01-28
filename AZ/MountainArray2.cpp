#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n;
vector<int>arr;
int dp1[10100],dp2[10100];
//lis in nlogn starting at level
vector<int>list1,list2;
void f2(){
     for(int i=n-1;i>=0;i--){
        if(list2.empty()||list2.back()<arr[i]){
            
            list2.push_back(arr[i]);
            dp2[i]=list2.size();
        }
        else{
            auto it=lower_bound(list2.begin(),list2.end(),arr[i]);
            int index=it-list2.begin();
            list2[index]=arr[i];
            dp2[i]=index+1;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<dp2[i]<<" ";
    // }
    // cout<<"\n";
}
void f1(){
    for(int i=0;i<n;i++){
        if(list1.empty()||list1.back()<arr[i]){
            
            list1.push_back(arr[i]);
            dp1[i]=list1.size();
        }
        else{
            auto it=lower_bound(list1.begin(),list1.end(),arr[i]);
            int index=it-list1.begin();
            list1[index]=arr[i];
            dp1[i]=index+1;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<dp1[i]<<" ";
    // }
    // cout<<"\n";
}

void solve(){
    cin>>n;
    arr.clear();
    list1.clear();
    list2.clear();
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    f1();
    f2();
    int mnLen=-1;
    int ans=INF;
    for(int i=0;i<n;i++){
        if(dp1[i]>1&&dp2[i]>1){
            mnLen=max(mnLen,dp1[i]+dp2[i]-1);
            
            ans=min(ans,n-mnLen);
            // cout<<n<<" "<<mnLen<<" "<<ans<<"\n";
        }
    }
    cout<<(ans==INF?-1:ans)<<"\n";
    // rec2(n-1);


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}