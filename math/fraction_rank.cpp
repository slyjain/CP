    #include<bits/stdc++.h>
    using namespace std;
    #define int long long

    void solve(){
    int n;
    cin>>n;
    int a,b;
    set<int>st;
    
    for(int i=1;i<=n;i++){

    }
    for(double i=0;i<=n;i+=1){
        for(int j=i+1;j<=n;j+=1){
            st.insert(i/j);
        }

    }
    // cout<<"hi";
    int i=1;
    for(auto x:st){
        if(x==a/b){
            cout<<i<<"\n";
            return;
        }
        i++;
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