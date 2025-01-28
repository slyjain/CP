#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
struct monotone_deque{
    deque<int>dq;
    void insert(int x){
        while(!dq.empty()&&dq.back()>x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void erase(int x){
        if(dq.front()==x){
            dq.pop_front();
        }
    }
    int getMin(){
        return dq.front();
    }
};
void solve(){
     int n,m;
     cin>>n>>m;
     int a[n][m];
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
     }
     int dp[n][m];
     memset(dp,0,sizeof(dp));
     for(int i=0;i<n;i++){
        
        
        for(int j=0;j<m;j++){
            
            
            if(i==0){
                dp[i][j]=a[i][j];
            }else{
                
               int x=j+1<m?dp[i-1][j+1]:0;
               int y=dp[i-1][j];
               int z=j-1>=0?dp[i-1][j-1]:0;
               
                dp[i][j]=max({a[i][j],x,y,z});
               

            }
        }
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<(dp[i][j]==a[i][j]);
        }
        cout<<"\n";
     }
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