#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m;
int arr[1001][1001];
int ans[1001][1001];
int rec(int row,int col){
    //base case 
    if(row==0||col==0){
        return ans[row][col];
    }
    //cachec check
    if(ans[row][col]!=-1){
        return ans[row][col];
    }
    //compute
    if(arr[row][col]==0){
        return ans[row][col]=0;
    }
    else if(arr[row][col]==1){
        ans[row][col]=1+min({rec(row-1,col),rec(row-1,col-1),rec(row,col-1)});
    }
    return ans[row][col];
}
void solve(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(arr,-1,sizeof(arr));
        memset(ans,-1,sizeof(ans));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                if(i==0||j==0){
                    ans[i][j]=arr[i][j];
                }
            }
        }
        int maxSeen=0;
        rec(n-1,m-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<rec(i,j)<<" ";
                maxSeen=max(maxSeen,rec(i,j));
            }
            // cout<<"\n";
        }
        cout<<maxSeen*maxSeen<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}