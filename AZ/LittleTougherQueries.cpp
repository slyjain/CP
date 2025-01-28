// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define MAXN 100010
// int a[MAXN];
// vector<int> t[4*MAXN];

// void build(int id,int l,int r){
//     for(int i=l;i<r;i++){
//         t[id].push_back(a[i]);
//     }
//     sort(t[id].begin(),t[id].end());
//     if(l==r){
//         return;
//     }
//     int mid=(l+r)>>1;
//     build(id<<1,l,mid);
//     build(id<<1|1,mid+1,r);
//     // t[id]=t[id<<1]+t[id<<1|1];
// }

// int query(int id,int l,int r,int lq,int rq,int x){
//     cout<<"Here"<<"\n";
//         if(r<lq||l>rq){
//             return 0;
//         }
//         if(l>=lq&&r<=rq){
//             return binarySearch(id,x);
//         }
//         int mid=(l+r)/2;
//         return query(2*id,l,mid,lq,rq,x)+query(2*id+1,mid+1,r,lq,rq,x);
// }

// void solve(){
//     int n,q;
//     cin>>n>>q;
//     for(int i=1;i<=n;i++){
//         // int x;
//         cin>>a[i];
//         // a[x]=1;
//     }
//     build(1,1,n);
    

// }

// signed main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     solve();
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100010
int a[MAXN];
vector<int> t[4*MAXN];

void build(int id,int l,int r){
    for(int i=l;i<=r;i++){
        t[id].push_back(a[i]);
    }
    sort(t[id].begin(),t[id].end());
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
}

// int binarySearch(int id,int x){
//     int lo=0,hi=t[id].size()-1;
//     int ans=-1;
//     while(lo<=hi){
//         int mid=(lo+hi)/2;
//         if(t[id][mid]<=x){
//             ans=mid;
//             lo=mid+1;
//         }else{
//             hi=mid-1;
//         }
//     }
//     return ans+1;
// }
int binarySearch(int id,int x){
    int lo=0,hi=t[id].size()-1;
    int ans=-1;
    // cout<<"Yeaha"<<"\n";
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(t[id][mid]<=x){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return ans+1;
}
// int query(int id,int l,int r,int lq,int rq,int x){
//     if(r<lq||l>rq){
//         return 0;
//     }
//     if(l>=lq&&r<=rq){
//         return binarySearch(id,x);
//     }
//     int mid=(l+r)/2;
//     return query(2*id,l,mid,lq,rq,x)+query(2*id+1,mid+1,r,lq,rq,x);
// }
int query(int id,int l,int r,int lq,int rq,int x){
    // cout<<"Here"<<"\n";
        if(r<lq||l>rq){
            return 0;
        }
        if(l>=lq&&r<=rq){
            return binarySearch(id,x);
        }
        int mid=(l+r)/2;
        return query(2*id,l,mid,lq,rq,x)+query(2*id+1,mid+1,r,lq,rq,x);
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    // while(q--){
    //     int l,r,k;
    //     cin>>l>>r>>k;
    //     int lo=0,hi=1e9+10;
    //     int ans=-1;
    //     while(lo<=hi){
    //         int mid=(lo+hi)/2;
    //         if(query(1,1,n,l,r,mid)>=k){
    //             ans=mid;
    //             hi=mid-1;
    //         }else{
    //             lo=mid+1;
    //         }
    //     }
    //     cout<<ans<<"\n";
    // }  
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        int lo=0,hi=1e9+10;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(query(1,1,n,l,r,mid)>=k){
                // cout<<"here"<<"\n";
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        cout<<ans<<"\n";
    }   
 
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
