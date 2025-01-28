#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
int n,p,k;
cin>>n>>k>>p;
int sum=0,mx=0;
for(int i=0;i<n;i++){
int x;
cin>>x;
sum+=x;
mx=max(mx,x);

}
sum-=mx;
if((p+sum)==(k+mx)){
    cout<<"Equal";
}
else if((p+sum)>(k+mx)){
    cout<<"Varun";
}else{
    cout<<"Ved";
}
cout<<"\n";
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