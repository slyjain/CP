#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     string s;
     cin>>s;
     int n=s.size();
    //  cout<<n<<" ";
     map<char,int>mp;
    // for(int i=0;i<25;i++){
    //     mp['a'+i];
    // }
     mp['a']=1;
     mp['e']=2;
     mp['i']=3;
     mp['o']=4;
     mp['u']=5;

     //11111->63
     int k=0;;
     int tail=0,head=tail-1;
     int ans=0;
     while(tail<n){
        
        while((head+1)<n&&(k|((mp[s[head+1]]!=0)?(1<<(mp[s[head+1]]-1)):0))<31){
            head++;
            if(mp[s[head]]!=0){
                k|=(1<<(mp[s[head]]-1));
            }
        }
        // cout<<head<<" "<<tail<<"\n";
        ans+=(head-tail+1);
        if(head<tail){
            tail++;
            head=tail-1;
            k=0;
        }else{
            if(mp[s[tail]]!=0){
                k&=(~(1<<(mp[s[tail]]-1)));
               
            }
             tail++;
        }
     }
     cout<<(n*(n+1)/2-ans)<<"\n";
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