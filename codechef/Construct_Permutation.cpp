        #include<bits/stdc++.h>
        using namespace std;
        #define int long long

        void solve(){
            int n;
            cin>>n;
            
            if(n%2==0){cout<<-1<<"\n";return;}
            int o=n,e=2;
            for(int i=0;i<n;i++){
                if(i%2){
                    cout<<e<<" ";
                    e+=2;
                }else{
                    cout<<o<<" ";o-=2;
                }
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