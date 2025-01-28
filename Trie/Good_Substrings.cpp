#include<bits/stdc++.h>
using namespace std;
#define int long long
// int n,mxlen,q;
string s,gb;
    int k;
struct node{
    int cnt_end,cnt_prefix;
    node *child[26];
    multiset<string>ms;
    node(){
        cnt_end=cnt_prefix=0;
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
        ms.clear();
    }
};
struct trie{
    node* root;
    trie(){
        root=new node();
    }
    void add(string s){
        node *cur=root;
        for(int i=0;i<s.length();i++){
            cur->cnt_prefix++;
            if(cur->child[s[i]-'a']==nullptr){
                cur->child[s[i]-'a']=new node();
            }
            cur=cur->child[s[i]-'a'];
            cur->ms.insert(s);
        }
        cur->cnt_end++;
    }
    int findPrefix(string s){
        node * curr=root;
        for(int i=0;i<s.length();i++){
            if(curr->child[s[i]-'a']==nullptr){
                return 0;
            }
            curr=curr->child[s[i]-'a'];
        }
        return curr->cnt_end+curr->cnt_prefix;
    }
};
trie tt;
int ts;
int dfs(node * curr,int x[]){
    int ans=0;
    
    for(int i=0;i<26;i++){
        if(curr->child[i]!=nullptr){
            // string temp=s;
            char x='a'+i;
            dfs(curr->child[i],s+x);
        }
    }
}
void printAutoSuggestions(string s,int totalSug){
    ts=totalSug;
    node * curr=tt.root;
    for(int i=0;i<s.length();i++){
        if(curr->child[s[i]-'a']==nullptr){
            return ;
        }
        curr=curr->child[s[i]-'a'];
    }
    auto it=curr->ms.begin();
    while(totalSug>0&&it!=curr->ms.end()){
        cout<<(*it)<<" ";
        totalSug--;
        it++;
    }
}
void solve(){
    
    cin>>s>>gb>>k;
    
    tt.add(s);
    int x[26]={0};
    
    dfs(tt.root,x);
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}