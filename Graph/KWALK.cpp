

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
using state=pair<int,int>;
using ii=pair<state,int>;
// vector<vector<int>>g;
vector<vector<int>>dis;
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
vector<state> neigh(int x,int y,int n){
	vector<state>neighbors;
	for(int i=0;i<8;i++){
		int cx=x+dx[i];
		int cy=y+dy[i];
		if(cy>0&&cy<=n&&cx>0&&cx<=n){
			neighbors.push_back({cx,cy});
		}
	}
	return neighbors;
}
int KnightWalk(int n, int Sx, int Sy, int Fx, int Fy)
{	
	dis.assign(n+1,vector<int>(n+1,INF));
	queue<ii>q;
	dis[Sx][Sy]=0;
	q.push({{Sx,Sy},0});
	while(q.empty()==false){
		int xx=q.front().first.first;
		int yy=q.front().first.second;
		int d=q.front().second;
    //cout<<xx<<" "<<yy<<"\n";
		q.pop();
		for(auto v:neigh(xx,yy,n)){
			int nx=v.first;
			int ny=v.second;
			if(dis[nx][ny]==INF){
				q.push({{nx,ny},d+1});
				dis[nx][ny]=d+1;
			}
		}
	}
	return dis[Fx][Fy];
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
