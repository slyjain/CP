#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
   
    cin>>n;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i <n-j; i++)
        {
            cout<<" ";
        }
        for(int i=0;i<2*j-1;i++){
            cout<<"*";
        }
        
        cout<<"\n";
    }
     for (int j = n; j >= 1; j--)
    {
        for (int i = 0; i <n-j; i++)
        {
            cout<<" ";
        }
        for(int i=0;i<2*j-1;i++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}