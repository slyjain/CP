#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int queen[20];//maximum rows possible is 20
//queen[i] stores on which column our queen 
//is present in ith row
bool check(int row,int col){
    for(int i=0;i<row;i++){
        //row colision is not possible because we have placed
        //only one queen in one row
        if(queen[i]==col||abs(col-queen[i])==abs(row-i)){
            return false;
        }
    }
    return true;
}
int rec(int row){
    //Meaning of recurance :
    //number of ways to populate queens from row to n-1
    // rows from the previous 0 to row -1 configuration

    //pruning

    //base case
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(queen[i]==j){
                    cout<<"Q";
                }
                else{
                    cout<<".";
                }
            }
            cout<<"\n";
        }
        cout<<"----------------\n";
        return 1;
        
    }
    //transition or compute
    int ans=0;
    //loop over all choices
    for(int col=0;col<n;col++){
        //check whether the choice is valid or not
        if(check(row,col)){
            //place the queen 
            queen[row]=col;
            // make the move
            ans+=rec(row+1);
            //revert the changes
            queen[row]=-1;
        }
    }
    return ans;

}
void solve(){
cin>>n;
memset(queen,-1,sizeof(queen));
cout<<rec(0)<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}