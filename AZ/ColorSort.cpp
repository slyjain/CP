
#include <bits/stdc++.h>
using namespace std;

void sort(int a[], int n)

{
    //add code here
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            cnt0++;
        }else if(a[i]==1){
            cnt1++;
        }else{
            cnt2++;
        }
    }
    int it=0;
    while(cnt0){
        a[it++]=0;
        cnt0--;
    }
    while(cnt1){
        a[it++]=0;
        cnt1--;
    }while(cnt2){
        a[it++]=0;
        cnt2--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, n);
    for (int i : a)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
