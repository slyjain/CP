#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a;
int n,m,k;
int check(int v,int mid,int rem){
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        if(i==v)continue;
        pq.push(-a[i]);
        if(pq.size()>m){
            pq.pop();
        }
    }
    // int ans=false;
    
        int tp=-pq.top();
        if(tp+rem>a[v]+mid){
            return false;
        }
        return true;
    
    
}
signed main(){
  
  cin>>n>>m>>k;
  a.resize(n);int x;
  int sum=0;
  for(int i=0;i<n;i++){
    cin>>x;
    a[i]=x;
    sum+==x;
  }vector<int>ci;

  for(int i=0;i<n;i++){
    int remVotes=k-sum;
  int lo=0,hi=remVotes;
  int ans=-1;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    while(check(i,mid,remVotes-mid)){
        int ans=mid;
        int hi=mid-1;
    }
    else{
        lo=mid+1;
    }
  }
    ci.push_back(ans);
  }
  for(int i=0;i<n;i++)cout<<ci[i]<<" ";
  

  
  return 0;
}