        #include<bits/stdc++.h>
        using namespace std;
        #define int long long
        vector<int>arr(2*100100),t(8*100100);
        void build(int id,int l,int r){
            if(l==r){
                t[id]=arr[l];
                
            }else{
            int mid =(l+r)/2;
            build(2*id,l,mid);
            build(2*id+1,mid+1,r);
            t[id]=t[2*id]+t[2*id+1];
            }
        }

        void update(int id,int l,int r,int pos,int val){
            if(pos<l||pos>r){
                return ;
            }
            if(l==r){
                t[id]=val;
                arr[pos]=val;
                return;
            }
            int mid=(l+r)/2;
            update(2*id,l,mid,pos,val);
            update(2*id+1,mid+1,r,pos,val);
            t[id]=t[2*id]+t[2*id+1];
        }

        int query(int id,int l,int r,int lq,int rq){
            if(lq>r||rq<l)return 0;
            if(lq<=l&&rq>=r)return t[id];
            int mid=(l+r)/2;
            int ans=query(2*id,l,mid,lq,rq);
            ans+=query(2*id+1,mid+1,r,lq,rq);
            return ans;
        }
        void solve(){
        int n,q;
        cin>>n>>q;
        // arr.resize(n+1);
        // t.resize(4*(n+1));
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        build(1,1,n);
        while(q--){
            int c;
            cin>>c;
            if(c==1){
                int pos,val;
                cin>>pos>>val;
                update(1,1,n,pos,val);
            }else if(c==2){
                int l,r;
                cin>>l>>r;
                cout<<query(1,1,n,l,r)<<"\n";
            }
        }
        }

        signed main(){
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            solve();
            return 0;
        }