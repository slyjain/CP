#include<bits/stdc++.h>
using namespace std;
#define int long long
int t[1000];
int s[1000];
int taken[1000];
int n,x,k;
bool check(int item_number){
    int timeTaken=0;
    int itemTaken=0;
    for(int i=0;i<item_number;i++){
        if(taken[i]==1){
            timeTaken+=t[i];
            itemTaken++;
        }
    }
    itemTaken++;
    timeTaken+=t[item_number];
    if(item_number>k||timeTaken>x){
        return false;
    }
    return true;
}
int rec(int item_number){
    if(item_number==n){
        int skill_collected=0;
        for(int i=0;i<n;i++){
            if(taken[i]){
                skill_collected+=s[i];
            }
        }
        return skill_collected;
    }
    int ans=rec(item_number+1);
    if(check(item_number)){
         taken[item_number]=1;
        ans=max(ans,rec(item_number+1));
        taken[item_number]=0;
    }
    return ans;
}
void solve(){
     memset(taken,0,sizeof(taken));
     cin>>n;
     for(int i=0;i<n;i++){
        cin>>t[i]>>s[i];
     }
     cin>>x>>k;
     cout<<rec(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0)
    solve();
    return 0;
}