
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> TransitiveClosureGraph(vector<vector<int>> adj)
{
	// Complete the function
    int n=adj.size();
    vector<vector<int>>T(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            T[i][j]=adj[i][j];
        }
    }
    for(int i=0;i<n;i++){
        T[i][i]=1;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                T[i][j]|=(T[i][k]&T[k][j]);
            }
        }
    }
    return T;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> adj(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> adj[i][j];
			if (i == j)
			{
				adj[i][j] = 1;
			}
		}
	}

	vector<vector<int>> T = TransitiveClosureGraph(adj);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << T[i][j] << ' ';
		}
		cout << '\n';
	}
}
