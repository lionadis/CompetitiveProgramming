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

const int maxn = 412;
string s[maxn];
int h, w, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool vis[maxn][maxn];

void dfs(int x, int y, int &cnt_w, int &cnt_b){
	if(vis[x][y]) return;
	vis[x][y] = true;
	if(s[x][y] == '#') cnt_w ++;
	else cnt_b++;
	rep(i,0,4){
		int xx = x + dx[i], yy = y + dy[i];
		if(xx < h && xx >=0 && yy < w && yy >= 0 && s[x][y] != s[xx][yy]) dfs(xx, yy, cnt_w, cnt_b);
	}
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> h >> w;
	rep(i,0,h) cin >> s[i];
	ll ans = 0;
	rep(i,0,h){
		rep(j,0,w){
			if(!vis[i][j]){
				int cnt_w = 0, cnt_b = 0;
				dfs(i, j, cnt_w, cnt_b);
				ans += 1ll * cnt_w * cnt_b;
			}
		}
	}
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
