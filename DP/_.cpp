
#include <bits/stdc++.h>
using namespace std;


#define ll int64_t
int n;
vector<int>ar;
vector<vector<bool>>dp;
vector<int> giveVec(int level,int remSum){
    int rem=remSum;
    vector<int>ans;
    for(int i=0;i<level;i++){
        for(int j=rem;j>=0;j--){
            if(dp[i][j]!=-false){
                
            }
        }
    }
}

bool rec(int level,int remSum){
    //base case
    if(remSum==0){
        return true;
    }
    if(level==n){
        if(remSum==0){
            return true;
        }
        else{
            return false;
        }
    }
    //cache check
    if(dp[x][remSum]!=-1){
        return dp[x][remSum];
    }
    //compute
    bool ans=false;
    for(auto x:ar){
        if(x<=remSum){
            ans|=rec(level+1,remSum-x);
        }
    }
    //save and return 
    return dp[level][remSum]=ans;
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    ar=arr;
    
    vector<vector<int>>ans;
    for(auto q:queries){
        dp.clear();
        dp.assign(arr.size()+1,vector<bool>(q+1,false));
        if(rec(0,q)==true){
            ans.push_back(giveVec(0,q));
        }else{
            ans.push_back({-1});
        }
    }
    return ans;
}
 

void solve() {
    int N, Q;
    cin >> N >> Q;
    int n=N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
