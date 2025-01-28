#include<bits/stdc++.h>
using namespace std;
#define int long long
int p[1000010];
vector<int>primes;
void pre(){
    for(int i=2;i<1000010;i++){
        p[i]=i;
    }
    for(int i=2;i<1000010;i++){
        if(p[i]==i){
            primes.push_back(i);
            for(int j=2*i;j<1000010;j+=i){
                if(p[j]==j){
                    p[j]=i;
                }
            }
        }
    }

}
int totalP(int x){
    int cnt=0;
    while(x!=1){
        x/=p[x];
        cnt++;
    }
    return cnt;
}
void solve(){
    int h,k;
    cin>>h>>k;
    int mx=totalP(h);
    int cnt=0;
    while(k){
        k/=2;
        cnt++;
    }
    cnt--;
    cout<<mx+cnt<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre();
    cout.tie(0);int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}