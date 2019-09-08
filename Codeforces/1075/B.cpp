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

const int maxn = 100123;
int a[2 * maxn], ans[maxn];
vector<ll> taxi, citizen;

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, m;
	cin >> n >> m;
	rep(i,0,n + m) cin >> a[i];
	rep(i,0,n + m){
		int x;
		cin >> x;
		if(x) taxi.push_back(a[i]);
		else citizen.push_back(a[i]);
	}
	taxi.push_back(1e18);
	int curr_taxi = 0;
	trav(x, citizen){
		while(curr_taxi < m && abs(x - taxi[curr_taxi]) > abs(x - taxi[curr_taxi + 1])) curr_taxi++;
		ans[curr_taxi]++;
	}
	rep(i,0,m) cout << ans[i] << " ";
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
