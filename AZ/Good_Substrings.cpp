#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;
struct node
{
    int cnt_pre, cnt_end;
    node *child[26];
    node()
    {
        cnt_end = cnt_pre = 0;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};
struct trie
{
    node *root;
    trie()
    {
        root = new node();
    }
    void insert(string s)
    {
        node *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            curr->cnt_pre++;
            if (curr->child[s[i] - 'a'] == nullptr)
            {
                curr->child[s[i] - 'a'] = new node();
            }
            curr = curr->child[s[i] - 'a'];
        }
        curr->cnt_end++;
    }
    int find(string s)
    {
        node *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (curr->child[s[i] - 'a'] == nullptr)
            {
                return 0;
            }
            curr = curr->child[s[i] - 'a'];
        }
        return curr->cnt_end + curr->cnt_pre;
    }
    int countExact(const string &s)
    {
        node *curr = root;
        for (char c : s)
        {
            if (curr->child[c - 'a'] == nullptr)
            {
                return 0;
            }
            curr = curr->child[c - 'a'];
        }
        return curr->cnt_end; // Return exact matches
    }

    // Count occurrences of words with a given prefix
    int countPrefix(const string &s)
    {
        node *curr = root;
        for (char c : s)
        {
            if (curr->child[c - 'a'] == nullptr)
            {
                return 0;
            }
            curr = curr->child[c - 'a'];
        }
        return curr->cnt_pre; // Return prefix occurrences
    }
};
map<int, int> mp;
set<string> st;
string p;
void dfs(node *curr, int misRem, string currSt)
{
    // int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (curr->child[i] != nullptr && (misRem - (1 - (int)(p[i] - '0')) >= 0))
        {
            dfs(curr->child[i], misRem - (1 - (int)(p[i] - '0')), currSt + ((char)('a' + i)));
        }
    }
    ans++;
    // st.insert(currSt);
}
void solve()
{
    string s;
    cin >> s;

    cin >> p;
    // for (int i = 0; i < 26; i++)
    // {
    //     mp[i] = p[i] - '0';
    // }
    int k;
    cin >> k;
    // int ans = 0;
    trie t;
    int al[26]{};
    for (int i = 0; i < s.length(); i++)
    {
        al[s[i] - 'a']++;
        t.insert(s.substr(i, s.length() - i));
    }
    st.clear();
    dfs(t.root, k, "");
    // cout <<st.size()-1;
    cout << ans - 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}