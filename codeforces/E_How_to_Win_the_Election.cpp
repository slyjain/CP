#include <bits/stdc++.h>
using namespace std;
#define int long long
multiset<int>Topk,bottomN_k;
vector<int> a;
int n, m, k;

bool check(int v, int mid, int rem) {
    // cout<<v<<" "<<mid<<" "<<rem<<"\n";
    auto it=Topk.find(a[v]);
    // cout<<*it<<"\n";
    if(it!=Topk.end()){
        // cout<<"HERE1\n";
      if(!bottomN_k.empty()&&(*it)+mid>=(*bottomN_k.rbegin())+rem){
        // cout<<"HERE1\n";
        return true;
      }      
    
    }
    else{
        auto it2=bottomN_k.find(a[v]);
        if(it2!=bottomN_k.end()){
            // cout<<"HERE2\n";
            if(!Topk.empty()&&(*it2)+mid>=(*Topk.begin())+rem){
                // cout<<"HERE2\n";
            return true;
        }
        }
        
    }
    return false;
}

signed main() {
    Topk.clear();
    bottomN_k.clear();
    a.clear();
    cin >> n >> m >> k;
    a.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        Topk.insert(a[i]);
        if(!Topk.empty()&&Topk.size()>m){
            auto it=Topk.begin();
            int val=*it;
            bottomN_k.insert(val);
            Topk.erase(it);

        }
    }
    if(n==m){
        for(int i=0;i<n;i++){
            cout<<"0 ";
        }
        exit;
    }
    
    
    vector<int> ci(n);
    int remVotes = k - sum;
    
    for (int i = 0; i < n; i++) {
        
            int lo = 0, hi = remVotes;
            int ans = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (check(i, mid, remVotes - mid)) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                    
                }
            }
            ci[i] = ans;
        
    }
    
    for (int i = 0; i < n; i++) cout << ci[i] << " ";
    
    return 0;
}