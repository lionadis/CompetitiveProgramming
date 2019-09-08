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

const int maxn = 300123;
int a[maxn], dp[2][maxn];
bool vis[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n;
	cin >> n;
	vector<pii> v;
	rep(i,0,n){
		int a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		v.push_back({a, b});
	}
	rep(i,0,n){
		bool can_a = true;
		rep(j,0,60) can_a &= !vis[a[i] + j];
		if(can_a) {
			rep(j,0,60) vis[a[i] + j] = true;

			continue;
		}

	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
