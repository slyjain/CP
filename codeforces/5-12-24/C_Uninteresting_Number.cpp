#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;
    int freq[2]={0};
    int sum=0;
    for(auto x:s){
        sum+=(int)(x-'0');
        if((int)(x-'0')==2){
            freq[0]++;
        }
        if((int)(x-'0')==3){
            freq[1]++;
        }
    }
    if(sum%9==0){
        cout<<"YES\n";
    }else if(sum%2==1){
        int posiDev=2*freq[0]+6*freq[1];
        int mul=(sum+9)/9;
        if(mul%2!=1){
            mul++;
        }
        int dev=mul*9-sum;
        bool posible=false;
        while(dev<=posiDev&&!posible){
            int dev6=dev/6;
            int rem=dev-min(dev6,freq[1])*6;
            if(rem/2<=freq[0]){
                posible=true;
            }
            dev+=18;
        }
        if(posible){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }else{
        int posiDev=2*freq[0]+6*freq[1];
        int mul=(sum+9)/9;
        if(mul%2!=0){
            mul++;
        }
        int dev=mul*9-sum;
        bool posible=false;
        while(dev<=posiDev&&!posible){
            int dev6=dev/6;
            int rem=dev-min(dev6,freq[1])*6;
            if(rem/2<=freq[0]){
                posible=true;
            }
            dev+=18;
        }
        if(posible){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
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