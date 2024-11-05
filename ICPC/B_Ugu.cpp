#include <bits/stdc++.h>
using namespace std;

int fn(string str) {
    int n = str.length();
    int pre = 0, ans = 0;
    
    for (int i = 1; i < n; i++) {
        if (str[i] != str[i - 1]) {
            if (pre == 0 && str[i] == '0') {
                pre = 1;
                ans++;
            } else if (pre == 1) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int ans = fn(str);
        cout << ans << endl;
    }
    return 0;
}