#include<bits/stdc++.h>
using namespace std;
int n,q;
//10^5
int arr[200200];
int t[800800];
//4 times the array

//id- node of array
//l ,r responsiblity region

void build(int id,int l,int r){
    //base case
    if(l==r){
        t[id]=arr[l];
        return;
    }
    //make it in 2 parts
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    //merging the children
    t[id]=t[2*id]+t[2*id+1];
}
void update(int id,int l,int r,int pos,int val){
    if(pos<l||pos>r)return;
    if(l==r){
        t[id]=val;
        arr[pos]=val;
        return;
    }
    //make it in 2 parts
    int mid=(l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    //merging the children
    t[id]=t[2*id]+t[2*id+1];

}
int query(int id,int l,int r,int lq,int rq){
    //condition for no overlap
    if(lq>r||rq<l)return 0;
    if(lq>=l&&rq<=r)return t[id];
    int mid=(l+r)/2;
    int ans=query(2*id,l,mid,lq,rq);
    ans+=query(2*id+1,mid+1,r,lq,rq);
    
    return ans;;
}
int main(){
    //n elements
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //build
    build(1,0,n-1);
    //build node number 1 
    //that is responsible for region 0 to n-1

    //q queries
    cin>>q;
    while(q--){
        int ch;
        cin>>ch;
        if(ch=='+'){
            int pos,val;
            cin>>pos>>val;
            //update
            update(1,0,n-1,pos,val);
        }
        else if(ch=='?'){
            int l,r;
            cin>>l>>r;
            //query
            cout<<query(1,0,n-1,l,r)<<"\n";
        }
    }

    return 0;    
}