#include<bits/stdc++.h>
using namespace std;
#define int long long
//return what is asked in questions(Generally)
int n;
int rec(int level){
//level -> stair i am at
//prunning code
if(level==n){
    return 1;// counting problems have base case as 1
}
//loop over choices
int ans=0;
for(int i=1;i<=3;i++){
    if(level+i<=n){
        int ways+=rec(level+i);
        ans+=ways;
    }
}
return ways;
}
void solve(){

cin>>n;
rec(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0)
    solve();
    return 0;
}
