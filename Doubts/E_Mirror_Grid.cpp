#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[101][101];
int n;
int l1[101],l2[101],l3[101],l4[101];
int layerCorrector(int l){
    int count=0;
    for(int i=l;i<n-1-l;i++){
        l1[count]=arr[l][i];
        l2[count]=arr[i][n-1-l];
        l3[count]=arr[n-1-l][n-1-i];
        l4[count]=arr[n-1-i][l];
        count++;
        // cout<<l1[i-l]<<" ";
    }
    
    int ans=0;
    for(int i=0;i<count;i++){
        // cout<<l1[i]<<" ";
        int oneCount=0;
        if(l1[i]==1){
            oneCount++;
        }
        if(l4[i]==1){
            oneCount++;
        }
        if(l2[i]==1){
            oneCount++;
        }
        if(l3[i]==1){
            oneCount++;
        }
        ans+=min(oneCount,4-oneCount);

    }
    // cout<<"\n";
    // for(int i=0;i<count;i++){
        
    // }
    // // cout<<"\n";
    // for(int i=0;i<count;i++){
        
    // }
    // // cout<<"\n";
    // for(int i=0;i<count;i++){
        
    // }
    // cout<<"\n";

    // for(int i=l;i<)
    return ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;

            arr[i][j]=c-'0';
            // cout<<arr[i][j]<<" ";
        }
        // cout<<"\n";
        
    }
    int ans=0;
    for(int i=0;i<(n/2);i++){
        ans+=layerCorrector(i);
        // cout<<i<<" ";
    }
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
   
    return 0;
}