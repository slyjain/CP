#define SZ (int)1e5+100;
struct node{
    int mini,cnt;
    node(int mn=1e9,int c=0){
        mini=mn;
        cnt=c;
    }
};
node merge(node a,node b){
    if(a.mini==b.mini){
        return node(a.mini,a.cnt+b.cnt);
    }else if(a.mini<b.mini){
        return a;
    }else{
        return b;
    }
}
//dont forget to update the size of Array
int arr[100100];
node t[4*100100];

void build(int index,int l,int r){
    if(l==r){
        t[index]=arr[l];
        return ;
    }
    int mid=(l+r)/2;
    build(2*index,l,mid);
    build(2*index,mid+1,r);
    t[index]=merge(t[2*index],t[2*index+1]);
}
void update
