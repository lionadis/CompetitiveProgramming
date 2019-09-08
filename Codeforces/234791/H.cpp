#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 123;
int h, w, cc, found;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {0, 1, -1, 1, -1, 0, 1, -1};
string s[maxn];
bool vis[maxn][maxn];
vector<vector<pair<int, int> > > G;
struct edge{
	int x, y, dist
}E[maxn * maxn];

void dfs_cc(int x, int y){
	if(x < 0 || x >= h || y < 0 || y >= w) return;
	vis[x][y] = true;
	if(s[x][y] != 'X') return;
	found = 1;
	s[x][y] = (char)(cc+'0');
	rep(i,0,8) dfs_cc(x + dx[i], y + dy[i]);
}

void dfs_build(int startx, int start_y, int x, int y, int id){
	if(x < 0 || x >= h || y < 0 || y >= w) return;
	if(vis[x][y]) return;
	vis[x][y] = true;
	if(vis[x]

}


int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int t;
	cin >> t;
	while(t--){
		cc = 0;
		cin >> h >> w;
		rep(i,0,h) cin >> s[i];
		rep(i,0,h){
			rep(j,0,w){
				if(!vis[i][j]) found = 0, dfs_cc(i, j), cc+=found;
			}
		}
		G.clear();
		G.resize(cc);
		memset(vis, 0, sizeof vis);
		rep(i,0,h){
			rep(j,0,w) if(!vis[i][j] && s[i][j] != '-') dfs_build(i, j, i, j, s[i][j] - '0');
		}
		
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
