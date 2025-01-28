#include <bits/stdc++.h>
using namespace std;
#define int long long
// do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
set<int> PrimeFactorisation(int n)
{
    set<int> ans;
    ans.insert(1);
    int temp = n;
    for (int i = 2; i * i <= n; i++)
    {
        bool isFactor = false;
        while(temp % i == 0)
        {
            temp /= i;
            isFactor = true;
        }
        if (isFactor)
        {
            ans.insert(i);
        }
    }
    if(temp>1){
        ans.insert(temp);
    }
    return ans;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    set<int>temp=PrimeFactorisation(__gcd(a,b));
    
    // for (auto v : temp)
    // {
    //     cout << v << " ";
    // }
    cout<<temp.size()<<"\n";
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}