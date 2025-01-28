#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE

pair<double,double>p[101];
double sq(double x){
    return x*x;
}

double cost(int x, int y) {
    if (y == x + 1) return 0;
    double dx = p[x].first - p[y].first;
    double dy = p[x].second - p[y].second;
    double dist_sq = sq(dx) + sq(dy);
    // cout << "Cost between points " << x << " and " << y << ": " << sqrt(dist_sq) << "\n";
    return sqrt(dist_sq);
}

double dp[101][101];
bool vis[101][101];
void solve(){
     int n;
     cin>>n;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = numeric_limits<double>::infinity();
                vis[i][j]=false;
            }
        }
     for(int i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
        cout<<p[i].first<<" "<<p[i].second<<"\n";
     }
     for(int len=0;len<=n-1;len++){
        for(int st=1;st<=n-len;st++){
            int en=st+len;
            vis[st][en]=true;
            if(st==en){dp[st][en]=0;}
            else if(en==st+1){dp[st][en]=0;}
            else if(en==st+2){dp[st][en]=0;}
            else{
                for(int mid=st+1;mid<en;mid++){
                    
                    dp[st][en]=min(dp[st][en],dp[st][mid]+dp[mid][en]+cost(st,mid)+cost(mid,en));
                    cout<<st<<" "<<en<<" "<<mid<<" "<<cost(st,mid)+cost(mid,en)<<"\n";
                }
            }
        }
     }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]==false){
                cout<<-1<<"\t";
            }else{
                cout<<dp[i][j]<<"\t";
            }
            
        }
        cout<<"\n";
     }
     cout<<dp[1][n];
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