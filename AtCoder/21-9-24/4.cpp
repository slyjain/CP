#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=1e9+7;
//typedef long long ll;
ll n;

int main()
{    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    //cout<<n;
    vector<ll>a;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    stack<ll>s;
    vector<ll>ans(n);
    for(ll i=n-1;i>=0;i--){
          ans[i]=s.size();
        while(!s.empty()&&s.top()<a[i]){
            s.pop();
        }
        s.push(a[i]);
    }
    for(ll i=0;i<n;i++){
      cout<<ans[i]<<" ";
    }
    return 0;
}
