    #include<bits/stdc++.h>
    using namespace std;
    #define int long long

    void solve(){
    int k,l1,r1,l2,r2;
    cin>>k>>l1>>r1>>l2>>r2;
    int curr=1;
    int ans=0;
    while(curr<=(r2)){
        
        int n1=min(r2,curr*r1);
        int n2=max(l2,l1*curr);
        // cout<<curr<<" "<<n1<<" "<<n2<<" "<<((n1-n2+curr)<0?0:(n1-n2+curr)/curr)<<"\n";
        if(n2<=n1){
            int st=(n2+curr-1)/curr;
            int en=n1/curr;
            ans+=max(en-st+1,(int)0);
        }

    // ans+=((n1-n2+curr)<0?0:(n1-n2+curr)/curr);
    curr*=k;
    }
    cout<<ans<<"\n";
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