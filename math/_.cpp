#include<bits/stdc++.h>
using namespace std;
#define int long long
int fact[500010],invFact[500010];
int mod=1e9+7;
int add(int a,int b){
    a=(a+b+mod)%mod;
    while(a<0){
        a+=mod;
    }
    return a;
}
int mul(int a,int b){
    return (a*b)%mod;
}
int binpow(int a,int p){
    int temp=a;
    int ans=1;
    while(p){
        // cout<<p<<" "<<temp<<"\n";
        if(p%2==1){
            ans=(mul(ans,temp))%mod;
        }
        p>>=1;
        temp=mul(temp,temp)%mod;
    }
    return ans%mod;
}

void pre2(){
    for(int i=0;i<100010;i++){
        invFact[i]=binpow(fact[i],mod-2);
    }
}
void pre(){
    fact[0]=1;
    for(int i=1;i<100010;i++){
        fact[i]=(mul(i,fact[i-1]))%mod;
    }
}
int ncr(int n,int r){
    if(r>n)return 0;
    if(r==0||r==n){
        return 1;
    }
    int ans= mul(fact[n],mul(invFact[n-r],invFact[r]));
    if(ans<0){
        ans+=mod;
    }
    return ans;
}
void solve(){
   
   
    pre();pre2();
    // for(int i=0;i<100;i++){
    //     cout<<fact[i]<<" "<<invFact[i]<<"\n";
    // }
    
    int n,m,k;
    cin>>n>>m>>k;
    int i=0;
    int sum=0;
    while(n+k-1-i*m>=(n-1)&&i<=n){
        // cout<<sum<<"\n";
        if(i%2==0){
            sum=(add(sum,mul(ncr(n+k-1-i*m,n-1),ncr(n,i))))%mod;
        }else{
            sum=(add(sum,-mul(ncr(n,i),ncr(n+k-1-i*m,n-1))))%mod;
        }
        i++;
    }
    cout<<sum;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}